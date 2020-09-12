const assert = require('assert');
const MarioChar = require('../models/MarioChar');

describe('Saving data', () => {
    it('Save data to db', (done) => {
        const MarioObj = new MarioChar({
            name: 'Mario',
            weight: 40
        })

        MarioObj.save().then(() => {
            assert(!(MarioObj.isNew))
            done()
        })
    })
})