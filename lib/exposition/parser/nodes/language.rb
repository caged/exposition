module Language
  # Any node that could have a parsable block comment directly
  # above it.  The PEG rule must always begin with docs:block_comment.
  class Documentable < Treetop::Runtime::SyntaxNode
    def self.symbol
      raise NotImplementedError, "Implement this in a subclass"
    end
    
    def name
      raise NotImplementedError, "Implement this in a subclass"
    end
        
    def documentation
      docs.to_s
    end
    
    def ref
      "#//apple_ref/occ/#{self.class.symbol}/#{name}"
    end
  end
  
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