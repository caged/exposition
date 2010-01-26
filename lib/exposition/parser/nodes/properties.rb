module Properties
  class Base < Treetop::Runtime::SyntaxNode; end
  class Property < Base
    def attributes
      attrs.text_value.gsub(/(\(|\)|\s*)/, '').split(',')
    end
    
    def name
      prop_name.text_value.strip
    end
  end
end