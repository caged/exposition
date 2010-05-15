require 'helper'

context "Parsing Comments" do
  setup do
    @parser = CommentsParser.new
  end
  
  test 'parses single line inlin comments' do
    ic = parse("\n// This is a comment\n")
    assert_instance_of(Comments::InlineComment, ic.elements.first)
  end
  
  test 'parses single line block comment' do
    flunk("Haven't got this working")
    # bc = parse("\n/** commenthere */\n")
    # assert_instance_of(Comments::BlockComment, bc)
  end
  
  
  test 'Should parse comment body' do
    bc = parse_file('comment').elements.first
    assert_equal("correct GITObject subtype will be called to create the correct representation and return the new object.", bc.text.split("\n").last)
  end
  
  test 'Should parse integer indexed params' do
    bc = parse_file('comment').elements.first
    assert_equal(5, bc.params.count)
    
    assert_instance_of(Comments::Param, bc.params.last)
    assert_equal(4, bc.params.last.arg_index)
    assert_equal('NSError describing the error which occurred', bc.params.last.body)
  end
  
  test 'Should parse keyword params' do
    bc = parse_file('comment').elements.first
    assert_equal(2, bc.keywords.count)
    
    assert_equal('task', bc.keywords.last.name)
    assert_equal('Initialisers', bc.keywords.last.body)
  end
end