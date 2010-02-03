require '../lib/exposition'


#str = File.read('../test/samples/TTPhotoViewController.h')

def prepare_content_for_parse(content)
  string = content.gsub(/\r\n/, "\n")
  string = string.split("\n").map do |line|
    line.gsub(/\s+$/, '')
  end.join("\n")
  "\n#{string}\n"
end

# begin
#   parser = PropertiesParser.new
#   str = "\n@property (nonatomic, assign, getter=isSomethingTrue, setter=comfirmSomethingIsTrue) BOOL somethingTrue;"
#   str = "\n@property NSInteger someInt;"
#   str = "\n@property EXSomeClass *someClass;"
#   result = parser.parse(str)
#   unless result    
#     puts "\n" << parser.terminal_failures.join("\n") << "\n"
#   else
#    pp result.type
#   end
# rescue ParseError => e
#   puts e.message
# end

begin
  parser = MethodsParser.new
  str = "\n- (TTPhotoView*)createPhotoView;"
  result = parser.parse(str)
  unless result    
    puts "\n" << parser.terminal_failures.join("\n") << "\n"
    raise Exposition::ParseError, parser
  else
   pp result
  end
rescue Exposition::ParseError => e
  puts e.message
end