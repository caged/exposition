module Exposition
  # Originally based on Sinatra
  module Templates
    def erb(view, options = {})
      render :erb, view, options
    end
    
    def partial(view, *args)
      view_array = view.to_s.split('/')
      view = (view_array[0..-2] << "_#{view_array[-1]}").join('/')
      view = config.templates_root + template + view
            
      options = args.last.is_a?(Hash) ? args.pop : {}
      options.merge!(:layout => false)
      if collection = options.delete(:collection) then
        collection.inject([]) do |buffer, member|
          buffer << erb(:"#{view}", options.merge(:layout =>
          false, :locals => {view_array[-1].to_sym => member}))
        end.join("\n")
      else
        erb(view.to_s.to_sym, options)
      end
    end
    
    private
      def render(engine, view, options ={})
        options = config.to_hash.merge(options)
      
        layout = options.delete(:layout)
        layout = 'layout' if layout.nil? || options[:layout] == true
        views  = config.templates_root + template
        locals = options.delete(:locals) || {}
      
        options[:file_path] = "#{views + view.to_s}.#{engine}"
        template_data = File.read(options[:file_path])
        output = self.send("render_#{engine}", view, template_data, options, locals)
        
        unless layout.nil? || !layout
          options[:file_path] = "#{views + layout.to_s}.#{engine}"
          data = File.read(options[:file_path])
          unless data.nil?
            output = self.send("render_#{engine}", layout, data, options, locals) { output }
          end
        end

        output
      end
      
      def render_erb(template, data, options, locals, &block)
        original_out_buf = defined?(@_out_buf) && @_out_buf
        
        instance = ::ERB.new(data, nil, '-', '@_out_buf')
        local_assigns = locals.to_a.collect { |k,v| "#{k} = locals[:#{k}]" }
        eval(local_assigns.join("\n"), binding)
        eval(instance.src, binding, options[:file_path], 1)
        @_out_buf, result = original_out_buf, @_out_buf
        result
      end
  end
end