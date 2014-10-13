#!/usr/bin/env node

var program = require('commander');
var belch = require('../lib/index');

program
  .version('0.0.1')
  .option('-s, --sound [type]', 'specify the sound to play')
  .parse(process.argv);

if (program.sound) {
  belch(program.sound);
} else {
  belch('belch');
}
