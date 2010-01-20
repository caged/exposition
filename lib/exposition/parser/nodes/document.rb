module Document
  class General < Treetop::Runtime::SyntaxNode; end
  class Doc < Treetop::Runtime::SyntaxNode
    
  end
  class Text          < General; end
  class CommentStart  < General; end
  class CommentEnd    < General; end
  class LineBreak     < General; end
  class Space         < General; end
  class Char          < General; end
  class Line          < General; end
  class BlankLine < General
    def to_s
      ""
    end
  end

  class TextLine < General
    def to_s
      text.text_value
    end
  end

end