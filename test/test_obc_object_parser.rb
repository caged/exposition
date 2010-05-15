require 'helper'

context "Parsing Classes, Categories and Protocols in Header Files" do
  setup do
    @parser = ObjCObjectsParser.new
    @klass = parse_file('SampleClass')
  end
  
  test 'parses objc class' do
    cl = parse_file('SampleClass')
    assert_instance_of(ObjCObjects::ObjCClass, cl)
    
    assert_equal('SampleClass', cl.name)
    assert_equal('NSObject', cl.superclass)
    
    assert_not_nil(cl.properties)
    assert_not_nil(cl.class_methods)
    assert_not_nil(cl.instance_methods)
    
    doc_str = "This is some documentation for SampleClass."
    assert_equal(doc_str, cl.documentation.text[0, doc_str.length])
  end
  
  test 'parses protocols conforming to' do
    cl = parse_file('SampleClass')
    protocols = cl.conforms_to
    assert_equal(3, protocols.count)
    names = %w(EXSomeProtocol EXSomeOtherProtocol EXSomeDifferentProtocol)
    protocols.each do |pcall|
      assert(names.include?(pcall.name))
    end
  end
  
  test 'parses instance variables' do
    cl = parse_file('SampleClass')
    ivs = cl.instance_variables
    
    assert_equal(4, ivs.count)
    
    assert_equal('NSString', ivs[0].type)
    assert_equal('_someString', ivs[0].name)
    assert_equal(0, ivs[0].conforms_to.count)
    
    assert_equal('CGFloat', ivs[1].type)
    assert_equal('someFloat', ivs[1].name)
    assert_equal(0, ivs[1].conforms_to.count)
    
    assert_equal('id', ivs[2].type)
    assert_equal('fooBar', ivs[2].name)
    assert_equal(0, ivs[2].conforms_to.count)
    
    assert_equal('id', ivs[3].type)
    assert_equal('someConformingObject', ivs[3].name)
    assert_equal(3, ivs[3].conforms_to.count)
  end
  
  test 'parses categories' do
    cat = parse_file('GitActor+Parsing')
    assert_equal('GITActor', cat.name)
    assert_equal('Crazy Time', cat.category_name)
    assert_equal('GITActor_CrazyTime', cat.cleaned_name)
    
    assert_not_equal(0, cat.class_methods.count)
    assert_not_equal(0, cat.instance_methods.count)
  end
  
  test 'parses protocols' do
    pcall = parse_file('HRResponseDelegate')
    assert_equal('HRResponseDelegate', pcall.name)
    assert_equal('NSObject', pcall.conforms_to[0].name)
    
    assert_not_equal(0, pcall.instance_methods.count)
  end
end