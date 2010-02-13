(function() {
  function addClassName(el, name) {
    var existingClasses = el.getAttribute('class') || '';
    el.setAttribute('class', existingClasses + ' ' + name);
    return el;
  }
  
  function removeClassName(el, name) {
    var existingClasses = el.getAttribute('class') || '';
    names = existingClasses.replace(name, '');
    el.setAttribute('class', names);
    return el;
  }
  
  function setupTableOfContents() {
    var elements = document.querySelectorAll("#toc ul li ul");
    for (var i = elements.length - 1; i >= 0; i--){
      var el = elements[i];
      var parent = el.parentNode;
      addClassName(el, 'hidden');
      addClassName(parent, 'ex');

      parent.addEventListener('click', function(event) {
        if(event.target.tagName.toLowerCase() == 'li') {
            var ul = this.querySelector('ul');
   	       if((/hidden/).test(ul.getAttribute('class'))) {
   	         addClassName(this, 'exp');
   	         removeClassName(ul, 'hidden'); 
   	       } else {
   	         removeClassName(this, 'exp');
   	         addClassName(ul, 'hidden'); 
   	       }
  	       }
   	    }, true);
      } 
  }
      
  document.addEventListener('DOMContentLoaded', function(e) {
      setupTableOfContents();
  }, null);
})();