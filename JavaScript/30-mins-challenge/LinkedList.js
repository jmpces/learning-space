'use strict'

class Node{
  constructor(Value=null)
  {
    this.Value = Value;
    this.Prev = null;
    this.Next = null;
  }
}

class LinkedList{
  constructor(){
    this.Head = null;
    this.Tail = null;
    this.Size = 0;
  }

  add_back(Value){
    // case 1 : the list is empty
    if(this.Size === 0){
      let NewNode = new Node(Value);
      this.Head = NewNode;
      this.Tail = NewNode;
      this.Head.Next = this.Tail;
      this.Tail.Prev = this.Head;
    }
    // case 2 : not empty
    else{
      let NewNode = new Node(Value);
      NewNode.Prev = this.Tail;
      this.Tail.Next = NewNode;
      this.Tail = NewNode;
    }
    this.Size++;
  }

  add_front(Value){
    // case 1 : the list is empty
    if(this.Size === 0){
      let NewNode = new Node(Value);
      this.Head = NewNode;
      this.Tail = NewNode;
      this.Head.Next = this.Tail;
      this.Tail.Prev = this.Head;
    }
    // case 2 : not empty
    else{
      let NewNode = new Node(Value);
      NewNode.Next = this.Head;
      this.Head.Prev = NewNode;
      this.Head = NewNode;
    }
    this.Size++;
  }

  add_at(Value, Index){
    // case 1 : index is greater than size
    if(Index>=this.Size){
      throw Error('Index Overflow')
    }
    // case 2 : the list is empty but index is zero
    if(this.Size===0 && Index==0){
      let NewNode = new Node(Value);
      this.Head = NewNode;
      this.Tail = NewNode;
      this.Head.Next = this.Tail;
      this.Tail.Prev = this.Head;
    }
    // case 2 : not empty and 
    else{
      let Iterator = this.Head;

      while(Index--){
        Iterator = Iterator.Next;
      }

      let NewNode = new Node(Value);
      
      Iterator.Prev.Next = NewNode;
      NewNode.Prev = Iterator.Prev;
      NewNode.Next = Iterator;
    }
    this.Size++;
  }

  print(){
    let Iterator = this.Head;
    while(Iterator!==null){
      console.log(Iterator.Value);
      Iterator = Iterator.Next;
    }
    // if(this.Size===0) return;
    // else{
    //   let Iterator = this.Head;
    //   for(let i=0; i<this.Size; ++i){
    //     console.log(Iterator.Value);
    //     Iterator = Iterator.Next;
    //   }
    // }
  }
}

let List = new LinkedList();

List.add_back(2);
List.add_back(4);
List.add_back(6);
List.add_back(9);
List.add_front(-5);
List.add_front(-8);
List.add_at('here',4);

List.print();

console.log(List);