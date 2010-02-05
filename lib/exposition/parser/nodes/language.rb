module Language
  class Protocols < Treetop::Runtime::SyntaxNode
    include Enumerable
    def each
      type_names.elements.each { |e| yield e }
    end
    
    def zomg
      puts "zOMG"
    end
  end
  
  class Protocol < Treetop::Runtime::SyntaxNode
    def name
      text_value
    end
  end
end