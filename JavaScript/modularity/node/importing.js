/*-----------------------------------------------------------------*
  If you want to import a system module built in to Node or a module
  that you have installed on your system via a package manager, then
  you simply use the unqualified name of the module, without any “/”
  characters that would turn it into a filesystem path:
*-----------------------------------------------------------------*/

// These modules are built in to Node
const fs = require("fs");     // The built-in filesystem module
const http = require("http"); // The built-in HTTP module

// The Express HTTP server framework is a third-party module.
// It is not part of Node but has been installed locally
// const express = require("express");


/*-----------------------------------------------------------------*
  When you want to import a module of your own code, the module name
  should be the path to the file that contains that code, relative
  to the current module’s file. It is legal to use absolute paths
  that begin with a / character, but typically, when importing
  modules that are part of your own program, the module names will
  begin with ./ or sometimes ../ to indicate that they are relative
  to the current directory or the parent directory. For example:
*-----------------------------------------------------------------*/

// node import
const { stddev, stats, mean, Collection } = require('./exporting.js');

// ES6 import
// import { mean, stddev, stats, Collection } from '/exporting.mjs';


console.log('import function mean   = ',mean([1,2,3,4,5]));
console.log('import function stddev = ',stddev([1,2,3,4,5]));

console.log('\nimport object stats mean method   = ',stats.mean([1,2,3,4,5]));
console.log('import object stats stddev method = ',stats.stddev([1,2,3,4,5]));

let collectibles = new Collection([2,4,6,8,10]);

console.log('\ndata : ',collectibles.data);
console.log('sum = ',collectibles.sum());
console.log('ave = ',collectibles.average());