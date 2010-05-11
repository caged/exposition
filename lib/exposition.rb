require 'rubygems'
require 'treetop'
require 'fileutils'
require 'builder'
require 'pathname'
require 'rdiscount'
require 'erb'
require 'digest/sha1'

require 'term/ansicolor'
require 'pp'

include Term::ANSIColor

dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH << dir

require 'exposition/ext'
require 'exposition/symbol_mapper'
require 'exposition/parser'
require 'exposition/templates'
require 'exposition/generator'
require 'exposition/configuration'

module Exposition  
  class Documentation
    attr_reader   :config
    attr_accessor :source_files
    
    def initialize
      @config = Configuration.new
      @parser = Parser.new
    end
    
    # Take a list of Pathname objects and parse for documentation.
    def self.generate!
      if block_given?
        parser = new
        yield parser.config
        parser.run
      else
        new.run
      end
    end
    
    def run
      run_parse      
      run_generator
      run_stats
    end
    
    private
      def run_parse
        puts "Parsing #{source_files.collect { |sf| File.basename(sf)  }.join(', ')}\n\n\n"
        source_files.each_with_index do |file, index|
          progress = '=' * (index + 1) << ">"
          progress << "]".rjust(source_files.size - progress.size, "+")
          progress = " [" << progress
        
          unless @config.verbose
            puts "\c[[FParsing #{index + 1} of #{source_files.size}:" << red(progress)
          else
            puts red(underscore("#{file.basename} #{index + 1} of #{source_files.size}"))
          end
        
          content = File.read(file)
          doc = @parser.parse(content)
          raise ParseError, @parser unless doc
                
          sf = SourceFile.new
          sf.location = file
          sf.info = doc
          sf.source = content
          SymbolMapper.docs << sf
        
        
          stats_for_doc(doc) if @config.verbose          
        end
        puts "\n\n"
      end
    
      def run_generator
        generators = @config.generators
        generators.each do |generator, template|
          gen_name = generator.to_s.gsub(/\_+|\-+/, ' ').split.collect { |s| s.capitalize }
          gen = Exposition::Generators.module_eval("#{gen_name}", __FILE__, __LINE__)
          gen::Generator.new(template, @config).generate
        end
      end
    
      # TODO: Move this to its own file
      def stats_for_doc(doc)
        puts "  - #{doc.objc_classes.size} Classes"
        puts "  - #{doc.objc_categories.size} Categories"
        puts "  - #{doc.objc_protocols.size} Protocols"
        puts "  - #{sum(doc.objc_objects.collect { |obj| obj.methods.size })} Methods"
        puts "  - #{sum(doc.objc_objects.collect { |obj| obj.properties.size })} Properties"
      end
    
      def run_stats
        if @config.show_stats
          total_classes           = sum(SymbolMapper.docs.collect { |doc| doc.info.objc_classes.size })
          total_categories        = sum(SymbolMapper.docs.collect { |doc| doc.info.objc_categories.size })
          total_protocols         = sum(SymbolMapper.docs.collect { |doc| doc.info.objc_protocols.size })
          total_class_methods     = sum(SymbolMapper.docs.collect { |doc| sum(doc.info.objc_classes.collect { |c| c.class_methods.size })})
          total_instance_methods  = sum(SymbolMapper.docs.collect { |doc| sum(doc.info.objc_classes.collect { |c| c.instance_methods.size })})
          total_properties        = sum(SymbolMapper.docs.collect { |doc| sum(doc.info.objc_classes.collect { |c| c.properties.size })})
      
          cols = `tput cols`.to_i

          puts yellow("=" * cols)
          puts "#{blue(total_classes.to_s)} TOTAL CLASSES"
          puts "#{blue(total_categories.to_s)} TOTAL CATEGORIES"
          puts "#{blue(total_class_methods.to_s)} TOTAL CLASS METHODS"
          puts "#{blue(total_instance_methods.to_s)} TOTAL INSTANCE METHODS"
          puts "#{blue(total_properties.to_s)} TOTAL PROPERTIES"
          puts yellow("=" * cols)
          puts "\n\n"
        end
      end
    
      def source_files
        excludes = @config.exclude_files.collect { |sf| sf.to_s }        
        @config.include_files.select do |sfile|
          !excludes.include?(sfile.to_s)
        end
      end
    
      def sum(arr)
        arr.inject( 0 ) { |sum,x| sum+x }
      end
  end
  
  class SourceFile < Struct.new(:name, :location, :source, :info)
    def name
      File.basename(location)
    end
  end
end