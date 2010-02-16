module Document  
  class Doc < Treetop::Runtime::SyntaxNode
    include Enumerable
    include ObjCClasses
    
    def each
      elements.each { |e| yield e }
    end
    
    def objc_classes
      select { |e| e.is_a?(ObjCClass) }
    end
    
    def objc_categories
      select { |e| e.is_a?(ObjCCategory) }
    end
    
    def objc_protocols
      select { |e| e.is_a?(ObjCProtocol) }
    end
    
    def objc_objects
      objc_classes + objc_categories + objc_protocols
    end
  end
end