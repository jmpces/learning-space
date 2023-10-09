const app = require('fastify')({logger:true});

const PORT = process.env.PORT || 8080;

// endpoint + query
// localhost:8080/data?key=value&key2=val2
// use the ? to start the query
// use & when dealing with multiple keypar value
// use = to asign key pair value
// example:
//     localhost:8080/query?name=bob&age=18
app.get('/query',(req,res)=>{
  console.log(req.query);
  res.send(req.query);
});

// use : to asign a value to a key
// example:
//      localhost:8080/parameter/mon-fri/8am
app.get('/parameter/:startday-:endday/:time',(req,res)=>{
  console.log(req.params);
  res.send(req.params);
});

const start = async ()=> {
  try{
    await app.listen({port: PORT});
  } catch(err) {
    app.log.error(err);
    process.exit(1);
  }
}

start();