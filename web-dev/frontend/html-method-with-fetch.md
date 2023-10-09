### HTML Request Methods using JavaScript Fetch API

For more detailed information, access the MDN documentation for **[fetch() API](https://developer.mozilla.org/en-US/docs/Web/API/Fetch_API/Using_Fetch)**.

- **Extracting Responses**
    
    Get the value of a response from a ```fetch()``` call.
    
    ```js
    let response = await fetch('/records');
    let data = await response.json();
    ```

- **Get Request**

    The get request is the same as inputing a URL in the browser, or redirecting to a link or another endpoint.

    It could contain parameter values that will sent in the backend, either supply it with **[Request Query Parameters](../backend/fastify/f03-routing/basics.md)** or just **[Request Parameters](../backend/fastify/f03-routing/basics.md)**.
    
    If not specified, the ```fetch()``` api will use a **GET** request by default.
    ```js
    fecth('/getEndPoint');

- **Post Request**

    The ```/SaveEndPoint``` example is the route end point or action for the **POST** request.

    The **POST** will contain a **Body** content, This request is mainly use when saving data to the backend.

    ```js
    fetch('/SaveEndPoint', {
      headers: {
        'Accept': 'application/json',
        'Content-Type': 'application/json'
      },
      method: 'post',
      body: JSON.stringify({
        "key1": "value1",
        "key2": "value2",
        "key3": 10
      })
    }).then(function (response) {
      response.json().then(function (data) {
        console.log(data);
      });
    }).catch(function (error) {
      console.error(error);
    });
    ```

- **Put Request**

    The ```/UpdateEndPoint``` is the route, end point or action for the **PUT** request.

    The ```/ParametersOrQuery``` are the values that will be used during the **PUT** process in the backend, either supply it with **[Request Query Parameters](../backend/fastify/f03-routing/basics.md)** or just **[Request Parameters](../backend/fastify/f03-routing/basics.md)**.

    The **PUT** request might contain a **Body** content, just like **POST** request but, it is mainly used when updating or editing data in the backend.

    ```js
    fetch('/UpdateEndPoint/ParametersOrQuery', {
      headers: {
        'Accept': 'application/json',
        'Content-Type': 'application/json'
      },
      method: 'put',
      body: JSON.stringify({
        "key1": "value1",
        "key2": "value2",
        "key3": 10
      })
    }).then(function (response) {
      response.json().then(function (data) {
        console.log(data);
      });
    }).catch(function (error) {
      console.error(error);
    });
    ```

- **Delete Request**
    
    The ```/DeleteEndPoint``` is the route, end point or action for the delete request.

    The ```/ParametersOrQuery``` are the values that will be used during the delete process in the backend, either supply it with **[Request Query Parameters](../backend/fastify/f03-routing/basics.md)** or just **[Request Parameters](../backend/fastify/f03-routing/basics.md)**.

    Just like the **GET** request, the **DELETE** request don't have a body.

    ```js
    fetch('/DeleteEndPoint/ParametersOrQuery', {
      headers: {
        'Accept': 'application/json',
        'Content-Type': 'application/json'
      },
      method: 'delete'
    }).then(function (response) {
      response.json().then(function (data) {
        console.log(data);
      });
    }).catch(function (error) {
      console.error(error);
    });
    ```

- **An Example of Post Request Data**
    ```js
    fetch('/data/transactions', {
      headers: {
        'Accept': 'application/json',
        'Content-Type': 'application/json'
      },
      method: 'post',
      body: JSON.stringify({
        "buydate": "2022-05-13T06:17:59.751Z",
        "itemname": "From Browser",
        "class": "Test Data",
        "price": 10,
        "quantity": 2
      })
    }).then(function (response) {
      response.json().then(function (data) {
        console.log(data);
      });
    }).catch(function (error) {
      console.error(error);
    });
    ```
