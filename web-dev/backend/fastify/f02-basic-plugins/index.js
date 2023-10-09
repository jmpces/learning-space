const fastify = require('fastify')({logger:true});
const fastifyStatic = require('@fastify/static');
const fastifyFormBody = require('@fastify/formbody');
const path = require('path');

const PORT = process.env.PORT || 8080;

fastify.register(fastifyFormBody);

fastify.register(fastifyStatic, {
  root: path.join(__dirname, '/')
});

fastify.get('/', (req,res)=>{
  res.sendFile('post.html');
});

fastify.post('/data',(req,res)=>{
  let BodyData = req.body;
  console.log(BodyData);
  res.send(req.body);
});

const start = async ()=> {
  try{
    await fastify.listen({port:PORT});
  } catch(err) {
    fastify.log.error(err);
    process.exit(1);  
  }
}

start();