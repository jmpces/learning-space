/*
  PROTOTYPE INHERITANCE

  this is how the "class" and "extend" keyword works under the hood
  all of this were used before ES2015 when the "class" and "extend" keywords
  is still not supported existing.
  
*/

/* Creating base class and class members */
function Person(Name,Age,Gender){
  this.Name = Name;
  this.Age = Age;
  this.Gender = Gender;
}

/* Creating base class methods */
Person.prototype.printBasicInfo = function(){
  console.log(`Name         : ${this.Name}`);
  console.log(`Age          : ${this.Age}`);
  console.log(`Gender       : ${this.Gender}`);
}

/* Creating derived class*/
function Teacher(...args){

  // set the inherited base class members
  Person.apply(this, args.slice(0,3));

  // set the derived class member (only available to the derived class)
  this.BoardPasser = args[3];
}

/* Inheriting methods from base class to derived class */
Teacher.prototype = Object.create(Person.prototype);

/* Creating derived class methods (only available for derived class) */
Teacher.prototype.printSpecialInfo = function(){
  this.printBasicInfo();
  console.log(`Board Passer : ${this.BoardPasser}`);
}

let random09 = new Person('James',18,'M');
random09.printBasicInfo();
console.log();

let teacher04 = new Teacher('Nancy',22,'F',true);
teacher04.printBasicInfo();
console.log();

teacher04.printSpecialInfo();