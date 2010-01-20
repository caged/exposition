require '../lib/exposition'

str = File.read('../test/samples/TTPhotoViewController.h')

def pre_process(str)
  string = str.gsub(/\r\n/, "\n")
  string = string.split("\n").map do |line|
    line.gsub(/\s+$/, '')
  end.join("\n")
  "\n#{string}\n"
end

def test(str)
  parser = DocumentParser.new
  doc = parser.parse(pre_process(str))
  raise ParseError, parser unless doc
end

begin
  test(str)
rescue ParseError => e
  puts e.message
end