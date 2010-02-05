module Methods      
  class Method < Treetop::Runtime::SyntaxNode
    def name
      mbody = arguments.collect { |a| a.type_name.text_value.to_s }.join(':')
      mbody = method_body.method_args.text_value if mbody.empty?
      mtype = is_a?(ClassMethod) ? '+' : '-'
      "#{mtype} #{method_body.return_type.text_value.strip}#{mbody};"
    end
    
    def arguments
      args = method_body.elements.select { |e| e.is_a?(Arguments) }.first
      args.nil? ? [] : args
    end
    
    def return_type
      method_body.return_type
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
      elements.each { |e| yield e }
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
  end
end