function checkData() {
    const name = document.getElementById('name').value;
    const surname = document.getElementById('surname').value;
    let first_date = document.getElementById('first-date').value;
    let second_date = document.getElementById('second-date').value;
    first_date = Date.parse(first_date);
    second_date = Date.parse(second_date);
    if (first_date < Date.now())
        alert("la data da te inserita é minore della data attuale.");
    if (second_date < first_date)
        alert("inserisci una data di arrivo valida.")
    if (name == '' || surname == '')
        alert('inserisci o il nome o il cognome');
}   