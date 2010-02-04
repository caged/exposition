require '../lib/exposition'


#str = File.read('../test/samples/TTPhotoViewController.h')

def prepare_content_for_parse(content)
  string = content.gsub(/\r\n/, "\n")
  string = string.split("\n").map do |line|
    line.gsub(/\s+$/, '')
  end.join("\n")
  "\n#{string}\n"
end


samples = *Dir['../test/samples/*.h']
#bwtoolkit = Dir['/Users/justin/dev/thirdparty/cocoa/bwtoolkit/*.h']
three20   = Dir['/Users/justin/dev/thirdparty/iphone/three20/src/Three20/*.h']

Exposition::Documentation.generate!(*samples)

# begin
#   parser = MethodsParser.new
#   content = "\n- (id)performSelector:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3 withObject:(id)p4;"
#   pp content
#   result = parser.parse(content)
#   unless result    
#     puts "\n" << parser.terminal_failures.join("\n") << "\n"
#     raise Exposition::ParseError, parser
#   else
#    pp result.elements
#   end
# rescue Exposition::ParseError => e
#   puts e.message
# end

# begin
#   parser = DocumentParser.new
#   result = parser.parse(File.read(three20.first))
#   unless result    
#     puts "\n" << parser.terminal_failures.join("\n") << "\n"
#     raise Exposition::ParseError, parser
#   else
#    puts result.methods.collect { |m| m.to_s }
#   end
# rescue Exposition::ParseError => e
#   puts e.message
# end