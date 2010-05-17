require 'helper'

context "Parsing Comments" do
  setup do
    @parser = DocumentParser.new
    path = File.expand_path(File.join(File.dirname(__FILE__), "samples", 'Cruz.h'))
    content = File.read(path)
    
    file = prepare_content_for_parse(File.read(path))
    doc = parse(file)
    
    sf = Exposition::SourceFile.new
    sf.location = path
    sf.info = doc
    sf.source = content
    Exposition::SymbolMapper.docs << sf
  end
  
  test 'should find objects' do
    pcall = Exposition::SymbolMapper.find(:objc_protocol, 'TODBrowserPlugInController')
    assert_instance_of(ObjCObjects::ObjCProtocol, pcall)
    
    klass = Exposition::SymbolMapper.find(:objc_class, 'PSMProgressIndicator')
    assert_instance_of(ObjCObjects::ObjCClass, klass)
    
    cat = Exposition::SymbolMapper.find(:objc_category, 'NSToolbar')
    assert_instance_of(ObjCObjects::ObjCCategory, cat)
  end
end