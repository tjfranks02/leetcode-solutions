/**
 * Basic solution to counter javascript problem.
 */
var createCounter = function(n) {
  let first = true;
  
  return function() {
      if (first) {
          first = false;
          return n;
      }

      n += 1;
      return n;
  };
};