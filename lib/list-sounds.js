var fs = require('fs');
var path = require('path');

module.exports = function(cb) {
  fs.readdir(path.join(__dirname, '../sounds'), function(err, files){
    cb(null, files.map(function(currentVal, i, arr) {
      return path.basename(currentVal, '.mp3');
    }));
  });
};