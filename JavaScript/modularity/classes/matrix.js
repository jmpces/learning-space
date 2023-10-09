let { MatrixInt64 } = require('./mtx.js');

let test = new MatrixInt64(1,1);
let arr = MatrixInt64.from2D([[1,2,3,4,5],[6,7,8,9,0]]);

console.log(arr.toString());