require 'rubygems'
require 'treetop'
require 'pp'
require 'term/ansicolor'

include Term::ANSIColor

dir = File.expand_path(File.dirname(__FILE__))
$LOAD_PATH << dir

require 'exposition/parser'