# Request Contents

- **Request Query Parameters**

    Get data from client via html Request Query Parameters, this can be use in any end points, and it's data is accessible inside the ```request.query``` object of fastify routes.

    ```js
    app.get('/query',(req,res)=>{
      console.log(req.query);
      res.send(req.query);
    });
    ```

    Using this route, we will be able to pass query parameters in the URL to the fastify ```/query``` endpoint declared above; for example from the browser we input:

    ```url
    localhost:8080/query?name=bob&age=18
    ```

    Parts of the query parameter in the URL.

    - ```?``` starts the query in the URL.
    - ```=``` creates a key pair value ```KEY=VALUE```.
    - ```&``` to add another key-pair value, use to supply multiple key-pair values in one query URL.

    Then we get the query keypair values on the backend:

    ```json
    {
      "name" : "bob",
      "age" : "18"
    }
    ```

- **Request Parameter**

    Get data from client via html Request Parameters, this can only be used on specifically defined end points, and it's data is accessible inside the ```request.params``` object of fastify routes.

    ```js
    app.get('/parameter/:startday-:endday/:time',(req,res)=>{
      console.log(req.params);
      res.send(req.params);
    });
    ```

    Using the route above, we will be able to pass parameters in the URL to the fastify end point ```/parameter```; for example from the browser we input:

    ```url
    localhost:8080/parameter/mon-fri/8am
    ```

    Here we assign values to the parameters, the ```startday``` was given the value ```mon```, ```endday``` was given the value ```fri```, and ```time``` given the value ```8am```.

    Using the ```req.params``` object we will be able to access the key pari value at the backend:

    ```json
    {
      "startday" : "mon",
      "endday" : "fri",
      "time" : "8am"
    }
    ```

    **Request Body**

    The ```req.body``` will contain the key-pair values of HTML methods like ```POST``` and ```PUT``` requests, values from frontend ```fetch()``` calls or HTML form submissions.