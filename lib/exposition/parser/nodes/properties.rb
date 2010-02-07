module Properties
  class Base < Treetop::Runtime::SyntaxNode; end
  class Property < Base
    def attributes
      prop.attrs.text_value.gsub(/(\(|\)|\s*)/, '').split(',')
    end
    
    def name
      prop.prop_name.text_value.strip
    end
    
    def type
      prop.property_type.type_name.text_value.strip
    end
    
    def documentation
      docs
    end
    
    def getter
      unless readonly?      
        value = attributes.detect { |att| att =~ /^getter=/i }
        value.nil? ? name : value.split('=').last.strip
      end
    end
    
    def setter
      value = attributes.detect { |att| att =~ /^setter=/i }
      value.nil? ? "#{name}=" : "#{value.split('=').last.strip}="
    end
    
    def ib_outlet?
      prop.property_type.text_value.include?('IBOutlet')
    end
    
    def readonly?
      attributes.include?('readonly')
    end
    
    def to_s
      prop.text_value
    end
  end
end