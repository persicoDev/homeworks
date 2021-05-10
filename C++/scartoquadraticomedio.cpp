#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float number_array[7], media = 0, delta = 0, risultato = 0;
    int number = 0;
    cout << "inserisci il numero dei numeri che vuoi inserire: \n";
    cin >> number;
    for (int i = 0; i < number; i ++) {
        cout << "inserisci il numero in posizione: "<< i + 1 <<": \n";
        cin >> number_array[i];
        media += number_array[i];
    }
    media /= number;
    cout << media << "\n";
    for (int i = 0; i < number; i++) 
        delta += (number_array[i] - media);
    delta /= number;
    cout << delta << "\n";
    risultato = sqrt(delta);
    cout << risultato << "\n";
    return 0;
}