let isPrimeNumber = number => {
    for ( let i = 2; i < number; i++ ) {
        if ( number % i == 0 ) 
            return false;
    } 
    return true;
};

function getPrime() {
    let cont = 0
    let number = document.getElementById('number-input').value;
    while (cont < 10) {
        number ++
        if (isPrimeNumber(number)) {
            cont ++;
            document.getElementById("result").innerHTML += " " + number;
        }
    } 
}