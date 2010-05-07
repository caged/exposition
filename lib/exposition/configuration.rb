module Exposition
  class Configuration
    # The name of the current project
    attr_accessor :project_name
    
    # Show stats tables
    attr_accessor :show_stats
    
    # Glob of files to include
    attr_accessor :includes
    
    # Glob of files exclude
    attr_accessor :excludes
    
    # Whether or not to add members (methods, properties, instance variables, etc) 
    # to the documentation output
    attr_accessor :publish_underscored_members 
    
    # Which generators to use
    attr_accessor :generators
    
    # What direction should we put the documentaiton in
    attr_accessor :output_directory
    
    # The name of the documentation bundles
    attr_accessor :bundle_name
    
    # Whether or not to force rebulding of the documentaiton directory instead of 
    # failing if the directory exists
    attr_accessor :force_rebuild
    
    # Root directory where template directories are located
    attr_accessor :templates_root
    
    # The layout file for html based templates
    attr_accessor :layout
    
    # Get loud during parsing
    attr_accessor :verbose
    
    # Markdown Guides to include with the docset
    attr_accessor :guides
    
    # Main overview text shown on home page
    attr_accessor :main_overview
    
    def initialize
      self.project_name = ''
      self.show_stats = false
      self.includes   = []
      self.excludes   = []
      self.publish_underscored_members = false
      self.generators = [:docset]
      self.templates_root = Pathname.new(File.join(File.dirname(__FILE__), 'templates'))
      self.layout = 'layout'
      self.verbose = false
    end
    
    # TODO: Investigate why the Hash[*attrs] trick isn't working
    def to_hash
      hash = {}
      instance_variables.each do |var|
        var = var.to_s.sub('@', '').to_sym
        hash[var] = send(var)
      end
      hash
    end
  end
end