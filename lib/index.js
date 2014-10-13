var path = require('path'),
  exec = require('exec'),
  os = require('os'),
  linuxPlayCmd = 'play',
  macPlayCmd = 'afplay',
  listSounds = require(path.join(__dirname, '../lib/list-sounds'));

function noop() {
}

function playSound(path, cb) {
  var cmd = os.type() === 'Darwin' ? macPlayCmd : linuxPlayCmd,
    execCmd = cmd + ' ' + path;
  exec(execCmd, cb || noop);
  //console.log('>', execCmd);
}

module.exports = function (sound) {
  sound = sound || 'belch';
  listSounds(function (err, sounds) {

    var i = 0, found = false;
    while (i < sounds.length) {
      if (sounds[i] === sound) {
        found = true;
        break;
      }
      i++;
    }
    if (found) {
      var soundPath = path.join(__dirname, '../sounds/' + sound + '.mp3');
      playSound(soundPath);
    } else {
      console.log('ERROR: sound "' + sound + '" does not exist');
    }

  });
};