require 'rubygems'
require 'treetop'
require 'pp'
require 'term/ansicolor'

include Term::ANSIColor

dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH << dir

require 'exposition/parser'

module Exposition
  class Documentation
    def initialize(*source_files)
      @options = source_files.last.is_a?(Hash) ? source_files.pop : {}
      @source_files = source_files
      @parsed_docs = []
      @parser = Parser.new
    end
    
    def self.generate!(*source_files)
      new(*source_files).parse
    end
    
    def parse
      puts "Parsing #{@source_files}"
      puts 'Processing... 0%'
      @source_files.each do |file|
        content = File.read(file)
        doc = @parser.parse(content)
        raise ParseError, @parser unless doc
        
        sf = SourceFile.new
        sf.location = file
        sf.parse_tree = doc
        sf.source = content
        @parsed_docs << sf
      end
      
      @parsed_docs.each do |doc|
        puts "\n"
        puts red(doc.name)
        puts doc.parse_tree.properties
      end
      # Thread.new(@parser) do |parser|
      # 
      #   # 
      #   # i = 0        
      #   # begin          
      #   #   dots = ('.' * i) << (' ' * (3-i)) 
      #   #   puts "\c[[F    Processing#{dots} #{parser.completion_percentage}"
      #   #   i =  i == 3 ? 0 : i + 1
      #   #   sleep 0.1
      #   # end until parser.complete?
      #   # start_time = Time.new
      #   # @parsed_docs = @parser.parse
      #   # puts "\c[[F    Parsing completed in #{Time.new - start_time} seconds.\n\n"
      # end
    end
  end
  
  class SourceFile < Struct.new(:name, :location, :source, :parse_tree)
    def name
      File.basename(location)
    end
  end
end