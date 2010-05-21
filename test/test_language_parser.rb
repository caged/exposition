require 'helper'

context "Parsing Language" do
  setup do
    @parser = DocumentParser.new
  end
  
  test 'parses defines with numbers & expressions' do
    d1 = parse("\n#define MYNumber 23.0")
    assert_instance_of(Language::Define, d1)
  end
end