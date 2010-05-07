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
            
            contents = erb :'objc-class'
            current_file.open('w') do |f|
              f << contents
            end
          end
        end
        
        def create_protocols_documentation
          objc_protocols.each do |key, klass|
            current_file = documents_directory + "Protocols/#{klass.name}.html"
            @relative_assets = assets_relative_from_file(current_file.parent)
            @page_title = "#{klass.name} Protocol Reference"
            @object = klass
            
            contents = erb :'objc-class'
            current_file.open('w') do |f|
              f << contents
            end
          end
        end
        
        def create_categories_documentation
          objc_categories.each do |key, klass|
            current_file = documents_directory + "Categories/#{klass.cleaned_name}.html"
            @relative_assets = assets_relative_from_file(current_file.parent)
            @page_title = "#{klass.name} #{klass.category_name} Category Reference"
            @object = klass
            
            contents = erb :'objc-class'
            current_file.open('w') do |f|
              f << contents
            end
          end
        end
        
        def create_index_document
          current_file = documents_directory + "index.html"
          @relative_assets = assets_relative_from_file(current_file.parent)
          contents = erb :index, :locals => {
            :objc_classes => objc_classes,
            :objc_protocols => objc_protocols,
            :objc_categories => objc_categories,
            :flowable => true,
            :hide_toc => true
          }
          current_file.open('w') do |f|
            f << contents
          end
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