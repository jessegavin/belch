#!/usr/bin/env node

var path = require('path');
var program = require('commander');
var belch = require(path.join(__dirname, '../lib/index'));
var listSounds = require(path.join(__dirname, '../lib/list-sounds'));

listSounds(function(err, sounds) {
  program
    .version(require('../package.json').version)
    .option('-s, --sound [type]', 'specify the sound to play [' + sounds.join(',') + ']')
    .parse(process.argv);
  belch(program.sound);
});