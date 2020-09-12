const mongoose = require('mongoose')

const MarioCharSchema = mongoose.Schema({
    name: String,
    weight: Number
})

const MarioChar = mongoose.model('MarioChar', MarioCharSchema);

module.exports = MarioChar;