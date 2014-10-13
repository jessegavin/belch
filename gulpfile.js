var gulp = require('gulp'),
  options = {
    paths: {
      lint: [
        './*.js'
      ],
      //felint: [
      //    './src/public/**/*.js'
      //],
      cover: [
        './index.js'
      ],
      test: [
        './test/**/*.js'
      ]
    },
    coverageSettings: {
      thresholds: {
        statements: 100,
        branches: 60,
        lines: 100,
        functions: 100
      }
    }
  };

require('load-common-gulp-tasks')(gulp, options);