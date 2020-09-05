const mongoose = require('mongoose');

mongoose.Promise = global.Promise;

before((done) => {
    mongoose.connect('mongodb://127.0.0.1:27017/db')

    mongoose.connection.once('open', () => {
        console.log('Connection established')
        done();
    }).on('error', (error) => {
        console.log('Error:' + error)
    })

})

beforeEach((done) => {
    mongoose.connection.db.dropCollection('MarioChar', () => {
        done()
    })
})