require 'helper'

context "Parsing Methods Declared in Header Files" do
  setup do
    @parser = MethodsParser.new
  end
  
  test 'parses methods without arguments' do
    m1 = parse("\n- (TTPhotoView*)createPhotoView;")
    m2 = parse("\n-(TTPhotoView *) createPhotoView;")
    
    assert_equal("- (TTPhotoView*)createPhotoView", m1.name)
    assert_equal("- (TTPhotoView *)createPhotoView", m2.name)
  end
  
  test 'parses methods with arguments' do
    m1 = parse("\n- (id)performSelector:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3;")
    assert_equal("- (id)performSelector:withObject:withObject:withObject:", m1.name)
  end
  
  test 'parses methods with protocols in keyed arguments' do
    m1 = parse("\n- (void)didMoveToPhoto:(id<TTPhoto>)photo fromPhoto:(id<TTPhoto>)fromPhoto;")
    m2 = parse("\n- (void)didMoveToPhoto:(id<TTPhoto, AnotherProtocol, SomethingElse>)photo fromPhoto:(id<TTPhoto>)fromPhoto;")
    
    assert_equal("- (void)didMoveToPhoto:fromPhoto:", m1.name)
    assert_equal("- (void)didMoveToPhoto:fromPhoto:", m2.name)
    
    assert_equal('TTPhoto', m1.arguments.first.type.conforms_to.first.name)
    assert_equal(['TTPhoto', 'AnotherProtocol', 'SomethingElse'], m2.arguments.first.type.conforms_to.collect { |pc| pc.name })
  end
  
  test 'parses methods broken into seperate lines' do
    m1 = parse("\n- (void)didMoveToPhoto:(id<TTPhoto, AnotherProtocol, SomethingElse>)photo 
                      fromPhoto:(id<TTPhoto>)fromPhoto;")
    assert_equal("- (void)didMoveToPhoto:(id<TTPhoto, AnotherProtocol, SomethingElse>)photo fromPhoto:(id<TTPhoto>)fromPhoto;", m1.to_s)
    assert_equal("- (void)didMoveToPhoto:fromPhoto:", m1.name)
  end
  
  test 'parses methods with variable number of arguments' do
    m1 = parse("\n- (void) appendObjects:(id) firstObject,...;")
    
    assert(m1.arguments.variable?)
    assert_equal(['firstObject', '...'], m1.arguments.collect {|a| a.name})
    assert_equal(m1.arguments.first.type, m1.arguments.last.type)
    assert_equal("- (void)appendObjects:", m1.name)
  end
end