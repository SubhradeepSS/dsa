const assert = require('assert');
const Author = require('../models/Author');

describe('Nested object Test', () => {

    it('Testing nested objects', (done) => {
        const author = new Author({
            name:"Tagore",
            age: 50,
            books: [{
                title: 'Title',
                pages: 100
            }]
        })
        author.save().then(() => {
            Author.findOne({name: 'Tagore'})
            .then((res) => {
                assert(res.books.length === 1) 
                done()
            })
        })
    })

})