'use strict'
/* To set the attributes of a property or to create a new property with the
specified attributes, call Object.defineProperty(), passing the
object to be modified, the name of the property to be created or altered,
and the property descriptor object: */

let Obj = { z : 'default' };

// adding a non-enumerable property
Object.defineProperty(Obj, "x", {
  value: 1,
  writable: true, // can be changed in assignment
  enumerable: false, // wont be added in the array returned by Object.keys()
                     // wont be displayed in console.log or JSON.stringify()
  
  configurable: true
});

// modifies the property x and make it read-only
Object.defineProperty(Obj,'x',{writable: false});

// change x from a data property to an accessor property and make it enumerable
Object.defineProperty(Obj,'x',{ get: function() { return 0;}, enumerable: true });

// define new multiple properties
Object.defineProperties(Obj, {
  y : { value: 3, writable: true, enumerable: false },
  w : { value: 'double-yuu', writable: false, enumerable: true }
});

// get a specific property attributes
console.log('\nObj x property attributes',Object.getOwnPropertyDescriptor(Obj,'x'));

// get all object's property attributes
console.log('\nObj\'s all property attributes',Object.getOwnPropertyDescriptors(Obj));

/* The property descriptor you pass to Object.defineProperty()
does not have to include all four attributes. If you’re creating a new
property, then omitted attributes are taken to be false or
undefined. If you’re modifying an existing property, then the
attributes you omit are simply left unchanged. Note that this method
alters an existing own property or creates a new own property, but it
will not alter an inherited property. See also the very similar function
Reflect.defineProperty() */

console.log('\nObj = ',Obj);

/* RULE CALLS TO Object.defineProperties()

  > If an object is not extensible, you can edit its existing own
    properties, but you cannot add new properties to it.
  
  > If a property is not configurable, you cannot change its
    configurable or enumerable attributes.
  
  > If an accessor property is not configurable, you cannot change
    its getter or setter method, and you cannot change it to a data
    property.

  > If a data property is not configurable, you cannot change it to
    an accessor property.

  > If a data property is not configurable, you cannot change its
    writable attribute from false to true, but you can change it
    from true to false.

  > If a data property is not configurable and not writable, you
    cannot change its value. You can change the value of a
    property that is configurable but nonwritable, however
    (because that would be the same as making it writable, then
    changing the value, then converting it back to nonwritable). */