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
  end
end