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
  end
  
  class ClassMethod < Method
    
  end
  
  class InstanceMethod < Method
    
  end
end