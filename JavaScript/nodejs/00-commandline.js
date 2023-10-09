/* The node command line arguments and environment */
// node --trace-uncaught 00-commandline.js --arg1 --arg2 filename
function main(argc,argv,env) // if structured similar to a C/C++ program
{
  // console.log('command line arguments :',argv,'\n\n');
  // console.log('environment',env);
}
main(process.argv.length,process.argv,process.env);


/* parsing javascript code in command line 
you can use the eval() function in the command line

node --eval '1+5' --print

or

node -p -e '7+8'*/


/*  A node program can ignore Ctrl-C by registering a signal handler function with */
process.on('SIGINT', ()=>{});


/* closing a node runtime programmatically */
// process.exit();


/* If code in your program throws an exception and no catch clause
catches it, the program will print a stack trace and exit. 

If you don’t want these
exceptions to cause your program to completely crash, register a global
handler function that will be invoked instead of crashing:*/
process.setUncaughtExceptionCaptureCallback(e => {
  console.error("Uncaught exception:", e);
});  

console.log('\n\nprocess =\n',process);


/* Promise created by your program is
rejected and there is no .catch() invocation to handle it. As of Node
13, this is not a fatal error that causes your program to exit, but it does
print a verbose error message to the console.

In some future version of Node, unhandled Promise rejections are expected
to become fatal errors. If you do not want unhandled rejections,
to print error messages or terminate your program,
register a global handler function: */
process.on("unhandledRejection", (reason, promise) => {
  // reason is whatever value would have been passed to a .catch() function
  // promise is the Promise object that rejected
});
  