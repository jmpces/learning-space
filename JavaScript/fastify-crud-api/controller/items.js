const { v4:uuidv4 } = require('uuid');
let items = require('../data');

const getAllItems = (request, reply) => {
  reply.send(items);
};

const getSingleItem = (request, reply) => {
  const {id} = request.params;
  const item = items.find(item => item.id === id);
  reply.send(item);
};

const addItem = (request, reply) => {
  const { name } = request.body;
  const item = {
    id: uuidv4(),
    name 
  }

  items = [...items, item];

  reply.code(201).send(item);
}

const deleteItem = (request, reply) => {
  const { id } = request.params;

  items = items.filter(item => item.id !== id);

  reply.send({message: `Items ${id} has been removed`});
}

const updateItem = (request, reply) => {
  const { id } = request.params;
  const { name } = request.body;

  items = items.map(item => (item.id === id ? {id, name} : item));

  const item = items.find(item => item.id === id);

  reply.send(item);
}

module.exports = {
  getAllItems,
  getSingleItem,
  addItem,
  deleteItem,
  updateItem
};