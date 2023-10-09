const fastify = require('fastify')({logger:true});

const PORT = process.env.PORT || 8080;

fastify.register(require('fastify-swagger'), {
  exposeRoute: true,
  routePrefix: '/docs',
  swagger: {
    info: { title: 'fastify-api' }
  }
});

fastify.register(require('./routes/items'));

const start = async () => {
  try{
    await fastify.listen(PORT);
  }
  catch(err) {
    fastify.log.error(err);
    process.exit(1);
  }
}
start();