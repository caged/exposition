require 'helper'

context "Parsing Properties Declared in Header Files" do
  setup do
    @parser = PropertiesParser.new
  end
  
  test 'parses basic properties' do
    prop = parse("\n@property (nonatomic, retain) NSString *someString;")
    assert_equal("someString", prop.name)
    assert_equal(['nonatomic', 'retain'], prop.attributes)    
  end
  
  test 'parses core foundation properties' do
    prop = parse("\n@property (nonatomic, assign) CGFloat someFloat;")
    prop2 = parse("\n@property NSInteger someInt;")
    
    assert_equal('CGFloat', prop.type)
  end
end