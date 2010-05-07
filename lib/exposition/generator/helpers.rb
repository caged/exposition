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
      
      def link_to_project
        %(<a href="#{documents_directory}/index.html">#{config.project_name}</a>)
      end
      
      def link_to_class(sym)
        obj = SymbolMapper.find(:objc_class, sym)
        %(<a href="#{documents_directory}/Classes/#{sym}.html##{obj.ref}">#{obj.name}</a>) unless obj.nil?
      end
      
      def link_to_protocol(sym)
        obj = SymbolMapper.find(:objc_protocol, sym)
        %(<a href="#{documents_directory}/Protocols/#{sym}.html##{obj.ref}">#{obj.name}</a>) unless obj.nil?
      end
      
      def link_to_category(sym)
        obj = SymbolMapper.find(:objc_category, sym)
        %(<a href="#{documents_directory}/Categories/#{sym}.html##{obj.ref}">#{obj.name}</a>) unless obj.nil?
      end
      
      def link_to_task(title, obj)
        dir = 'Classes' if obj.class?
        dir = 'Prototcols' if obj.protocol?
        dir = 'Categories' if obj.category?
        
        %(<a href="#{documents_directory}/#{dir}/#{obj.name}.html##{id_for_task(title, obj)}">#{title}</a>)
      end
      
      def id_for_task(title, obj)
        %(task-#{Digest::SHA1.hexdigest("#{obj}#{title}")})
      end
      
      def tasks_for_object(obj)
        obj.members.inject({}) do |ret, mem|
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