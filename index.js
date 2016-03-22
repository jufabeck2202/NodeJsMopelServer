var express = require('express');
app = express();
var http = require('http').Server(app);
io= require("socket.io").listen(http);
var SerialPort = require("serialport").SerialPort
var serialPort = new SerialPort("/dev/ttyACM0", { baudrate: 115200 });
var valueLeft,valueRight


http.listen(8019);
app.use(express.static("public"));

io.on('connection', function (socket) {
  
  socket.on('directionLeft', function (data) {
    valueLeft=data.value;
    io.sockets.emit('directionLeft', {value: valueLeft});
    serialPort.write(JSON.stringify({directionLeft:valueLeft}));
  });
  socket.on('directionRight', function (data) {
    valueRight=data.value;
    io.sockets.emit('directionRight', {value: valueRight});
    serialPort.write(JSON.stringify({directionRight:valueRight}));
  });
});
