module Document  
  class Doc < Treetop::Runtime::SyntaxNode
    include Enumerable
    include Properties
    
    def properties
      elements.select { |e| e.is_a?(Property) }
    end
  end
end