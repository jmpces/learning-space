// NOTE: in classes unlike in objects-literals we don't
//       put comma after every property definition

class User {

  /** Constructor */
  constructor(Name,Email,Age){
    this.Name = Name;
    this.Email    = Email;
    this.Age      = Age
  }

  printName(){
    console.log(`Name  : ${this.Name}`);
  }

  printEmail = function(){
    console.log(`Email : ${this.Email}`);
  }

  printAge = () =>{
    console.log(`Age   : ${this.Age}`);
  }
}

let firstUser = new User('Jammie','jammie@gmail.com',22);
firstUser.printName();
firstUser.printEmail();
firstUser.printAge();