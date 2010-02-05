module Methods      
  class Method < Treetop::Runtime::SyntaxNode
    def name
      matches = []
      to_s.sub(/(\-|\+)\(/, '- (').scan /\s(.+?)(:|;)/ do |match|
        matches << match[0].to_s.strip
      end
      "#{to_s[0..0]} #{matches.join(':')};"
    end
    
    def to_s
      text_value.strip
    end
    
    def arguments
      args = method_body.elements.select { |e| e.is_a?(Arguments) }.first
      args.nil? ? [] : args
    end
  end
  
  class ClassMethod < Method
    
  end
  
  class InstanceMethod < Method
    
  end
  
  class Arguments < Treetop::Runtime::SyntaxNode
    include Enumerable
    
    def each
      elements.each { |e| yield e }
    end
  end
  
  class Argument < Treetop::Runtime::SyntaxNode 
    include Language       
    def name
      arg_name.text_value.strip
    end
    
    def type
      arg_type.text_value.strip
    end
    
    def conforms_to
      pcalls = arg_type.type_or_protocol.elements.select do |e| 
        e.is_a?(Protocols)
      end
      pcalls.any? ? pcalls.first : []
    end
  end
end