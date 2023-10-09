## Two ways to import a node module

- **Common JS** - this is the default and the original way to import modules
in a node program
    - uses the ```require()``` to import modules
    - uses ```module.exports``` property to export module objects/variables
    - it can also use the ```exports``` (note the 's') to export module objects/variables
    - what nodejs uses by default

- ES6 JS - this is added in node.js v13 to support ES6 syntax way of
importing ES6 modules
    - uses the ```import``` to import modules
    - uses the ```export``` to export modul object/variables
    - can be used on javascript main.js program with javascript module files that has ```.mjs``` as their extension

The two module systems are not fully compatible, so this is somewhat tricky to do.

Node needs to know—before it loads a module—whether that
module will be using ```require()``` and ```module.exports``` or if it
will be using ```import``` and ```export```.

-----

## Caveat
When Node loads a file of JavaScript code as a CommonJS module, it automatically defines the
require() function along with identifiers exports and module,
and it does not enable the import and export keywords. On the
other hand, when Node loads a file of code as an ES6 module, it must
enable the import and export declarations, and it must not define
extra identifiers like require, module, and exports.

-----

## using package.json to enable either CommonJS or ES6JS way of modularity

For files that _do not have an explicit .mjs or .cjs extension_, Node looks for a file named **package.json** in the same directory as the file and then in each of the containing directories.

Once the nearest **package.json** file is found, Node checks for a top-level type ***property*** in the **JSON object**.

- If the value of the ***type property*** is **“module”**, then Node loads
the file as an **ES6 module**.

- If the value of that ***type property*** is **“commonjs”**, then Node loads the file as a **CommonJS module**.

Note that you do not need to have a package.json file to run Node programs:

- when **no such file is found** (or when the file is **found** but it does **not have** a type property), Node **defaults** to using **CommonJS modules**.

This package.json trick only becomes necessary if you want to use ES6 modules with Node and do not want to use the .mjs file extension.

-----

## ES6 module can load CommonJS module, but not the other way around

Because there is an enormous amount of existing Node code written
using CommonJS module format, Node allows ES6 modules to load
CommonJS modules using the import keyword. The reverse is not
true, however: a CommonJS module cannot use require() to load
an ES6 module.
