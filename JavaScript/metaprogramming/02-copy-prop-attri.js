/* the Object.assign() function copies property values
from one or more source objects into a target object.

Object.assign() only copies enumerable properties,
and property values, not property attributes.

This is normally what we want, but it does mean, for
example, that if one of the source objects has an
accessor property, it is the value returned by the
getter function that is copied to the target object,
not the getter function itself.*/

/* */

Object.defineProperty(Object, "assignDescriptors", {
  writable: true,
  enumerable: false,
  configurable: true,
  value: function(target, ...sources){
    for(let source of sources){
      for(let name of Object.getOwnPropertyNames(source)){
        let desc = Object.getOwnPropertyDescriptor(source,name);
        Object.defineProperty(target,name,desc);
      }

      for(let symbol of Object.getOwnPropertySymbols(source)){
        let desc = Object.getOwnPropertyDescriptor(source, symbol);
        Object.defineProperty(target,symbol,desc);
      }
    }
    return target;
  }
});

let o = {c:1, get count() {return this.c++;}};
let p = Object.assign({},o);
let q = Object.assignDescriptors({},o);

console.log(p);
console.log(q);