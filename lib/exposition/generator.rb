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
          if symbols[:classses][sym_name].nil? 
            symbols[:classes][sym_name] = klass
          end
        end
        
        source.info.objc_classes.each do |klass|
          sym_name = klass.name.downcase.to_sym
          if symbols[:classses][sym_name].nil? 
            symbols[:classes][sym_name] = klass
          end
        end
      end
      pp symbols.keys
      
    end
  end
end