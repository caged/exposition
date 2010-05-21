require 'helper'

context "Parsing Methods Declared in Header Files" do
  setup do
    @parser = MethodsParser.new
  end
  
  test 'parses methods without arguments' do
    m1 = parse("\n- (TTPhotoView*)createPhotoView;")
    m2 = parse("\n-(TTPhotoView *) createPhotoView;")
    
    assert_equal("- createPhotoView", m1.name)
    assert_equal("- createPhotoView", m2.name)
  end
  
  test 'parses methods with arguments' do
    m1 = parse("\n- (id)performSelector:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3;")
    assert_equal("- performSelector:withObject:withObject:withObject:", m1.name)
  end
  
  test 'parses methods with protocols in keyed arguments' do
    m1 = parse("\n- (void)didMoveToPhoto:(id<TTPhoto>)photo fromPhoto:(id<TTPhoto>)fromPhoto;")
    m2 = parse("\n- (void)didMoveToPhoto:(id<TTPhoto, AnotherProtocol, SomethingElse>)photo fromPhoto:(id<TTPhoto>)fromPhoto;")
    
    assert_equal("- didMoveToPhoto:fromPhoto:", m1.name)
    assert_equal("- didMoveToPhoto:fromPhoto:", m2.name)
    
    assert_equal('TTPhoto', m1.arguments.first.type.conforms_to.first.name)
    assert_equal(['TTPhoto', 'AnotherProtocol', 'SomethingElse'], m2.arguments.first.type.conforms_to.collect { |pc| pc.name })
  end
  
  test 'parses methods broken into seperate lines' do
    m1 = parse("\n- (void)didMoveToPhoto:(id<TTPhoto, AnotherProtocol, SomethingElse>)photo 
                      fromPhoto:(id<TTPhoto>)fromPhoto;")
    assert_equal("- (void)didMoveToPhoto:(id<TTPhoto, AnotherProtocol, SomethingElse>)photo fromPhoto:(id<TTPhoto>)fromPhoto;", m1.to_s)
    assert_equal("- didMoveToPhoto:fromPhoto:", m1.name)
  end
  
  test 'parses methods with crazy spacing' do
    m1 = parse("\n-(BOOL)shortcutValidator:(id)arg1 isKeyCode:(short) arg2 andFlagsTaken:(unsigned int) arg3 reason: (id *)arg4;")
    assert_equal("- shortcutValidator:isKeyCode:andFlagsTaken:reason:", m1.name)

    args = m1.arguments
    assert_equal(4, args.count)
    assert_equal('id', args.first.type.name)
    assert_equal('arg1', args.first.name)
    assert_equal('short', args[1].type.name)
    assert_equal('arg2', args[1].name)
    assert_equal('unsigned int', args[2].type.name)
    assert_equal('arg3', args[2].name)
  end
  
  test 'parses methods with variable number of arguments' do
    m1 = parse("\n- (void) appendObjects:(id) firstObject,...;")
    
    assert(m1.arguments.variable?)
    assert_equal(['firstObject', '...'], m1.arguments.collect {|a| a.name})
    assert_equal(m1.arguments.first.type, m1.arguments.last.type)
    assert_equal("- appendObjects:", m1.name)
  end
end