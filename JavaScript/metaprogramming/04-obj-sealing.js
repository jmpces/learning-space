/* Object.seal() works like Object.preventExtensions(). 

but in addition to making the object non-extensible,
it also makes all of the own properties of that object
non-configurable.

This means that new properties cannot be added to the object,
and existing properties cannot be deleted or configured.

Existing properties that are writable can still be set,
however. There is no way to unseal a sealed object.
You can use Object.isSealed() to determine whether an
object is sealed.


Object.freeze() locks objects down even more tightly.
In addition to making the object non-extensible and its
properties non-configurable,

it also makes all of the object’s
own data properties read-only. (If the object has accessor
properties with setter methods, these are not affected and can
still be invoked by assignment to the property.) Use
Object.isFrozen() to determine if an object is frozen.
*/