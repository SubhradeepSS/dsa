const assert = require('assert');
const MarioChar = require('../models/MarioChar');

describe('Deleting data', () => {

    let MarioObj;

    beforeEach((done) => {
        MarioObj = new MarioChar({
            name: 'Mario'
        })

        MarioObj.save().then(() => {
            done()
        })
    })

    it('Deleting data from db', (done) => {
        MarioChar.deleteMany({
            name: 'Mario'
        }).then(() => {
            MarioChar.findOne({
                name: 'Mario'
            }).then((res) => {
                assert(res === null)
                done()
            })
        })
    })

})