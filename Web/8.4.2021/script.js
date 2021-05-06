function sinCos(){
  let gradi = document.getElementById("gradi-iniziali").value;
  let seno = Math.sin((gradi * Math.PI)/180);
  let cos = Math.cos((gradi * Math.PI)/180);
  let funz = seno / gradi;
  document.getElementById("sin").innerHTML = seno;
  document.getElementById("cos").innerHTML = cos;
  document.getElementById("gradi-uscita").innerHTML = gradi;
  document.getElementById("fdix").innerHTML =  funz;
}