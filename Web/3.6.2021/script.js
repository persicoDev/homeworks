function getMcm() {
    const index_num = prompt('inserisci il numero dei numeri');
    let num = [];
    
    for(let i = 0; i < index_num; i ++) 
        num.push(prompt('inserisci il numero'));
    const greatest_common_divisor = (a, b) => (a ? greatest_common_divisor(b % a, a) : b);
    const least_common_multiple = (a, b) => (a * b) / greatest_common_divisor(a, b);
    alert(`il minimo comune multiplo è: ${num.reduce(least_common_multiple)}`);
 }