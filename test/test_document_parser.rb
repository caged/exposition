require 'helper'

context "Parsing Comments and Objects in Documents" do
  setup do
    @parser = DocumentParser.new
  end
  
  test 'parses file comment' do
    doc = parse_file('GitObject')
    assert_instance_of(Comments::InlineComment, doc.file_comment)
    
    assert_equal(' GITObject.h', doc.file_comment.lines[2])
  end
  
  test 'parses multiple objects in same file' do
    doc = parse_file('GitObject')
    assert_not_equal(0, doc.objc_protocols.count)
    assert_not_equal(0, doc.objc_classes.count)
  end
  
  test 'parses object documentation for multiple objects in same document' do
    doc = parse_file('GitObject')
    assert_not_nil(doc.objc_protocols.first.documentation)
    assert_not_nil(doc.objc_classes.first.documentation)
  end
end