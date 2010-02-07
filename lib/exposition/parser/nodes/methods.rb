module Methods      
  class Method < Treetop::Runtime::SyntaxNode
    def name
      if arguments.variable?
        mbody = "#{arguments.first.arg_body.text_value.strip}"
      else
        mbody = arguments.collect do |arg| 
          arg.arg_body.text_value.to_s
        end.join(':')
      end
      
      if mbody.empty?
        mbody = method_body.method_args.text_value 
      else
        mbody << ':'
      end
      
      mtype = is_a?(ClassMethod) ? '+' : '-'
      "#{mtype} #{method_body.return_type.text_value.strip}#{mbody}"
    end
    
    def arguments
      args = method_body.elements.select { |e| e.is_a?(Arguments) }.first
      args.nil? ? Arguments.new(nil, nil, []) : args
    end
    
    def return_type
      method_body.return_type
    end
    
    def documentation
      docs.to_s
    end
    
    def to_s
      text_value.strip.gsub(/\s+/, ' ')
    end
  end
  
  class ClassMethod < Method
    
  end
  
  class InstanceMethod < Method
    
  end
  
  class Arguments < Treetop::Runtime::SyntaxNode
    include Enumerable
    
    def each
      elements.select { |e| e.is_a?(Argument) || e.is_a?(VariableArgument) }.each { |e| yield e }
    end
    
    def [](idx)
      entries[idx]
    end
    
    def last
      entries.last
    end
    
    def variable?
      any? { |e| e.is_a?(VariableArgument) }
    end
  end
  
  class Argument < Treetop::Runtime::SyntaxNode 
    include Language       
    def name
      arg_name.text_value.strip
    end
    
    def type
      arg_type
    end
    
    def variable?
      is_a?(VariableArgument)
    end
  end
  
  class VariableArgument < Argument
    def name
      text_value
    end
    
    def type
      parent.first.type
    end
    
    def arg_body
      nil
    end
  end
end