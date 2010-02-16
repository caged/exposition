module Exposition
  class SymbolMapper
    class << self; attr_accessor :docs end
    @docs = []
    
    def self.find(type, sym)
      case type.to_sym
        when :objc_class then find_class(sym)
        when :objc_category then find_category(sym)
        when :objc_protocol then find_protocol(sym)
        when :objc_object then find_object(sym)
      end
    end
    
    def self.objc_classes
      @classes ||= docs.collect do |d|
        d.info.objc_classes
      end.flatten
    end
    
    def self.objc_categories
      @categories ||= docs.collect do |d|
        d.info.objc_categories
      end.flatten
    end
    
    def self.objc_protocols
      @protocols ||= docs.collect do |d|
        d.info.objc_protocols
      end.flatten
    end
    
    private
      def self.find_class(sym)
        objc_classes.detect { |c| c.name == sym }
      end
      
      def self.find_category(sym)
        objc_categories.detect { |c| c.name == sym }
      end
      
      def self.find_protocol(sym)
        objc_protocols.detect { |c| c.name == sym }
      end
      
      def self.find_object(sym)
        (objc_classes + objc_categories + objc_protocols).detect { |c| c.name == sym }
      end
  end
end