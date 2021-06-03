#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct addressType {
    string nome, cognome, tipo;
    struct addressType *next;
};

class addressBook {
    addressType *head, *end;

    public:
    addressBook() {
        head = end = NULL;
    }

    void push() {
        addressType *p;
        p = new(addressType);
        cout << "\n\n";
        cout << "inserisci nome: ";
        cin >> p->nome;
        cout << "inserisci il cognome: ";
        cin >> p->cognome;
        cout << "inserisci il tipo (privato o lavoro): ";
        cin >> p->tipo;

        if(head == NULL)
            head = end = p;
         else {
            end->next = p;
            end = p;
        }
    }

    void filePush() {
        addressType *p;
        p = new(addressType);
        ifstream file;
        file.open("addressbook.txt");
        file >> p->nome >> p->cognome >> p->tipo;
        file.close();

        if(head == NULL)
            head = end = p;
         else {
            end->next = p;
            end = p;
        }
    }

    void arrayWrite() {
        vector<addressType*> addressArray;
        for (addressType* p = head; p != NULL; p = p->next) 
            addressArray.push_back(p);

        addressType *tmp;
        for (int i = 0; i < addressArray.size(); i++) {
            for (int j = 0; j < addressArray.size(); j++) {
                if (addressArray[i]->tipo == "privato") {
                    if ( addressArray[i]->cognome > addressArray[j]->cognome ) {
                        tmp = addressArray[i];
                        addressArray[i] = addressArray[j];
                        addressArray[j] = tmp;
                    }
                }
            }
        }
        
        for (int i = 0; i < addressArray.size(); i++)
            cout << "nome: " << addressArray[i]->nome << "\tcognome: " << addressArray[i]->cognome << "\ttipo: " << addressArray[i]->tipo;
    }
};

int main () {
    int choice = 0;
    addressBook obj;
    do {
        cout << "---------------------------------------------------------------------\n";
        cout << "1) inserimento \n2) scrittura su array, sorting e stampa array: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int input_choice = 0;
            cout << "---------------------------------------------------------------------\n";
            cout << "1) inserimento classico\t\t\t2) inserimento da file: ";
            cin >> input_choice;
            if (input_choice == 1)
                obj.push();
            if (input_choice == 2)
                obj.filePush();
        } break;
        
        case 2: 
            obj.arrayWrite();
            break;

        default:
            cout << "scelta errata\n";
            break;
        }
    } while (choice != 0);
}