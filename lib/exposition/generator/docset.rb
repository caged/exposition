module Exposition
  module Generators
    module DocSet
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
        end
        
        def resources_directory
          doc_root + 'Contents/Resources'
        end
        
        def documents_directory
          doc_root + resources_directory + 'Documents'
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
              end
            end
          end
        
          File.open(File.join(resources_directory, 'Nodes.xml'), 'w') do |f|
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
              plist.key 'DocSetPublisherIdentifier'
              plist.string config.publisher_identifier
              plist.key 'DocSetPublisherName'
              plist.string config.publisher_name
            end
          end          
          
          plist_file.open('w') do |f|
            f << plist.target!
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
        
        # def current_file
        #   Pathname.new('foo')
        # end
        
        private
          def assets_relative_from_file(file)
            @assets.collect do |asset|
              asset.relative_path_from(file)
            end
          end
          
          # TODO: A not so ugly way to do this?
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
            contents = erb :'objc-class', :locals => env_locals.merge(locals)
            file.open('w') do |f|
              f << contents
            end
          end
      end
    end
  end
end