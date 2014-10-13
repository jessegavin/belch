var path = require('path'),
  exec = require('exec'),
  os = require('os'),
  linuxPlayCmd = 'play',
  macPlayCmd = 'afplay';

function noop() {
}

function playSound(path, cb) {
  var cmd = os.type() === 'Darwin' ? macPlayCmd : linuxPlayCmd,
    execCmd = cmd + ' ' + path;
  exec(execCmd, cb || noop);
  console.log('executed:', execCmd);
}

module.exports = function (sound) {
  sound = sound || 'belch';
  var soundPath = path.join(__dirname, '../sounds/' + sound + '.mp3');
  playSound(soundPath);
};