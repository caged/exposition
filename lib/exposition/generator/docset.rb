module Exposition
  module Generators
    module DocSet
      class DocsetUtilNotFoundError < StandardError; end
      class Generator < Exposition::Generators::Base
        def generate
          create_output_directory
          create_docset_base_structure          
          copy_assets
          
          create_index_document
          
          create_classes_documentation
          create_protocols_documentation
          create_categories_documentation
          
          create_info_plist
          create_nodes_file
          create_tokens_file
          
          unless docsetutil.nil?
            index_docset
            generate_package
            print_package_info if config.verbose
          end
        end
        
        def bundle_root
          doc_root + config.bundle_name
        end
        
        def resources_directory
          bundle_root + 'Contents/Resources'
        end
        
        def documents_directory
          bundle_root + resources_directory + 'Documents'
        end

        def create_docset_base_structure
          documents_directory.mkpath
          %w(Classes Protocols Categories).each do |obj_type|
            (documents_directory + obj_type).mkpath
          end
        end
        
        def create_classes_documentation
          objc_classes.each do |key, klass|
            current_file = documents_directory + "Classes/#{klass.name}.html"
            @relative_assets = assets_relative_from_file(current_file.parent)
            @page_title = "#{klass.name} Class Reference"
            @object = klass
            write_object_file(current_file)
          end
        end
        
        def create_protocols_documentation
          objc_protocols.each do |key, klass|
            current_file = documents_directory + "Protocols/#{klass.name}.html"
            @relative_assets = assets_relative_from_file(current_file.parent)
            @page_title = "#{klass.name} Protocol Reference"
            @object = klass
            write_object_file(current_file)
          end
        end
        
        def create_categories_documentation
          objc_categories.each do |key, klass|
            current_file = documents_directory + "Categories/#{klass.cleaned_name}.html"
            @relative_assets = assets_relative_from_file(current_file.parent)
            @page_title = "#{klass.name} #{klass.category_name} Category Reference"
            @object = klass
            write_object_file(current_file)
          end
        end
        
        def create_index_document
          current_file = documents_directory + "index.html"
          @relative_assets = assets_relative_from_file(current_file.parent)
          define_current_file(current_file)
          contents = erb :index, :locals => {
            :flowable => true,
            :hide_toc => true
          }
          current_file.open('w') do |f|
            f << contents
          end
        end
        
        def create_nodes_file
          xml = Builder::XmlMarkup.new(:indent => 2)
          xml.instruct!
          xml.DocSetNodes :version => 1.0 do
            xml.TOC do
              xml.Node do
                xml.Name "#{config.project_name} Documentation"
                xml.Path 'index.html'
                xml.Subnodes do
                  
                end
              end
            end
          end
        
          File.open(File.join(resources_directory, 'Nodes.xml'), 'w') do |f|
            f << xml.target!
          end
        end
        
        def create_tokens_file
          xml = Builder::XmlMarkup.new(:indent => 2)
          xml.instruct!
          xml.Tokens :version => 1.0 do
            objc_classes.each_with_index do |objc_class, index|
              objc_class = objc_class[1]
              xml.File :path => path_for_object(objc_class) do
                xml.Token do
                  xml.TokenIdentifier objc_class.ref
                end
                objc_class.members.each do |method|
                  xml.Token do
                    xml.TokenIdentifier method.ref
                    if method.is_a?(Methods::Method)
                      xml.Anchor method.body_of_method
                    else
                      xml.Anchor method.name
                    end
                  end
                end
              end
            end
          end
          
          File.open(File.join(resources_directory, 'Tokens.xml'), 'w') do |f|
            f << xml.target!
          end
        end
        
        def create_info_plist
          plist_file = resources_directory.parent + 'Info.plist' # Contents Directory
          
          plist = Builder::XmlMarkup.new(:indent => 2)
          plist.instruct!
          plist.declare! :DOCTYPE, :plist, :PUBLIC, "-//Apple Computer//DTD PLIST 1.0//EN", "http://www.apple.com/DTDs/PropertyList-1.0.dtd"
          plist.plist :version => 1.0 do
            plist.dict do
              plist.key 'CFBundleName'
              plist.string "#{config.project_name} Documentation"
              plist.key 'CFBundleIdentifier'
              plist.string config.bundle_name
              plist.key 'CFBundleShortVersionString'
              plist.string config.version
              plist.key 'CFBundleVersion'
              plist.string config.version
              plist.key 'DocSetPublisherIdentifier'
              plist.string config.publisher_identifier
              plist.key 'DocSetPublisherName'
              plist.string config.publisher_name
              if config.feed_url
                plist.key 'DocSetFeedName'
                plist.string "#{config.project_name} Documentation"
                plist.key 'DocSetFeedURL'
                plist.string config.feed_url
              end
            end
          end          
          
          plist_file.open('w') do |f|
            f << plist.target!
          end
        end
        
        def index_docset
          puts blue(bold("==> Indexing documentation.  This could take a while..."))
          Open3.popen3 "#{docsetutil} index #{bundle_root}" do |stdin, stdout, stderr|
            puts stdout.read
          end
        end
        
        def generate_package
          if config.feed_url && config.download_url
            puts blue(bold("==> Generating xar package and feed"))
            package_command = %(#{docsetutil} package #{bundle_root} -atom "#{doc_root + 'docs.atom'}" -download-url "#{config.download_url}")
            Open3.popen3 package_command do |stdin, stdout, stderr|
              puts stdout.read
            end
          end
        end
        
        def print_package_info
          Open3.popen3 "#{docsetutil} dump #{bundle_root}" do |stdin, stdout, stderr|
            puts stdout.read
          end
        end
        
        def copy_assets
            template_dir = (config.templates_root + template)
            Pathname.glob("#{template_dir}/assets/**/*").each do |item|
              path = item.relative_path_from(template_dir)
              current_asset = documents_directory + path
              
              current_asset.dirname.mkpath unless File.exists?(current_asset.dirname)
              current_asset.open('w') do |f|
                f << File.read(item)
                @assets << current_asset
              end unless item.directory?
            end
        end
        
        private
          def path_for_object(obj)
            dir = 'Classes' if obj.class?
            dir = 'Prototcols' if obj.protocol?
            dir = 'Categories' if obj.category?
            name = obj.category? ? obj.clean_name : obj.name
            "#{dir}/#{name}.html"
          end
          
          def assets_relative_from_file(file)
            @assets.collect do |asset|
              asset.relative_path_from(file)
            end
          end
          
          # TODO: A not so ugly way to do this?
          # This is needed so links in template can be relative to the location 
          # of the current file we're in
          def define_current_file(file)
            @f = file
            instance_eval do
              def current_file
                @f
              end
            end
          end
        
          def write_object_file(file, locals = {})
            define_current_file(file)
            env_locals = {}
            contents = erb 'objc-object', :locals => env_locals.merge(locals)
            file.open('w') do |f|
              f << contents
            end
          end
          
          def docsetutil
              paths = [
                '/Developer/usr/bin/docsetutil', 
                '/usr/local/bin/docsetutil', 
                '/usr/bin/docsetutil'
              ]

              @docsetutil ||= paths.detect do |p|
                File.exists?(p) && Open3.popen3(p) do |stdin, stdout, stderr|
                  stderr.gets.nil?
                end
              end
            if @docsetutil.nil?
              red("Unable to find docsetutil. Make sure it's in your $PATH.  I looked for it here #{paths.join(',')}")
              red('Skipping keyword indexing, xar packaging and feed generation')
            end
            @docsetutil
          end
      end
    end
  end
end