fetch('http://localhost:8080/items', {
    headers: {
        'Accept': 'application/json',
        'Content-Type': 'application/json'
    },
    method: 'post',
    body: JSON.stringify({
        name : "From Browser"
    })
}).then(function (response) {
    response.json().then(function (data) {
        console.log(data);
    });
}).catch(function (error) {
    console.error(error);
});
