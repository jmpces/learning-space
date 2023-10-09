/**int 64 matrix */
class MatrixInt64{
  constructor(width,height){
    this.width = width;
    this.height = height;
    this.arr = new BigInt64Array(width*height);
  }

  toString(){
    let str = '';
    for(let i=0; i<this.height; ++i){
      for(let j=0; j<this.width; ++j){
        str += `${this.arr[i*this.width+j]} `;
      }
      str += '\n';
    }
    return str;
  }

  static from2D(Array2D)
  {
    let arr = new MatrixInt64(Array2D[0].length,Array2D.length);

    for(let i=0; i<arr.height; ++i){
      for(let j=0; j<arr.width; ++j){
        arr.arr[i*arr.width+j] = BigInt(Array2D[i][j]);
      }
    }
    return arr;
  }
}

module.exports = { MatrixInt64 };