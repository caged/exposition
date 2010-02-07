dir = File.expand_path(File.dirname(__FILE__))
$: << dir

require 'nodes/sourcefile'
require 'nodes/language'
require 'nodes/properties'
require 'nodes/methods'
require 'nodes/comments'
require 'nodes/objcclasses'
require 'nodes/document'