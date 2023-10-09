const { Readable } = require('stream');

const Fruits = ['apple', 'mango', 'orange', 'grapes', 'melon', 'pineapple'];

class StreamFromArray extends Readable {

  constructor(array){
    // Opbejct Mode true
    super( {objectMode: true} );
    this.array = array;
    this.index = 0;
  }

  _read() {
    if(this.index < this.array.length) {
      let stream_buffer = {
        data: this.array[this.index],
        index: this.index++
      }
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