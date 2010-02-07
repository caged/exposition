require 'helper'

context "Parsing Properties Declared in Header Files" do
  setup do
    @parser = PropertiesParser.new
  end
  
  test 'parses basic properties' do
    prop = parse("\n@property (nonatomic, retain) NSString *someString;")
    prop2 = parse("\n@property (nonatomic, retain) NSString * someString;")
    prop3 = parse("\n@property (nonatomic, retain) NSString* someString;")
    
    assert_equal("someString", prop.name)
    assert_equal("someString", prop2.name)
    assert_equal("someString", prop3.name)
    
    assert_equal("someString", prop.getter)
    assert_equal("someString", prop2.getter)
    assert_equal("someString", prop3.getter)
    
    assert_equal("someString=", prop.setter)
    assert_equal("someString=", prop2.setter)
    assert_equal("someString=", prop3.setter)
    
    assert_equal("NSString", prop.type)
    assert_equal("NSString", prop2.type)
    assert_equal("NSString", prop3.type)
    
    assert_equal(['nonatomic', 'retain'], prop.attributes)   
  end
  
  test 'parses core foundation properties' do
    prop = parse("\n@property (nonatomic, assign) CGFloat someFloat;")
    prop2 = parse("\n@property CGFloat someFloat;")    
    
    assert_equal('CGFloat', prop.type)
    assert_equal('someFloat', prop.name)
    assert_equal('someFloat', prop.getter)
    assert_equal('someFloat=', prop.setter)
    assert_equal(['nonatomic', 'assign'], prop.attributes)
    
    assert_equal('CGFloat', prop2.type)
    assert_equal('someFloat', prop2.name)
    assert_equal('someFloat', prop2.getter)
    assert_equal('someFloat=', prop2.setter)
    assert(prop2.attributes.empty?)
  end
  
  test 'parses properties without attributes' do
    prop = parse("\n@property EXSomeClass *someClass;")
    prop2 = parse("\n@property NSInteger someInt;")
    
    assert_equal('EXSomeClass', prop.type)
    assert_equal('someClass', prop.name)
    assert_equal('someClass', prop.getter)
    assert_equal('someClass=', prop.setter)
    assert(prop2.attributes.empty?)
    
    assert_equal('NSInteger', prop2.type)
    assert_equal('someInt', prop2.name)
    assert_equal('someInt', prop2.getter)
    assert_equal('someInt=', prop2.setter)
    assert(prop2.attributes.empty?)
  end
  
  test 'parses custom getters and setters' do
    prop = parse("\n@property (nonatomic, assign, getter=isSomethingTrue, setter=comfirmSomethingIsTrue) BOOL somethingTrue;")
    
    assert_equal('somethingTrue', prop.name)
    assert_equal('isSomethingTrue', prop.getter)
    assert_equal('comfirmSomethingIsTrue=', prop.setter)
  end
  
  test 'parses iboutlet properties' do
    prop = parse("\n@property (nonatomic, retain) IBOutlet NSButton *someButton;")
    
    assert_equal('NSButton', prop.type)
    assert(prop.ib_outlet?)
    assert_equal('someButton', prop.name)
  end
  
  test 'parses modifiers' do
    prop1 = parse("\n@property(retain) __attribute__((NSObject)) CFDictionaryRef myDictionary;")
    prop2 = parse("\n@property (nonatomic, retain) __weak Link *parent;")
    prop3 = parse("\n@property (nonatomic, retain) __strong Link *parent;")
    
    assert_equal('myDictionary', prop1.name)
    assert_equal('parent', prop2.name)
    assert_equal('parent', prop3.name)
    
    assert_equal('CFDictionaryRef', prop1.type)
    assert_equal('Link', prop2.type)
    assert_equal('Link', prop3.type)
    
    assert_equal(['retain'], prop1.attributes) 
    assert_equal(['nonatomic', 'retain'], prop2.attributes)   
    assert_equal(['nonatomic', 'retain'], prop3.attributes)   
  end
  
  test 'parses documented properties' do
    prop1 = parse("\n/**\n * The source of a sequential photo collection that will be displayed.\n */\n@property(nonatomic,retain) id<TTPhotoSource> photoSource;")
    assert_equal('photoSource', prop1.name)
    assert_instance_of(Comments::BlockComment, prop1.documentation)
    assert_equal(prop1.documentation.to_s, "/**\n * The source of a sequential photo collection that will be displayed.\n */")
  end
end