require 'helper'

context "Parsing Properties Declared in Header Files" do
  setup do
    @parser = PropertiesParser.new
  end
  
  test 'parses basic properties' do
    prop1 = parse("\n@property (nonatomic, retain) <Bob> CGFloat width;")
    assert_equal("width", prop1.name)    
  end
end