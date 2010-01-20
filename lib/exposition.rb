require 'rubygems'
require 'treetop'
require 'pp'

dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH << dir

require 'exposition/parser'