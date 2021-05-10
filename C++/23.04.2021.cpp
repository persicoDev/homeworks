//array 100 terreni che hganno la proprieta grandezza, proprietarioì, codice identificativo, ricerca, media grandezza 
#include <iostream>
#include <string>

using namespace std;

class terreno {
   float gr,mg;
    string pr;
    int cod;
    public:
    void registraTerreno() {
        cout<<"inserisci il nome del proprietario"<<endl;
        cin>>pr;
        cout<<"inserisci il codice identificativo del terreno"<<endl;
        cin>>cod;
        cout<<"inserisci la grandezza in m2"<<endl;
        cin>>gr;
    }

};
 int main() {
    int cont = 0;
    int scelta = 0;
    terreno terreni[10];

    do {        
        switch (scelta) {
        case 1: {
            cout<<"inserisci il terreno in pos: " << cont + 1 << endl;
            terreni[cont].registraTerreno();
            cont++;
        } break;
        case 2: {

        }
        default:
            break;
        }
    } while (scelta != 0);
 }