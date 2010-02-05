module Language
  class Protocols < Treetop::Runtime::SyntaxNode
    include Enumerable
    def each
      type_names.elements.each { |e| yield e }
    end
  end
  
  class Protocol < Treetop::Runtime::SyntaxNode
    def name
      type_name.text_value.strip
    end
  end
end