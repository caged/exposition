module Comments
  class Comment < Treetop::Runtime::SyntaxNode
    include SourceFile
    
    def to_s
      text_value.strip
    end
  end
  
  class InlineComment < Comment
    
  end
  
  class BlockComment < Comment
    def to_s
      str = ''
      str = lines.elements.collect do |line|
        line.text_value.gsub(/\s*[\*^]/, '')
      end.join("\n") unless lines.nil?
      str
    end
    
    def keywords
      lines.elements.select { |e| e.is_a?(Keyword) }
    end
  end
  
  class Keyword < Treetop::Runtime::SyntaxNode
    def name
      keyword_start.attribute_name.text_value.strip
    end
    
    def body
      str = ''
      str = keyword_lines.elements.collect do |line|
        puts line.class
        line.text_value.gsub(/\s*[\*^]/, '')
      end.join("\n") unless keyword_lines.nil?
      str
    end
  end
end