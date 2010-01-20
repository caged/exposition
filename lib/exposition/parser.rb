dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH << dir

require 'parser/nodes'
require 'parser/grammars'

class ParseError < StandardError
  def initialize(parser)
    @parser = parser
    @lines = @parser.input.split("\n").unshift("")
  end
  
  def message    
    <<-EOS
      ParseError: Expected #{expected_string} at line #{line}, column #{column} (byte #{index + 1}) after #{@parser.input[@parser.index...index].inspect}.
      
      #{source_code}
    EOS
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