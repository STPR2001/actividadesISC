const { SerialPort } = require("serialport");
const { ReadlineParser } = require("@serialport/parser-readline");

const port = new SerialPort({
  path: "COM1", //CAMBIAR ESTO SI USAMOS LINUX
  baudRate: 9600,
});

const parser = port.pipe(new ReadlineParser({ delimiter: "\r\n" }));

module.exports = function (io) {
  parser.on("data", function (data) {
    console.log("Data:", data);
    if (data == "Modo normal ON") {
      io.sockets.emit("modoOperacion", 1);
    } else if (data == "Modo mantenimiento ON") {
      io.sockets.emit("modoOperacion", 0);
    } else if (data == "LedRojo ON") {
      io.sockets.emit("estadoLedRojo", 1);
    } else if (data == "LedRojo OFF") {
      io.sockets.emit("estadoLedRojo", 0);
    } else if (data == "LedVerde ON") {
      io.sockets.emit("estadoLedVerde", 1);
    } else if (data == "LedVerde OFF") {
      io.sockets.emit("estadoLedVerde", 0);
    } else if (data == "LedAmarillo ON") {
      io.sockets.emit("estadoLedAmarillo", 1);
    } else if (data == "LedAmarillo OFF") {
      io.sockets.emit("estadoLedAmarillo", 0);
    }
  });

  io.on("connection", (socket) => {
    console.log("Socket Conectado");
    socket.on("LED", function (valorLED, callback) {
      if (valorLED == 1) {
        port.write("p", function (err) {
          if (err) {
            return console.log("Error on write: ", err.message);
          }
        });
      } else if (valorLED == 0) {
        port.write("a", function (err) {
          if (err) {
            return console.log("Error on write: ", err.message);
          }
        });
      }
      console.log("ValorLED:" + valorLED);
      callback(true);
    });
  });
};
