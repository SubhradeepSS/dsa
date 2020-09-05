const assert = require('assert');
const MarioChar = require('../models/MarioChar');

describe('Retrieving data', () => {

    let MarioObj;

    beforeEach((done) => {
        MarioObj = new MarioChar({
            name: 'Mario',
            weight: 40
        })

        MarioObj.save().then(() => {
            done()
        })
    })

    it('Retrieves a data from db', (done) => {
        MarioChar.findOne({
            name: 'Mario',
            weight: 40
        }).then((res) => {
            assert(res.name === 'Mario' && res.weight ===  40)
            done()
        })
    })

    it('Retrieves a data from db by id', (done) => {
        MarioChar.findOne({
            _id: MarioObj._id
        }).then((res) => {
            assert(res._id.toString() === MarioObj._id.toString())
            done()
        })
    })
})