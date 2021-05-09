function sinCos() {
    let gradi = document.getElementById("gradi-iniziali").value;
    let seno = document.getElementById("sin");
    let coseno = document.getElementById("cos");
    let gradi_in_uscita = document.getElementById("gradi-uscita");
    coseno.innerHTML = Math.cos((gradi * Math.PI) / 180);
    gradi_in_uscita.innerHTML = gradi;
    seno.innerHTML = Math.sin((gradi * Math.PI) / 180);
  }