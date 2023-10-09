## Fastfy FormBody
Enables parsing contents from static html like for example; when submit form data.

- **Install**
    ```
    npm install @fastify/formbody
    ```

- **Sample**
    ```js
    // register by conventional way
    const fastifyFormBody = require('@fastify/formbody');
    fastify.register(fastifyFormBody);

    // register directly
    fastify.register(require('@fastify/formbody'));
    ```

## Fastify Static

Enables serving static files, like html, css, and javascript to clients.

- **Install**
    ```
    npm install @fastify/static
    ```

- **Sample**
    ```js
    // import fastify static
    const fastifyStatic = require('@fastify/static');
    const path = require('path');

    // register the fastify static plugin.
    // this also sets a root path where,
    // all the static files is located
    fastify.register(fastifyStatic, {
      root: path.join(__dirname, '/static-folder')
    });

    // serve the file to the clients
    fastify.get('/', (req,res)=>{
      res.sendFile('static-form.html');
    });
    ```
