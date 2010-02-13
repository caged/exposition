module Exposition
  module Generators
    module Helpers
      def markdown(str)
        RDiscount.new(str).to_html
      end
      
      def anchor_for_collection(collection)
        collection.first.class.symbol
      end
    end
  end
end