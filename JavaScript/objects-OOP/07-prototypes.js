function Person(Name,Age){
  this.Name = Name;
  this.Age  = Age;
  this.Alive = true;
}

Person.prototype.status = function(){
  console.log(`Name  : ${this.Name}`);
  console.log(`Age   : ${this.Age}`);
  console.log(`Alive : ${this.Alive}`);
}

let RandomIndividual = new Person('Alice',1029);

RandomIndividual.status();