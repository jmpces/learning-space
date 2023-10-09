let dog = {
  name : 'Chuchu',
  age : 12,
  weight : 45
}


/* Property Attributes

  in javascript, normal object properties has 3 associated attributes :

    - writable : specifies whether or not the value of a
                 property can change, false = READ ONLY.
                 
                 when set to false assigning new value to it won't
                 do anything.
                 
                 when set to false and in STRICT MODE assigning a
                 value to a to it will throw a TypeError.

    - enumerable : specifies whether the property is enumerated
                   by the for/in loop and the Object.keys() method.
                   
                   also properties that are not enumerable (set to false)
                   won't be showed in console.log() or won't be included
                   when using JSON.stringify().

    - configurable : specifies whether a property can be deleted
                     and also whether the property’s attributes
                     can be changed.
*/
console.log('dog =',dog);
console.log('\ndog[name] attribute =',Object.getOwnPropertyDescriptor(dog,'name'))


// Here is an object with a read-only accessor property
const random = {
  get octet() { return Math.floor(Math.random()*256); },
};

console.log('\n\nrandom =',random);
// Returns { get: /*func*/, set:undefined, enumerable:true, configurable:true}
console.log('\nrandom[octet] attribute',Object.getOwnPropertyDescriptor(random, "octet"));

/* As its name implies, Object.getOwnPropertyDescriptor()
works only for own properties. To query the attributes of inherited
properties, you must explicitly traverse the prototype chain. (See
Object.getPrototypeOf() */

console.log('\n\nAll dog property attributes',Object.getOwnPropertyDescriptors(dog));