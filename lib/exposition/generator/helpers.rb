module Exposition
  module Generators
    module Helpers
      def markdown(str)
        RDiscount.new(str).to_html
      end
      
      def anchor_for_collection(collection)
        collection.first.class.symbol
      end
      
      def link_to_class(sym)
        obj = SymbolMapper.find(:objc_class, sym)
        sym = %(<a href="#{documents_directory}/Classes/#{sym}.html##{obj.ref}">#{obj.name}</a>) unless obj.nil?
        sym
      end
      
      def link_to_protocol(sym)
        obj = SymbolMapper.find(:objc_protocol, sym)
        sym = %(<a href="#{documents_directory}/Protocols/#{sym}.html##{obj.ref}">#{obj.name}</a>) unless obj.nil?
        sym
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