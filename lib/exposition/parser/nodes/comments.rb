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
  end
end