class String
  def integer?
    self =~ /\A\d+\Z/
  end
end