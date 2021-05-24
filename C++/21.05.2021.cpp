#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 100;

struct contact {
    string name, surname, type;
    int phone_number;
    struct contact *next;
};

class addressBook {
    contact C[MAX];
    contact *head;
    int i;

public:

    addressBook() {
        head = NULL;
        i = 0;
    }

    void push() {
        contact *p;
        p = new(contact);

        cout << "Inserire il nome: ";
        cin >> p->name;
        cout << "Inserire il cognome: ";
        cin >> p->surname;
        cout << "Inserire tipo di contatto(privato o lavoro): ";
        cin >> p->type;
        cout << "Inserire il numero del contatto: ";
        cin >> p->phone_number;
        p->next = head;
        head = p;
    }

    void file() {
        ofstream file;
        contact *p;

        if (head != NULL) {
            file.open("adressbook.txt");
            for (p = head; p != NULL; p = p->next) {
                if (p->type == "privato")
                    file << p->name << "\t" << p->surname << "\t" << p->type << "\t" << p->phone_number << "\n";
            }
            file.close();
        } else 
            cout << "Non hai nessun contatto in rubrica\n";
    }

    void array() {
        contact *p;

        if (head != NULL) {
            for (p = head; p != NULL; p = p->next) {
                if (p->type == "lavoro") {
                    C[i] = *p;
                    i++;
                }
            }
        } else 
            cout << "Non hai nessun contatto in rubrica\n";
    }

    void sorting() {
        contact tmp;

        for (int y = 0; y < i - 1; y++) {
            for (int j = i + 1; j < i; j++) {
                if (C[y].name > C[j].name) {
                    tmp = C[y];
                    C[y] = C[j];
                    C[j] = tmp;
                }
            }
        }
    }

    void erase() {
        contact *p, *pp;
        string sur;

        if (head == NULL)
            cout << "Non ci sono contatti\n";
        else {
            cout << "Inserire il cognome del contatto: ";
            cin >> sur;
            if (sur == head->surname) {
                head = head->next;
                cout << "Eliminazione riuscita\n";
            } else 
                pp = head;
            for (p = head; p != NULL; p = p->next) {
                if (p->surname == sur) 
                    pp->next = p->next;
                else 
                    pp = p;
            }
        }
    }

    void insert() {
        contact *p, *p1, *p2;
        string sur;
        bool check = false;
        p2 = new(contact);

        cout << "Inserire cognome contatto: ";
        cin >> sur;
        for (p = head; p != NULL; p = p->next) {
            p1 = p->next;
            if (p->surname == sur) {
                cout << "Inserire il nome: ";
                cin >> p2->name,
                cout << "Inserire il cognome: ";
                cin >> p2->surname;
                cout << "Inserire tipo di contatto(privato o lavoro): ";
                cin >> p2->type;
                cout << "Inserire il numero del contatto: ";
                cin >> p2->phone_number;
                p->next = p2;
                p2->next = p1;
                check = true;
                break;
            }
        }
        if (!check)
            cout << "Il cognome " << sur << "non e' stato trovato tra i contatti\n";
    }

    void print(){
        contact* p;
        int count = 0;

        if (head == NULL)
            cout << "Non ci sono contatti\n";
        else {
            cout << "\t\tELENCO CONTATTI\n";
            for (p = head; p != NULL; p = p->next) {
                count++;
                cout << "Contatto numero: " << count << "\n";
                cout << "Nome: " << p->name << "\nCognome: " << p->surname << "\nNumero di telefono: " << p->phone_number << "\nTipo: " << p->type << "\n";
            }
        }
    }

};


int main() {
    int choice = 0;
    addressBook contacts;
    
    do {
        cout << "0-Uscire dal programma,\n"
             << "1-Inserire un contatto,\n"
             << "2-Inserire i contatti privati in un file,\n"
             << "3-Inserire i contatti lavoro in un array,\n"
             << "4-Ordinare i contatti nell'array,\n"
             << "5-Eliminare un contatto,\n"
             << "6-Inserire un nuovo contatto dopo un contatto dato in input,\n"
             << "5-Stampa dei contatti,\n"
             << "Scelta:";
        cin  >> choice;
        switch (choice) {
            case 0:
                return 0;
                break;
            default:
                cout << "--scelta errata--\n";
                break;
            case 1:
                contacts.push();
                break;
            case 2:
                contacts.file();
                break;
            case 3:
                contacts.array();
                break;
            case 4:
                contacts.sorting();
                break;
            case 5:
                contacts.erase();
                break;
            case 6:
                contacts.insert();
                break;
            case 7:
                contacts.print();
                break;
        }
    } while (choice != 0);
    return 0;
}