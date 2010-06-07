module Exposition
  module Generators
    module Helpers      
      def markdown(str)
        RDiscount.new(str).to_html
      end
      
      def classes_for_container
        %( class="flowable") if defined?(@flowable) && @flowable
      end
      
      def anchor_for_collection(collection)
        collection.first.class.symbol
      end
      
      def relative_link_to_project
        project_path = documents_directory + 'index.html'
        path = project_path.relative_path_from(current_file.parent)
        %(<a href="#{path}">#{config.project_name}</a>)
      end
      
      def link_to_class(sym)
        if obj = SymbolMapper.find(:objc_class, sym)
          to_file = Pathname.new("#{documents_directory}/Classes/#{sym}.html")
          path = to_file.relative_path_from(current_file.parent)
          sym = %(<a href="#{path}##{obj.ref}">#{obj.name}</a>)
        end
        sym
      end
      
      def link_to_protocol(sym)
        if obj = SymbolMapper.find(:objc_protocol, sym)
          to_file = Pathname.new("#{documents_directory}/Protocols/#{sym}.html")
          path = to_file.relative_path_from(current_file.parent)
          sym = %(<a href="#{path}##{obj.ref}">#{obj.name}</a>)
        end
        sym
      end
      
      def link_to_category(sym)
        if obj = SymbolMapper.find(:objc_category, sym)
          to_file = Pathname.new("#{documents_directory}/Categories/#{obj.cleaned_name}.html")
          path = to_file.relative_path_from(current_file.parent)
          sym = %(<a href="#{path}##{obj.ref}">#{obj.name} (#{obj.category_name})</a>)
        end
        sym
      end
      
      def link_to_task(title, obj)
        %(<a href="#{documents_directory}/#{dir_for_object(obj)}/#{obj.name}.html##{id_for_task(title, obj)}">#{title}</a>)
      end
      
      def id_for_task(title, obj)
        %(task-#{Digest::SHA1.hexdigest("#{obj}#{title}")})
      end
      
      def tasks_for_object(obj)
        members = obj.respond_to?(:members) ? obj.members : obj
        members.inject({}) do |ret, mem|
          task = mem.documentation.keywords.detect { |kw| kw.name == 'task' }
          unless task.nil?
            ret[task.body] ||= []
            ret[task.body] << mem 
          end
          ret
        end
      end
    end
  end
end