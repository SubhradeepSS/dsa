const assert = require('assert');
const MarioChar = require('../models/MarioChar');

describe('Updating data', () => {

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

    it('Update data from db', (done) => {
        MarioChar.updateMany({name: 'Mario'},{name: 'Mongo'})
        .then(() => {
            MarioChar.findOne({_id: MarioObj._id})
            .then((res) => {
                assert(res.name === 'Mongo')
                done()
            })
        })
    })

    it('Increment weight by 1 for all', (done) => {
        MarioChar.updateMany({}, { $inc: { weight: 1 } })
        .then(() => {
            MarioChar.findOne({name: 'Mario'})
            .then(res => {
                assert(res.weight === 41)
                done()
            })
        })
    })

})