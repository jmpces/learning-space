## Fastify

A minimalist JavaScript web framework use to build fast web applications and APIs.

### Installing Fastify
```cmd
npm init
npm install fastify --save
```

### Setting Up
```js
// ESM import
import Fastify from 'fastify';
const fastify = Fastify({logger:true});

// CommonJS import
const fastify = require('fastify')({logger:true});
```

### Declaring a Route
```js
// callback way
fastify.get('/', function (request, reply) {
  reply.send({ hello: 'world' })
});

// async way
fastify.get('/', async (request, reply) => {
  return { hello: 'world' }
});
```

### Listening to Port / Running the Server
```js
// callback way
fastify.listen({ port: 3000, host:'::' }, function (err, address) {
  if (err) {
    fastify.log.error(err);
    process.exit(1);
  }
  // Server is now listening on ${address}
});

// async way
const start = async () => {
  try {
    await fastify.listen({ port: 3000 });
  } catch (err) {
    fastify.log.error(err);
    process.exit(1);
  }
}

start();
```

### Note :

This things can change in the future, if these examples did not work, please see the official fastify documentation