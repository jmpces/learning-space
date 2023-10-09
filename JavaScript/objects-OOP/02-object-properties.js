/** Properties are like members and methods */

/* just a helper function */
function ObjectStatus(blockName, ObjectDisplay){
  console.log(`\n============ ${blockName} ============`);
  console.log(ObjectDisplay);
}

let runtimeComputedKey = (KeyLabel)=> {
  let signature = "9usy";
  return signature + KeyLabel + signature;
}

/* an empty object */
let emptyObject = {

}
ObjectStatus('created an empty object',emptyObject);


// Adding Properties : method 1
emptyObject.new_property = "I am the first property added to this object";


// Adding Properties : method 2
emptyObject['new property 2'] = ['The second property to be added', {age: 5}];

// Adding A runtime computed property
emptyObject[runtimeComputedKey("MyKey")] = 'My key is not a literal but computed at runtime';

// Adding A property that binds to a function
emptyObject.display = function(){
  console.log(`property 1: ${this.new_property}`);
  console.log(`property 2: ${this[`new property 2`][0]}`);
}
ObjectStatus('added properties',emptyObject);

/* Accessing Properties */
console.log('\n============ Accessing Properties ============');
console.log('property 1 = ',emptyObject.new_property);
console.log('property 2 = ',emptyObject['new property 2'][1].age);

/* Calling the object property that is binded to a function */
console.log('\n============ Calling Properties binded to function ============');
emptyObject.display();

/* Deleting Properties */
delete emptyObject['new property 2'];
ObjectStatus('deleted property 2',emptyObject);

/* Test Properties using 'in' */
console.log('\n============ Test Properties : using "in" ============');
/* the in operator returns true if the property in question is an OWN or INHERITED property */
console.log('new_property   : ','new_property' in emptyObject);
console.log('new property 2 : ','new property 2' in emptyObject);
console.log('toString       : ','toString' in emptyObject);

/* Test Properties using 'hasOwnProperty()' */
console.log('\n============ Test Properties : using "hasOwnProperty()" ============');
/* the hasOwnProperty() function returns true if the property in question is an OWN property*/
console.log('new_property   : ',emptyObject.hasOwnProperty('new_property'));
console.log('new property 2 : ',emptyObject.hasOwnProperty('new property 2'));
console.log('toString       : ',emptyObject.hasOwnProperty('toString'));

/* Test Properties using 'propertyIsEnumerable()' */
console.log('\n============ Test Properties : using "propertyIsEnumerable()" ============');
/*  the propertyIsEnumerable() function returns true if the property
    in question is an OWN property and is enumerable
    
    properties created by normal JavaScript code are enumerable
    unless you set it as not-enumerable*/
console.log('new_property   : ',emptyObject.propertyIsEnumerable('new_property'));
console.log('new property 2 : ',emptyObject.propertyIsEnumerable('new property 2'));
console.log('toString       : ',emptyObject.propertyIsEnumerable('toString'));

/* Converting Objects to string in JSON format */
let JsonObjectString = JSON.stringify(emptyObject);
ObjectStatus('Object to String in JSON format',emptyObject);

/* Converting string in JSON format to Object literals */
let ObjectLiteral = JSON.parse(JsonObjectString);
ObjectStatus('String in JSON format to Object literal',ObjectLiteral);
