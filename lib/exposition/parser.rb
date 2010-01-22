dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH << dir

require 'parser/nodes'
require 'parser/grammars'

module Exposition
  class SourceFile < Struct.new(:name, :location, :source, :parse_tree)
    def name
      File.basename(location)
    end
  end
  
  class Parser
    def initialize(*source_files)
      @options = source_files.last.is_a?(Hash) ? source_files.pop : {}
      @source_files = source_files
      @parser = DocumentParser.new
      @parsed_docs = []
      @percent_complete = 0
      @complete = false
    end
    
    def parse
      @complete = false
      @source_files.each do |file|
        content = File.read(file)
        prepared_content = prepare_content_for_parse(content)
        doc = @parser.parse(prepared_content)
        raise ParseError, @parser unless doc
        
        sf = SourceFile.new
        sf.location = file
        sf.parse_tree = doc
        sf.source = content
        @parsed_docs << sf
      end
      @complete = true
      @parsed_docs
    end
    
    def completed?
      @complete
    end
    
    def prepare_content_for_parse(content)
      string = content.gsub(/\r\n/, "\n")
      string = string.split("\n").map do |line|
        line.gsub(/\s+$/, '')
      end.join("\n")
      string = ("\n" << string) unless string =~ /\n^/
      string
    end
  end
  
  
  class ParseError < StandardError
    def initialize(parser)
      @parser = parser
      @lines = @parser.input.split("\n").unshift("")
    end
  
    def message    
      <<-EOS
        ParseError: Expected #{expected_string} at line #{line}, column #{column} (byte #{index + 1}) after #{@parser.input[@parser.index...index].inspect}.

  #{source_highlight}
      EOS
    end
  
    def source_highlight
      lines = source_code.split("\n")
      lines = lines.collect do |l|
        if l =~ /^\-+>/
          chars = l.chars.to_a
          clean_string = l.gsub(/^\-+>\s*[0-9]+\s*/, '')
          actual_column = (l.length - clean_string.length) + column
        
          char = clean_string.chars.to_a[column]
          if char == ' ' || char == nil
            char = on_red(' ')
          else
            char = bold(red(underline(char)))
          end
          chars[actual_column] = char
          l = chars.join
        end
        l
      end
      lines.join("\n")
    end
  
    def line
      @parser.failure_line
    end
  
    def column
      @parser.failure_column
    end
  
    def failures
      @parser.terminal_failures
    end
  
    def index
      @parser.failure_index
    end
  
    def source_code
      ((line-2)..(line+2)).map do |index|
        result = index == line ? "-->" : "   "
        "#{result} #{index.to_s.rjust(5)} #{@lines[index]}"
      end.join("\n")
    end
  
    def failure_reason
      ""
    end
  
    def expected_string
      if failures.size == 1
        failures.first.expected_string.inspect
      else
        expected = failures.map { |f| f.expected_string.inspect }.uniq
        last = expected.pop
        "one of #{expected.join(', ')} or #{last}"
      end
    end
  end
end