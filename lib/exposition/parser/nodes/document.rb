module Document  
  class Doc < Treetop::Runtime::SyntaxNode
    include Enumerable
    include Properties
    include Methods
    
    def each
      elements.each { |e| yield e }
    end
    
    def properties
      select { |e| e.is_a?(Property) }
    end
    
    def methods
      instance_methods + class_methods
    end
    
    def instance_methods
      select { |e| e.is_a?(InstanceMethod) }
    end
    
    def class_methods
      select { |e| e.is_a?(ClassMethod) }
    end
  end
end