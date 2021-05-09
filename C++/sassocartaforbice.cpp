#include <iostream>
#include <string.h>
 
using namespace std;

int main() {
        string tipi[3] = {"sasso","carta","forbice"};
        string mossa="";
        int tot=0,vit=0,perd=0,pari=0,mossanum=0,bot;
        while(mossa!="0"){
            bot = rand()%3;
            cout  << "Inserire sasso,carta o forbici (s,c,f), inserisci '0' per uscire\n";
            cin >> mossa;
            if(mossa == "s" || mossa == "c" || mossa == "f" || mossa == "sasso" || mossa =="carta" || mossa == "forbice") {
                if(mossa=="0")
                    break;
                else if(mossa=="s" || mossa=="sasso")
                    mossanum = 0;
                else if(mossa=="c" || mossa=="carta")
                    mossanum = 1;
                else if(mossa=="f" || mossa=="forbice")
                    mossanum = 2;
                if(mossanum!=0 && mossanum!=1 && mossanum!=2)
                    cout << "Non conta un cazzo\n";
                else if(mossanum == bot) {
                    cout << "Pari \n";
                    pari++;
                    tot++;
                }
                else if(mossanum==0 && bot==2 || mossanum==1 && bot==0 || mossanum==2 && bot==1) {
                    cout <<"Hai vinto";
                    cout <<"Il bot ha scelto "<< tipi[bot];
                    vit++;
                    tot++;
                }
                else {
                    cout <<"Hai perso\n";
                    cout <<"Il bot ha scelto"<<tipi[bot]<<endl;
                    perd++;
                    tot++;
                }
                cout <<"Totale partite giocate = "<<tot<<" Totale vittorie = "<<vit<<" Totale perdite = "<<perd<<" Totale parita = "<<pari;
                tot = (vit*100)/tot;
                cout <<"Hai vinto il "<<tot<<" delle volte\n";
            } else
                cout <<"inserisci solo i valori sopra indicati\n";
        }
    }
