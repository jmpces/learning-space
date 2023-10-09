# IT'S A LIE
we cannot truly make a custom asynchronous function in javascript (me: or maybe in one javascript runtime?).

```callbacks```, ```promises``` and ```async``` & ```await``` are all just ways to deal with built in asynchronous functions and methods, they provide ways to **run natively asynchronous functions** either **sequentially** or **simultaneously but waiting for each other**.

Those methods and functions are builtin and they run natively on our machine, probably written using another language, (me: or maybe using multiple javascript runtimes communicating with each other?), we can expect them as a separate thread but javascript provides us interface to work with those.

[an SO thread](https://stackoverflow.com/questions/9516900/how-can-i-create-an-asynchronous-function-in-javascript)
If you want to simulate an asynchronous function, you will eventually need to leverage on technology provided natively, such as

- ```setInterval```
- ```setTimeout```
- ```requestAnimationFrame```
- ```XMLHttpRequest```
- ```WebSocket```
- ```Worker```
- Some HTML5 APIs such as the File API, Web Database API
- technologies that support ```onload```
- ... and many others

