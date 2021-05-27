#include <iostream>
#include <string>
using namespace std;

struct paziente {
    string cognome, ordine;
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

    void push(string ordine) {
        paziente *p;
        p = new(paziente);
        if (ordine == "rosso") {
            cout << "inserisci i campi di struct\n";
            cin >> p->cognome;
            p->ordine = ordine;
            p->next = head;
            head = p;
        }
        if (ordine == "giallo") {
            for (p = head; p != NULL;p = p->next) {
                if(p->ordine != "rosso") {
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
                    break;
                }
            }
        }    
        if (ordine == "verde") {
            for (p = head; p != NULL;p = p->next) {
                if(p->ordine != "rosso" && p->ordine != "giallo") {
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
                        break;
                    }
                }
            }
        }
        if (ordine == "bianco") {
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

    void pop() {
        paziente *p;
        if (head == NULL) 
            cout << "testa vuota! \n";
        else {
            p = head;
            head = p->next;
            delete p;
        }
    }
    
    void eliminaNome(string cognome) {
        paziente *p, *pp;
        if (head == NULL)
            cout << "testa vuota \n";
        else {
            if (cognome == head->cognome) 
                head = head->next;
            else {
                pp = head;
                for (p = head; p != NULL; p = p->next) {
                    if (cognome == p->cognome) 
                        pp->next = p->next;
                    else 
                        pp = p;
                }
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    codaPazienti obj;
    int scelta = 0;
    do {
        cout << "seleziona 1 per inserimento, seleziona 2 per la stampa, seleziona 3 per il pop, seleziona 4 per eliminare dato il cognome\n";
        cin >> scelta;
        switch (scelta) {
        case 1: {
            string ordine;
            cout << "inserisci l'ordine: ";
            cin >> ordine;
            obj.push(ordine);
        } break;
        case 2:
            obj.stampa();
            break;
        case 3:
            obj.pop();
            break;
        case 4: {
            string cognome;
            cout << "inserire il cognome:";
            cin >> cognome;
            obj.eliminaNome(cognome);
        }
        default:
            break;
        }
    } while(scelta != 0);
    return 0;
}
