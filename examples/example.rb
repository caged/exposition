require '../lib/exposition'


#str = File.read('../test/samples/TTPhotoViewController.h')

def prepare_content_for_parse(content)
  string = content.gsub(/\r\n/, "\n")
  string = string.split("\n").map do |line|
    line.gsub(/\s+$/, '')
  end.join("\n")
  "\n#{string}\n"
end
# 
# def parse_doc(str)
#   parser = DocumentParser.new
#   doc = parser.parse(pre_process(str))
#   raise ParseError, parser unless doc
#   doc
# end

begin
  # samples = Dir['../test/samples/*.h'].collect { |f| File.expand_path(f) }  
  # parser = Exposition::Parser.new(*samples)
  # docs = parser.parse
  # docs.each do |doc|
  #   puts doc.name
  #   pp doc.parse_tree.properties.collect { |p| p.attributes }
  # end
  parser = PropertiesParser.new
  str = "\n@property (nonatomic, assign, getter=isSomethingTrue, setter=comfirmSomethingIsTrue) BOOL somethingTrue;"
  str = "\n@property NSInteger someInt;"
  str = "\n@property EXSomeClass *someClass;"
  result = parser.parse(str)
  unless result    
    puts "\n" << parser.terminal_failures.join("\n") << "\n"
  else
   pp result.type
  end
rescue ParseError => e
  puts e.message
end