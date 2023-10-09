// push
// pop

class Node{
  constructor(Value){
    this.Front = null;
    this.Back = null;
    this.Value = Value;
  }
}

class Queue{
  constructor(){
    // this.Start = null;
    // this.End = null;
    this.Size = 0;
  }

  push(Value){
    let NewNode = new Node(Value);
    if(this.Size===0){
      this.Start = NewNode;
      this.End = NewNode;
      this.Start.Back = this.End;
      this.End.Front = this.Start;
    }
    else{
      NewNode.Front = this.End;
      this.End.Back = NewNode;
      this.End = NewNode;
    }
    this.Size++;
  }

  pop(){
    let Value;

    if(this.Size===0){
      return 'Queue is Empty';
    }
    else{
      Value = this.Start.Value;
      this.Start = this.Start.Back;
      this.Size--;
    }
    return Value;
  }
}

let Line = new Queue();

Line.push('Marco');
Line.push('Jeanne');
Line.push('Micha');
Line.push('Ela');
Line.push('Abby');

console.log(Line.pop());
console.log(Line.pop());
console.log(Line.pop());
console.log(Line.pop());
console.log(Line.pop());

console.log(Line.pop());
console.log(Line.pop());