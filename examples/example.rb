require '../lib/exposition'

str = File.read('../test/samples/TTPhotoViewController.h')

# def pre_process(str)
#   string = str.gsub(/\r\n/, "\n")
#   string = string.split("\n").map do |line|
#     line.gsub(/\s+$/, '')
#   end.join("\n")
#   string = ("\n" << string) unless string =~ /\n^/
#   string
# end
# 
# def parse_doc(str)
#   parser = DocumentParser.new
#   doc = parser.parse(pre_process(str))
#   raise ParseError, parser unless doc
#   doc
# end

begin
  samples = Dir['../test/samples/*.h'].collect { |f| File.expand_path(f) }  
  parser = Exposition::Parser.new(*samples)
  docs = parser.parse
  docs.each do |doc|
    puts doc.name
    pp doc.parse_tree.properties.collect { |p| p.text_value }
  end
rescue Exposition::ParseError => e
  puts e.message
end