const { getAllItems, getSingleItem, addItem, deleteItem, updateItem } = require('../controller/items');

// Item schema
const Item = {
  type: 'object',
  properties: {
    id: { type: 'string' },
    name: { type: 'string' }
  }
}

// Options are objetcs that format what to be return from a route
const getAllItemsOption = {
  schema: {
    response: {
      200: {
        type: 'array',
        items: Item
      }
    }
  },
  handler: getAllItems
}

const getSingleItemOption = {
  schema: {
    response: {
      200: Item
    }
  },
  handler: getSingleItem
}

const postItemOption = {
  schema: {
    body: {
      type: 'object',
      required: ['name'],
      properties: {
        name: { type: 'string' }
      }
    },
    response: {
      201: Item
    }
  },
  handler: addItem
}

const deleteItemOption = {
  schema: {
    response: {
      200: {
        type: 'object',
        properties: {
          message: { type: 'string'}
        }
      }
    }
  },
  handler: deleteItem
}

const updateItemOption = {
  schema: {
    response: {
      200: Item
    }
  },
  handler: updateItem
}

async function itemRoutes(fastify, options) {

  // get all items
  fastify.get('/items', getAllItemsOption);

  // get single item
  fastify.get('/items/:id', getSingleItemOption);

  // add item
  fastify.post('/items', postItemOption);

  // delete item
  fastify.delete('/items/:id', deleteItemOption);

  // update item
  fastify.put('/items/:id', updateItemOption);
}

module.exports = itemRoutes;