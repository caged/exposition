require '../lib/exposition'

str = File.read('../test/samples/TTPhotoViewController.h')

def pre_process(str)
  string = str.gsub(/\r\n/, "\n")
  string = string.split("\n").map do |line|
    line.gsub(/\s+$/, '')
  end.join("\n")
  string = ("\n" << string) unless string =~ /\n^/
  string
end

def parse_doc(str)
  parser = DocumentParser.new
  doc = parser.parse(pre_process(str))
  raise ParseError, parser unless doc
  doc
end

begin
  doc = parse_doc(str)
  pp doc.properties.collect { |p| p.text_value.to_s }
rescue ParseError => e
  puts e.message
end