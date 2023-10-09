class Person {
  constructor(Name,Age){
    this.Name = Name;
    this.Age  = Age;
  }

  print(){
    console.log(`Name : ${this.Name}`);
    console.log(`Age  : ${this.Age}`);
  }
}

let person = new Person('James',14);
person.print();
// person.printID(); // error

console.log();

class Student extends Person {

  printID(){
    console.log(`ID   : ${this.ID}`);
  }
}

let Micha = new Student('Micha',21);
Micha.print();
Micha.ID = '0838284729843';
Micha.printID();