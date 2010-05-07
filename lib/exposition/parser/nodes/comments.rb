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
    
    def summary
      str = ''
      str = lines.elements.select { |e| !e.is_a?(Keyword) }.collect do |line|
        line.text_value.gsub(/^(\s\*\s?)/, '')
      end.join if defined?(lines)
      str.sub(/^\n/, '')
    end
    
    def params
      lines.elements.select { |e| e.is_a?(Param) }
    end 
    
    def keywords
      lines.elements.select { |e| e.is_a?(Keyword) && !e.is_a?(Param)}
    end
    
    def lines
      defined?(doc_lines) ? doc_lines : Treetop::Runtime::SyntaxNode.new("", 0..0, [])
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
      str = lines.elements.collect do |line|
        line.text_value.gsub(/^(\s\*\s?)/, '')
      end.join("\n") unless lines.nil?
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