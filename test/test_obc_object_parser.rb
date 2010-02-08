require 'helper'

context "Parsing Classes and Categories in Header Files" do
  setup do
    @parser = ObjCClassesParser.new
  end
  
  test 'parses objc class' do
    c1 = parse_file("SampleClass")
    assert_instance_of(ObjCClasses::ObjCClass, c1)
    
    assert_equal('SampleClass', c1.name)
    assert_equal('NSObject', c1.superclass)
    
    assert_not_nil(c1.properties)
    assert_not_nil(c1.class_methods)
    assert_not_nil(c1.instance_methods)
    
    assert_instance_of(Comments::BlockComment, c1.documentation)
  end
end