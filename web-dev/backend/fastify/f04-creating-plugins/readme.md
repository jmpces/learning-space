# Fastify Plugins

In fastify everything is a plugin, a route can be a plugin, an object can
be a plugin, a handler can be a plugin and etc. Almost everything can ba a
plugin in fastify.

## Fastify Context/Scope

In fastify we have something we call a fastify context or you can call it
a scope. It is a function that takes a fastify instance and an options as
its parameter.

- **fastify context - callback form**
  ```js
  function(fastify, options, done) {
    // code goes here...
    done();
  }
  ```

- **fastify context - async form**
  ```js
  async function(fastify, options) {
    // code goes here...
    return;
  }
  ```

- **Important definitions to remember**

  - **`fastify instance`** is the first parameter passed in the example functions above.
  - **`fastify context/scope`** is the function body ```{}``` itself.
  - **`fastify plugin`** are anything that will be added inside the **`fastify
  context/scope`**, mostly through `fastify.decorate()`, `fastify.decorateRequest()`, and `fastify.decorateReply()` *(but not limited to)*.

## Register

The ```register()``` method in fastify enables you to create a new fastify
context or scope.

```js
fastify.register(function(fastify, options, done) {
  // plugins
});

// or

fastify.register(require('./your-plugin'));

// or 

fastify.register(require('./your-plugin'), { options });
```

- **importing plugins**

  Required plugins (plugin context/scope from another ```.js``` file) must expose a
  single function with the following signature.

  ```js
  // for callback versions
  module.exports = function (fastify, options, done) {
    done(); // after all plugins, the done function should be called
  }
  ```

- **Async style note**

  We can call the ```return``` keyword after all the plugins is declared or if
  you have some crazy logic in your plugin context/scope, if not the
  ```return``` keyword can sometimes be ommited.

  ```js
  async function(fastify, options) {
    // plugins goes here
  }
  ```

- **The `options` parameter**

  If you have been wondering why does the functions passed into the
  `register` method has a second argument called `options`?

  ```js
  function(fastify, options, done);
  ```

  and then the `register()` method itself has an `options` parameter?

  The answer to that question is any objects passed to the `register()`s
  second parameter, is also passed to the second parameter of the **fastify
  function context** used in the register (the first parameter), example:

  ```js
  fastify.register(

    // first parameter of register
    function(instance, options, done) {
      console.log('Options',options);
      done();
    },

    // second parameter of register
    {
      name:'micha'
    }
  );
  ```

  output:
  ```
  Options { name: 'micha' }
  ```
  You might now realize that this options parameter can be use to set some
  logics inside the plugins scope.

## Decorators

- **Decorate Format**

  We can add properties in the `fastify instance` be it; a function, an array,
  or an object. We can do this using the `fastify.decorate()` method where its
  first parameter is a `String` which will be the name of the new property and
  a second parameter where it could be of any type.

  ```js
  decorate(name, value, [dependencies])
  ```
  
  **Decorate Example**

  ```js
  async function(fastify, options) {

    // adding a number property
    fastify.decorate('luckyNumber', 777);

    // adding an object property
    fastify.decorate('coordinates', {x:5, y:3});

    // adding a method property
    fastify.decorate('greetMsg', function(name) {
      return `Hello ${name}, welcome!`;
    });

    // using the plugins in a route
    fastify.get('/', function(request, reply) {
      reply.send({
        luckyNumber : fastify.luckyNumber,
        coordinates : fastify.coordinates,
        greetings : fastify.greetMsg('Kimi No Nawa')
      });
    });
  }
  ```
  
- **Decorating fastify's `request` and `reply` object**

  Instead of decorating the fastify instance, we can directly decorate the
  **`reply`** and **`request`** objects.

  ```js
  decorateReply(name, value, [dependencies])
  decorateRequest(name, value, [dependencies])
  ```
  > **Note**
  
  Always remember that if the property that you want to add is a method or a
  utility, and it needs access to the **`request`** and **`reply`** object,
  
  in this case the function needed as a second parameter should be defined using
  the **`function`** keyword, not by an **`arrow function expression`**.
  
  This is needed so that the **`request`** and **`reply`** object
  can accessed using the **`this`** keyword.
  
  > *Warning*
  
  Do not pass a reference type (Objects) to the 2nd parameter of
  `decorateRequest` and `decorateReply`.
  
  ```js
  // Don't do this
  fastify.decorateRequest('foo', { bar: 'fizz'})
  ```
  
  In this example, the reference of the object is shared with all the requests:
  **any mutation will impact all requests, potentially creating security
  vulnerabilities or memory leaks**.
  
  *Do this instead*
  
  ```js
  async function myPlugin (fastify) {
  
    fastify.decorateRequest('foo', null);
    
    fastify.addHook('onRequest', async (req, reply) => {
      req.foo = { bar: 42 }
    });
  }
  ```
  
  Instead of defining the value of the property in `request` object,
  we just declare it's value then set it's value using
  `addHook('onRequest', async function(req, rep) {});`
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  






