require 'helper'

context "Parsing Properties Declared in Header Files" do
  setup do
    @parser = PropertiesParser.new
  end
  
  test 'parses basic properties' do
    assert_equal("\n@property CGFloat width;", @parser.parse("\n@property CGFloat width;").text_value)
  end
end