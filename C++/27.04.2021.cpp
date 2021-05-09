#include <iostream>
#include <string>
using namespace std;

struct paziente {
  string nome;
  int num;
  struct paziente *next;
};
class coda {
  paziente *testa, *fine;
  int num;

public:
  coda() { // questo è il costruttore
    testa = NULL;
    fine = NULL; // inizalizazione  della coda senza nulla dentro
    num = 1;
  }
  void push() { // inserimento del paziente in coda
    paziente *p;
    p = new (paziente);
    cout << "inserire il nome del paziente: \n";
    cin >> p->nome;
    p->num = num++; // alloca l'indirizzo di memoria, il cui indirizzo è p;
                    // quindi devo andare inserire la variabile all'interno di p.
    cout << "il paziente: " << p->nome << " ha il numero: " << p->num << endl;
    p->next = NULL;
    if (testa == NULL)
      testa = fine = p; // inserimento 1° paziente
    else {
      fine->next = p;
      fine = p;
    }
  }
  void pop() { // estrazione del primo paziente della coda
    paziente *p;
    if (testa == NULL)
      cout << "non ci sono pazienti in attesa \n";
    else {
      p = testa;
      testa = p->next;
      cout << "il prossimo paziente: " << p->nome << "e ha il numero: " << p->num
           << endl;
      if (testa == NULL)
        fine = NULL;
      delete p;
    }
  }
  void stampa() { // stampa dei pazienti in attesa
    paziente *p;
    if (testa == NULL)
      cout << "non ci sono pazienti in attesa \n";
    else {
      cout << "elenco pazienti in attesa \n";
      for (p = testa; p != NULL; p = p->next)
        cout << p->nome << "\t\t" << p->num << endl;
    }
  }
  void precedenza() { // fa passare avanti il paziente con priorità più alte
    paziente *p; 
    p = new (paziente);
    cout << "inserire il nome del paziente: \n"; 
    cin >> p->nome;
    p->num = 0;
    cout << "paziente: " << p->nome << " numero: " << p->num << endl;
    p->next = testa;
    testa = p;
  }
};
int main() {
  int scelta;
  coda studio;
  do {
    cout << "0: esci dal programma \n";
    cout << "1: inserisci paziente \n";
    cout << "2: estrai paziente \n";
    cout << "3: stampa elenco pazienti in attesa \n";
    cout << "4: paziente con priorità \n";
    cout << "fai una scelta: ";
    cin >> scelta;
    switch (scelta) {
    case 1:
      studio.push();
      break;
    case 2:
      studio.pop();
      break;
    case 3:
      studio.stampa();
      break;
    case 4:
      studio.precedenza();
      break;
    }

  } while (scelta != 0);
   return(0);
}