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
    include Enumerable
    
    def each
      lines.elements.each { |e| yield e }
    end
    
    def to_s
      str = ''
      str = select { |e| !e.is_a?(Keyword) }.collect do |line|
        line.text_value.gsub(/^(\s\*\s?)/, '')
      end.join("\n") unless lines.nil?
      str
    end
    
    def keywords
      select { |e| e.is_a?(Keyword) }
    end
  end
  
  class Keyword < Treetop::Runtime::SyntaxNode
    def name
      keyword_start.attribute_name.text_value.strip
    end
    
    def body
      str = ''
      str = keyword_lines.elements.collect do |line|
        puts "LINE:#{line.text_value}"
        line.text_value.gsub(/^(\s\*\s?)/, '')
      end.join("\n") unless keyword_lines.nil?
      str
    end
  end
end