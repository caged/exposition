module Comments
  class Comment < Treetop::Runtime::SyntaxNode
    include SourceFile
    
    def to_s
      text_value.strip
    end
  end
  
  class InlineComment < Comment
    def summary
      text_value
    end
  end
  
  class BlockComment < Comment
    include Enumerable
    
    def each
      lines.elements.each { |e| yield e }
    end
    
    def summary
      str = ''
      str = select { |e| !e.is_a?(Keyword) }.collect do |line|
        line.text_value.gsub(/^(\s\*\s?)/, '')
      end.join if defined?(lines)
      str
    end
    
    def params
      select { |e| e.is_a?(Param) }
    end 
    
    def keywords
      select { |e| e.is_a?(Keyword)}
    end
  end
  
  class MethodComment < BlockComment
    
  end
  
  class Keyword < Treetop::Runtime::SyntaxNode
    def name
      keyword_start.attribute_name.text_value.strip
    end
    
    def body
      str = ''
      str = keyword_lines.elements.collect do |line|
        line.text_value.gsub(/^(\s\*\s?)/, '')
      end.join("\n") unless keyword_lines.nil?
      str
    end
  end
  
  class Param < Keyword
    attr_accessor :argument
    def name
      param_start.attribute_name.text_value.strip
    end
    
    def arg_index
      name.to_i - 1
    end
  end
end