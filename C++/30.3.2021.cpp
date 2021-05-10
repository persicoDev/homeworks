#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

struct vettura{
    string targa;
    int cil;
    struct vettura *next;
};
vettura *p;

class pila{
    vettura *testa;
    public:
        pila() {
            testa=NULL;
        }
        void push() {
            p = new(vettura);
            cout << "\nNumero di targa" <<endl;
            cin >> p->targa;
            cout << "Cilindrata" <<endl;
            cin >> p->cil;
            p->next = testa;
            testa = p;
        }
        void pop() {
            if(testa==NULL)
                cout << "\nNon ci sono autovetture disponibili" <<endl;
            else {
                p = testa;
                testa = p->next;
                cout << "\nLa vettura assegnata ha targa "<< p->targa << " e cilindrata " << p->cil <<endl;
                delete p;
            }
        }
        void stampa() {
            if(testa==NULL)
                cout << "\nNon ci sono autovetture disponibili" <<endl;
            else {
                cout << "\nElenco autovetture" <<endl;
                for(p=testa; p!=NULL; p=p->next)
                    cout<<p->targa<<"\t\t"<<p->cil<<endl;
            }
        }

        ~pila() {  //distruttore
            while(testa!=NULL) {
                p=testa;
                testa = testa->next;
                delete(p);
            }
        }
};

int main() {
    int scelta;
    pila garage;
    do {
        cout << "\nInserire valore per scegliere opzione" <<endl;
        cout << "Opzione 1: Inserisci auto (push)" <<endl;
        cout << "Opzione 2: Elimina auto (pop)" <<endl;
        cout << "Opzione 3: Stampa elenco auto" <<endl;
        cout << "Opzione 0: Esci dal programma" <<endl;
        cin >> scelta;
        switch(scelta) {
            case 0:
                cout<<"\n---Uscendo dal programma"<<endl;
            break;
            case 1:
                garage.push();
            break;
            case 2:
                garage.pop();
            break;
            case 3:
                garage.stampa();
            break;
            default:
                cout<<"\nScelta inesistente"<<endl;
        }
    } while(scelta!=0);
    return 0;
}