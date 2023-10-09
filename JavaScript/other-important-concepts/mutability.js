let object1 = {value: 10};
let object2 = object1;
let object3 = {value: 10};

console.log(object1 == object2); // true
console.log(object1 == object3); // false

object1.value = 15;
console.log(object1.value);
console.log(object2.value);
console.log(object3.value);