module Language
  class ObjectType < Treetop::Runtime::SyntaxNode
    def name
      type_or_protocol.type_name.text_value
    end
        
    def conforms_to
      pcalls = type_or_protocol.elements.select do |e| 
        e.is_a?(Protocols)
      end
      pcalls.any? ? pcalls.first : []
    end
  end
  
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