dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH << dir

require 'generator/reconciler'

module Exposition
  class Generator
    attr_accessor :parsed_source_files
    
    def initialize(options = {})
      @reconciler = Reconciler.new
    end
    
    def generate_from_source_files(files)
      symbols = {
        :protocols  => {},
        :classes    => {},
        :categories => {}
      }
      files.each do |source|
        source.info.objc_classes.each do |klass|
          sym_name = klass.name.downcase.to_sym
          if symbols[:classes][sym_name].nil? 
            symbols[:classes][sym_name] = klass
          end
        end
        
        source.info.objc_protocols.each do |klass|
          sym_name = klass.name.downcase.to_sym
          if symbols[:protocols][sym_name].nil? 
            symbols[:protocols][sym_name] = klass
          end
        end
        
        source.info.objc_categories.each do |klass|
          sym_name = klass.name.downcase.to_sym
          if symbols[:categories][sym_name].nil? 
            symbols[:categories][sym_name] = klass
          end
        end
      end
      
      symbols.each do |group, objects|
        objects.each do |key, val|
          puts val.name
          val.methods.each do |m|
            puts m.ref
          end
        end
      end
    end
  end
end