$(document).ready(function () {
  console.log("Sitio Descargado");
  const socket = io();
  socket.on("modoOperacion", function (modoOperacion) {
    if (modoOperacion == "1") $("#lbl_modo_status").text("Normal");
    if (modoOperacion == "0") $("#lbl_modo_status").text("Mantenimiento");
  });

  socket.on("estadoLedVerde", function (estadoLedVerde) {
    if (estadoLedVerde == "1") $("#lbl_verde_status").text("ON");
    if (estadoLedVerde == "0") $("#lbl_verde_status").text("OFF");
  });

  socket.on("estadoLedRojo", function (estadoLedRojo) {
    if (estadoLedRojo == "1") $("#lbl_rojo_status").text("ON");
    if (estadoLedRojo == "0") $("#lbl_rojo_status").text("OFF");
  });

  socket.on("estadoLedAmarillo", function (estadoLedAmarillo) {
    if (estadoLedAmarillo == "1") $("#lbl_amarillo_status").text("ON");
    if (estadoLedAmarillo == "0") $("#lbl_amarillo_status").text("OFF");
  });

  $("#btn_normal").click(function () {
    socket.emit("LED", 1, function (data) {
      console.log(data);
    });
  });

  $("#btn_mantenimiento").click(function () {
    socket.emit("LED", 0, function (data) {
      console.log(data);
    });
  });
});
