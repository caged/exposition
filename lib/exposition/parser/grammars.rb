dir = File.expand_path(File.dirname(__FILE__))
$: << dir

Treetop.load File.join(dir, 'grammars', 'sourcefile')
Treetop.load File.join(dir, 'grammars', 'language')
Treetop.load File.join(dir, 'grammars', 'properties')
Treetop.load File.join(dir, 'grammars', 'methods')
Treetop.load File.join(dir, 'grammars', 'comments')
Treetop.load File.join(dir, 'grammars', 'objcclasses')
Treetop.load File.join(dir, 'grammars', 'document')