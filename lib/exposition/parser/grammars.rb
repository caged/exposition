dir = File.expand_path(File.dirname(__FILE__))
$: << dir

Treetop.load File.join(dir, 'grammars', 'document')