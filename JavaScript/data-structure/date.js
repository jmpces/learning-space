let timestamp = Date.now();
 // The current time as a timestamp (a number).
let now = new Date();
 // The current time as a Dateobject.
let ms = now.getTime();
 // Convert to a millisecond timestamp.
let iso = now.toISOString();
 // Convert to a string in standard format.

console.log(timestamp);
console.log(now);
console.log(ms);
console.log(iso);