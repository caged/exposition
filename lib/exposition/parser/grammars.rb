dir = File.expand_path(File.dirname(__FILE__))
$: << dir

Treetop.load File.join(dir, 'grammars', 'basic')
Treetop.load File.join(dir, 'grammars', 'properties')
Treetop.load File.join(dir, 'grammars', 'document')