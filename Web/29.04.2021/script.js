function checkPassword() {
    const password = document.getElementById('password').value;
    const search_term = [/[A-Z]/, /[0-9]/, /[!@#$%&*]/];
    let result = true;
    for (let index = 0; index < search_term.length; index++) {
        result = search_term[index].test(password);
        if (!result && index == 0)
            alert('inserisci almeno una lettera maiuscola');
        if (!result && index == 1)
            alert('inserisci almeno un numero');
        if (!result && index == 2)
            alert('inserisci almeno un carattere speciale'); 
        if (password.length < 8)
            alert('la password deve contenere almeno 8 caratteri');
    }
}