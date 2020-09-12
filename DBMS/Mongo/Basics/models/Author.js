const mongoose = require('mongoose')

const BookSchema = mongoose.Schema({
    title: String,
    pages: Number
})

const AuthorSchema = mongoose.Schema({
    name: String,
    age: Number,
    books: [BookSchema]
})

const Author = mongoose.model('Author', AuthorSchema);

module.exports = Author;