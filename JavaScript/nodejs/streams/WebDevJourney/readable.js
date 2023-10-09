const { Readable } = require('stream');

const Fruits = ['apple', 'mango', 'orange', 'grapes', 'melon', 'pineapple'];

// classes and modules that provides readable streams extends using the Readable class 
class StreamFromArray extends Readable {

  constructor(array){

    /* in super we are calling the constructor of the 'Readable' class
    and by default it's encoding type is in "HEX".
    
    though in our example below we use the "UTF8" encoding. */
    super( {encoding: 'utf8'} );
    this.array = array;
    this.index = 0;
  }

  _read() {
    if(this.index < this.array.length) {
      let stream_buffer = this.array[this.index++];
      this.push(stream_buffer);
    }
    else{
      this.push(null);
    }
  }
}

const FruitStream = new StreamFromArray(Fruits);

FruitStream.on('data', (stream_buffer) => console.log(stream_buffer));
FruitStream.on('end', () => console.log('done!!!'));