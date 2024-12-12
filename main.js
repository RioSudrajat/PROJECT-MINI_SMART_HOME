const endpoint = "http://10.0.0.120";

function getDapurLed() {
  fetch(endpoint + "/dapur", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if ((result = "ON")) {
        ledDapur.style.backgroundColor = "blue";
        dapurLedImage.src = "./assets/led-on.png";
      } else {
        ledDapur.style.backgroundColor = "#579fff";
        dapurLedImage.src = "./assets/led-on.png";
      }
    });
}
function getTamuLed() {
  fetch(endpoint + "/tamu", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if ((result = "ON")) {
        ledTamu.style.backgroundColor = "blue";
        tamuLedImage.src = "./assets/led-on.png";
      } else {
        ledTamu.style.backgroundColor = "#579fff";
        tamuLedImage.src = "./assets/led-on.png";
      }
    });
}
function getMakanLed() {
  fetch(endpoint + "/makan", {
    method: "GET",
  })
    .then((response) => response.text())
    .then((result) => {
      if ((result = "ON")) {
        ledMakan.style.backgroundColor = "blue";
        makanLedImage.src = "./assets/led-on.png";
      } else {
        ledMakan.style.backgroundColor = "#579fff";
        makanLedImage.src = "./assets/led-on.png";
      }
    });
}
function setDapurLed() {
  fetch(endpoint + "/dapur", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload);
}
function setTamuLed() {
  fetch(endpoint + "/tamu", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload);
  ledTamu.style.background = "red";
  tamuLedImage.src = "./assets/led-on.png";
}
function setMakanLed() {
  fetch(endpoint + "/makan", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload);
  ledMakan.style.background = "red";
  makanLedImage.src = "./assets/led-on.png";
}
function setToiletLed() {
  fetch(endpoint + "/toilet", {
    method: "POST",
  })
    .then((response) => response.text())
    .then(() => location.reload);
  ledToilet.style.background = "red";
  toiletLedImage.src = "./assets/led-on.png";
}

getDapurLed();
getTamuLed();
getMakanLed();
