module Document  
  class Doc < Treetop::Runtime::SyntaxNode
    include Enumerable
    include ObjCObjects
    include Comments
    
    def each
      elements.each { |e| yield e }
    end
    
    def file_comment
      detect { |e| e.is_a?(InlineComment)}
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