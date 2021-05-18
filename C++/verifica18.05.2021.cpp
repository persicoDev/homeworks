#include <iostream>
#include <string>
using namespace std;

struct paziente {
    string cognome;
    int ordine;
    paziente *next;
};

class codaPazienti {
    paziente *head;
    paziente *end;

    public:
    codaPazienti() {
        head = NULL;
        end = NULL;
    }

    void push(int ordine) {
        paziente *p;
        p = new(paziente);
        if (ordine == 1) {
            cout << "inserisci i campi di struct\n";
            cin >> p->cognome;
            p->ordine = ordine;
            p->next = head;
            head = p;
        }
        if (ordine == 2) {
            for (p = head; p != NULL;p = p->next) {
                if(p->ordine != 1) {
                    cout << "inserisci i campi di struct\n";
                    cin >> p->cognome;
                    p->ordine = ordine;
                    p->next = head;
                    head = p;
                    break;
                } 
                else {
                    cout << "inserisci nei campi\n";
                    cin >> p->cognome;
                    p->ordine = ordine;
                    p->next = NULL;
                    if (head == NULL)
                        head = end = p;
                    else {
                        end->next = p;
                        end = p;
                    }
                }
            }
        }    
        if (ordine == 3) {
            for (p = head; p != NULL;p = p->next) {
                if(p->ordine != 1 && p->ordine != 2) {
                    cout << "inserisci i campi di struct\n";
                    cin >> p->cognome;
                    p->ordine = ordine;
                    p->next = head;
                    head = p;
                    break;
                } 
                else {
                    cout << "inserisci nei campi\n";
                    cin >> p->cognome;
                    p->ordine = ordine;
                    p->next = NULL;
                    if (head == NULL)
                        head = end = p;
                    else {
                        end->next = p;
                        end = p;
                    }
                }
            }
        }
        if (ordine == 4) {
            cout << "inserisci nei campi\n";
            cin >> p->cognome;
            p->ordine = ordine;
            p->next = NULL;
            if (head == NULL)
                head = end = p;
            else {
                end->next = p;
                end = p;
            }
        }
    }
    void stampa() {
        paziente *p;
        for (p = head; p != NULL; p = p->next)
            cout << "cognome: " << p->cognome << "\tordine: " << p->ordine << endl;
    }
};

int main(int argc, char const *argv[]) {
    codaPazienti obj;
    int scelta = 0;
    do {
        cout << "selezoina 1 per inserimento, seleziona 2 per la stampa\n";
        cin >> scelta;
        if (scelta == 1){
            int ordine;
            cout << "inserisci l'ordine\n";
            cin >> ordine;
            obj.push(ordine);
        }
        if (scelta == 2)
            obj.stampa();
    } while(scelta != 0);
    return 0;
}
