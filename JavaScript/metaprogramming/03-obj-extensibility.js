/* Object Extensibility 

The extensible attribute of an object specifies whether new properties
can be added to the object or not. Ordinary JavaScript objects are
extensible by default, but you can change that with the functions
described in this section.

The purpose of the extensible attribute is to be able to “lock down”
objects into a known state and prevent outside tampering. */

let Sample = { x : 'eks', y : 7 }; 

// To determine whether an object is extensible
console.log(Object.isExtensible(Sample));

//  To make an object non-extensible
Object.preventExtensions(Sample);
console.log(Object.isExtensible(Sample));

/*
NOTE1 : there is no way to make an object extensible
        again once you have made it non-extensible.

NOTE2 : calling Object.preventExtensions() only affects
        the extensibility of the object itself.
        
        If new properties are added to the PROTOTYPE
        of a non-extensible object, the non-extensible
        object will inherit those new properties. */

