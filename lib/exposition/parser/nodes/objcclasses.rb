module ObjCClasses
  class ObjCObject < Treetop::Runtime::SyntaxNode
    include Enumerable
    include Properties
    include Methods
    include Comments
    
    def each
      elements.each { |e| yield e }
    end
    
    def properties
      members.elements.select { |e| e.is_a?(Property) }
    end
    
    def methods
      instance_methods + class_methods
    end
    
    def instance_methods
     members.elements.select { |e| e.is_a?(InstanceMethod) }
    end
    
    def class_methods
      members.elements.select { |e| e.is_a?(ClassMethod) }
    end
    
    def documentation
      docs
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
    def symbol
      'cat'
    end
  end
  
  class ObjCProtocol < ObjCObject
    def symbol
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