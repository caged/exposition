module ObjCClasses  
  class ObjCObject < Language::Documentable
    include Enumerable
    include Properties
    include Methods
    include Comments
    
    def self.symbol
      'cl'
    end
    
    def each
      elements.each { |e| yield e }
    end
    
    def members
      methods + properties
    end
    
    def properties
      objc_members.elements.select { |e| e.is_a?(Property) }
    end
    
    def methods
      instance_methods + class_methods
    end
    
    def instance_methods
     objc_members.elements.select { |e| e.is_a?(InstanceMethod) }
    end
    
    def class_methods
      objc_members.elements.select { |e| e.is_a?(ClassMethod) }
    end
    
    def conforms_to
      []
    end
    
    def class?
      is_a?(ObjCClass)
    end
    
    def protocol?
      is_a?(ObjCProtocol)
    end
    
    def category?
      is_a?(ObjCCategory)
    end
  end
  
  class ObjCClass < ObjCObject
    def name
      class_decleration.class_name.text_value.strip
    end
    
    def superclass
      class_decleration.inheritance_and_protocol.superclass.text_value.strip
    end
    
    def conforms_to
      class_decleration.inheritance_and_protocol.pcalls
    end
    
    def instance_variables
      ivar_elements = class_decleration.instance_variable_area.instance_variables.elements
      ivar_elements.select { |e| e.is_a?(InstanceVariable) }
    end
    
    def symbol
      'cl'
    end
  end
  
  class ObjCCategory < ObjCObject
    def name
      category_decleration.class_name.text_value
    end
    
    def category_name
      category_decleration.desc.text_value
    end
    
    def cleaned_name
      "#{name}_#{category_name.strip.gsub(/\s+/, '')}"
    end
    
    def ref
      "//apple_ref/occ/#{self.class.symbol}/#{cleaned_name}"
    end
    
    def self.symbol
      'cat'
    end
  end
  
  class ObjCProtocol < ObjCObject
    def name
      protocol_name.text_value.strip
    end
    
    def conforms_to
      pcalls
    end
    
    def self.symbol
      'intf'
    end
  end
  
  class InstanceVariable < Treetop::Runtime::SyntaxNode
    include Language
    
    def name
      ivar_name.text_value.strip
    end
    
    def type
      type_name.text_value.strip
    end
    
    def conforms_to
      pcalls.is_a?(Protocols) ? pcalls : []
    end
  end
end