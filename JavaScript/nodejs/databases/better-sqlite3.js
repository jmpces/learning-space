/* basic use of "better-sqlite3"        
                                        
   Install:                             
     npm install better-sqlite3
*/

const sqlite3 = require('better-sqlite3');

/// ======================= create database =======================

const db = sqlite3('data.db');

/// ======================= create table =======================

// our table name is "inventory"
try{
  db.exec(`
    CREATE TABLE inventory (
      itemname TEXT PRIMARY KEY NOT NULL,
      class TEXT NOT NULL,
      price REAL NOT NULL,
      quantity INTEGER NOT NULL
    )`
  );
}
catch(err) {
  ErrorHandler(err,'CREATE TABLE');
}

/// ======================= insert row =======================

try {
  const Insert = db.prepare(
    `INSERT INTO inventory (itemname, class, price, quantity) VALUES (?, ?, ?, ?)`
  );

  Insert.run('T-Shirt','Uppers',100.54,500);
}
catch(err) {
  ErrorHandler(err,'INSERT INTO');
}

/// ======================= edit row =======================

try {
  const Update = db.prepare(`
    UPDATE inventory SET
      itemname = ?,
      class = ?,
      price = ?,
      quantity = ?
    WHERE
      itemname = ?`
  );

  console.log(
    'Update Result : ',
    Update.run('Blue Short', 'Unders',56.3, 700, 'T-Shirt')
  );
}
catch(err) {
  ErrorHandler(err,'UPDATE SET WHERE');
}

/// ======================= read all row ======================= 

// read all row of table
try {
  const Read = db.prepare(`SELECT * FROM inventory`);

  console.log('\nAll table Rows :');
  for(let row of Read.iterate()) {
    console.log(row);
  }
}
catch(err) {
  ErrorHandler(err,'SELECT FROM');
}

// read with condition row
try {
  const SpecificRead = db.prepare(`SELECT * FROM inventory WHERE itemname = ?`);

  console.log('\nFiltered Rows :');
  for(let row of SpecificRead.iterate('T-Shirt')) {
    console.log(row);
  }
}
catch(err) {
  ErrorHandler(err,'SELECT FROM WHERE');
}

/// ======================= delete a row =======================
try {
  const Delete = db.prepare(`DELETE FROM inventory WHERE itemname = ?`);
  console.log(
    '\nDelete Result : ',
    Delete.run('T-Shirt')
  );
}
catch(err) {
  ErrorHandler(err,'DELETE FROM');
}

/// ======================= drop table =======================
try {
  db.exec(`DROP TABLE inventory`);
}
catch(err) {
  ErrorHandler(err,'DROP TABLE');
}

/// ======================= error handler =======================

function ErrorHandler(err, sqlCommand) {
  console.error(
    `\nERROR : [${sqlCommand}]
      message : ${err.message},
      code    : ${err.code}\n`
  );
}
