module Exposition
  module Generators
    module DocSet
      class Generator < Exposition::Generators::Base
        def generate
          create_output_directory
          create_docset_base_structure          
          copy_assets
          
          document_classes
          document_protocols
          document_categories
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
        
        def document_classes
          klasses.each do |key, klass|
            current_file = documents_directory + "Classes/#{klass.name}.html"
            @relative_assets = assets_relative_from_file(current_file.parent)
            @page_title = "#{klass.name} Class Reference"
            @object = klass
            contents = erb :'objc-class'
            current_file.open('w') do |f|
              f << contents
            end
          end
        end
        
        def document_protocols
          
        end
        
        def document_categories
          
        end
        
        # def create_nodes_file
        #   root = Builder::XmlMarkup.new(:indent => 2)
        #   root.nodes do |nodes|
        #     @docs.each do |doc|
        #       nodes.node do |n|
        #         n.name doc.location
        #       end
        #     end
        #   end
        #   File.open(File.join(resources_directory, 'Nodes.xml'), 'w') do |f|
        #     f << root.target!
        #   end
        
        
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
        
        def assets_relative_from_file(file)
          @assets.collect do |asset|
            asset.relative_path_from(file)
          end
        end
      end
    end
  end
end