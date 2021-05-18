#include <iostream>
#include <string>
using namespace std;

struct paziente {
    string cognome, codice, ordine;
    paziente *next;
};

class codaPazienti {
    paziente *head;
    paziente *end;

    codaPazienti() {
        head = NULL;
        end = NULL;
    }

    void push(int ordine) {
        if (ordine == 1) {
            paziente *p;
            cout <<"inserisci i campi di struct";
        }
        
    }
};