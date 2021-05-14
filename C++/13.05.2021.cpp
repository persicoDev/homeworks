#include <iostream>
#include <string>
using namespace std;
struct ufficio {
    string descrizione, nome_impiegato, codice;
    struct ufficio *next;
};

class gestoreUfficio {
    ufficio *testa;
    ufficio *fine;
    
    public:

    gestoreUfficio() {
        testa = NULL;
        fine = NULL;
    }

    ~gestoreUfficio() {
        ufficio *p;
        while (testa != NULL) {
            p = testa;
            testa = testa->next;
            delete(p);
        }
    }    
        void push() {
            ufficio *p;
            p = new (ufficio);
            cout << "inserire il nome dell'impiegato: \n";
            cin >> p->nome_impiegato;
            cout << "inserire il codice: \n";
            cin >> p->codice;
            cout << "inserire la descrizione: \n";
            cin >> p->descrizione;
        }

        void print() {

        }
};