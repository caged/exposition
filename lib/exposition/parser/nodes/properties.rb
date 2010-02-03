module Properties
  class Base < Treetop::Runtime::SyntaxNode; end
  class Property < Base
    def attributes
      attrs.text_value.gsub(/(\(|\)|\s*)/, '').split(',')
    end
    
    def name
      prop_name.text_value.strip
    end
    
    def type
      property_type.type.text_value.strip
    end
    
    def getter
      value = attributes.detect { |att| att =~ /^getter=/i }
      value.nil? ? name : value.split('=').last.strip
    end
    
    def setter
      value = attributes.detect { |att| att =~ /^setter=/i }
      value.nil? ? "#{name}=" : "#{value.split('=').last.strip}="
    end
    
    def ib_outlet?
      property_type.text_value.include?('IBOutlet')
    end
  end
end