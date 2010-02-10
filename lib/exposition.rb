require 'rubygems'
require 'treetop'
require 'pp'
require 'term/ansicolor'

include Term::ANSIColor

dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH << dir

require 'exposition/parser'
require 'exposition/generator'

module Exposition
  class Documentation
    attr_reader :config
    
    def initialize(*source_files)
      @config = Configuration.new
      @source_files = source_files
      @parsed_docs = []
      @parser = Parser.new
      @generator = Generator.new
    end
    
    def self.generate!(*source_files)
      if block_given?
        parser = new(*source_files)
        yield parser.config
        parser.run
      else
        new(*source_files).run
      end
    end
    
    def run
      parse
      @generator.generate_from_source_files(@parsed_docs)
      show_stats if !@config.show_stats
    end
    
    def parse
      puts "Parsing #{@source_files.collect { |sf| File.basename(sf)  }.join(', ')}\n\n\n"
      @source_files.each_with_index do |file, index|
        progress = '=' * (index + 1) << ">"
        progress << "]".rjust(@source_files.size - progress.size, "+")
        progress = " [" << progress
        puts "\c[[FParsing #{index + 1} of #{@source_files.size}:" << red(progress)
        
        content = File.read(file)
        doc = @parser.parse(content)
        raise ParseError, @parser unless doc
        
        sf = SourceFile.new
        sf.location = file
        sf.info = doc
        sf.source = content
        @parsed_docs << sf
      end
      puts "\n\n\n"
    end
    
    def show_stats
      total_classes           = sum(@parsed_docs.collect { |doc| doc.info.objc_classes.size })
      total_categories        = sum(@parsed_docs.collect { |doc| doc.info.objc_categories.size })
      total_protocols         = sum(@parsed_docs.collect { |doc| doc.info.objc_protocols.size })
      total_class_methods     = sum(@parsed_docs.collect { |doc| sum(doc.info.objc_classes.collect { |c| c.class_methods.size })})
      total_instance_methods  = sum(@parsed_docs.collect { |doc| sum(doc.info.objc_classes.collect { |c| c.instance_methods.size })})
      total_properties        = sum(@parsed_docs.collect { |doc| sum(doc.info.objc_classes.collect { |c| c.properties.size })})
      
      max_name_length = @parsed_docs.collect { |pd| pd.name.size }.max
      cols = `tput cols`.to_i
      headers = {
        :name => bold(red('NAME'.center(max_name_length + 2))),
        :classes => bold(red('CLASSES'.center(30))),
        :properties => bold(red('PROPERTIES').center(30)),
        :class_methods => bold(red('CLASS METHODS').center(30)),
        :instance_methods => bold(red('INSTANCE METHODS').center(30))
      }
      
      @parsed_docs.each do |pd|
        objc = pd.info
        
        klasses           = objc.objc_classes
        categories        = objc.objc_categories
        protocols         = objc.objc_protocols
        properties        = klasses.collect { |c| c.properties }.flatten
        instance_methods  = klasses.collect { |c| c.instance_methods }.flatten + 
                            categories.collect { |c| c.instance_methods }.flatten +
                            protocols.collect { |p| p.instance_methods }.flatten
        class_methods     = klasses.collect { |c| c.class_methods }.flatten + 
                            categories.collect { |c| c.class_methods }.flatten + 
                            protocols.collect { |p| p.class_methods }.flatten
        
        # TODO REFACTOR THIS
        
        # HEADER
        puts '+' << ('-' * (cols - 2)) << '+'
        header = "#{headers[:name]} | #{headers[:classes]} | #{headers[:properties]} | #{headers[:class_methods]} | #{headers[:instance_methods]}"
        puts header
        
        # STATS 
        puts '+' << ('-' * (cols - 2)) << '+'
        name = pd.name.ljust(max_name_length, ' ')
        puts "| #{blue(name)} | #{klasses.size.to_s.center(30)} | #{properties.size.to_s.center(21)} | #{class_methods.size.to_s.center(21)} | #{instance_methods.size.to_s.center(21)}"
       
        # PROPERTIES
        puts '+' << ('-' * (cols - 2)) << '+'
        puts properties.collect { |p| "| #{p.to_s.ljust(cols - 4)} |"}
        
        # CLASS METHODS
        puts '+' << ('-' * (cols - 2)) << '+'
        puts class_methods.collect { |cm| "| #{cm.name.ljust(cols - 4)} |"}
       
        # INSTANCE METHODS
        puts '+' << ('-' * (cols - 2)) << '+'
        puts instance_methods.collect { |im| "| #{im.name.ljust(cols - 4)} |"}
        
        # FOOTER
        puts '+' << ('-' * (cols - 2)) << '+'
        puts "\n\n"
      end
      
      puts yellow("=" * cols)
      puts "#{blue(total_classes.to_s)} TOTAL CLASSES"
      puts "#{blue(total_categories.to_s)} TOTAL CATEGORIES"
      puts "#{blue(total_class_methods.to_s)} TOTAL CLASS METHODS"
      puts "#{blue(total_instance_methods.to_s)} TOTAL INSTANCE METHODS"
      puts "#{blue(total_properties.to_s)} TOTAL PROPERTIES"
      puts yellow("=" * cols)
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
  
  class Configuration
    # Show stats tables
    attr_accessor :show_stats
    
    # Glob of files to include
    attr_accessor :includes
    
    # Glob of files exclude
    attr_accessor :excludes
    
    # Whether or not to add members (methods, properties, instance variables, etc) 
    # to the documentation output
    attr_accessor :publish_underscored_members 
    
    attr_accessor :templates
    
    def initialize
      self.show_stats = false
      self.includes   = []
      self.excludes   = []
      self.publish_underscored_members = false
      self.templates = [:docset]
    end
  end
end