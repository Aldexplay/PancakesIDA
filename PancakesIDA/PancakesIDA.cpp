#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
                                //  ALEXIS ALDHAIR GARCIA SANDEZ ITC
using namespace std;

                                                                    // Funci�n para imprimir el vector
void printVector(const vector<char>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

                                                                // Funci�n para voltear los pancakes
void flip(vector<char>& v, int i) {
    reverse(v.begin(), v.begin() + i + 1);
}

                                                                    // Funci�n para ordenar los pancakes
void pancakeSort(vector<char>& v) {
    int n = v.size();
    vector<int> flips;                                            // Vector para guardar los volteos realizados
    for (int i = n - 1; i >= 0; i--) {
        int maxIndex = 0;
        for (int j = 0; j <= i; j++) {
            if (v[j] > v[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex == i) {
            continue;
        }
        if (maxIndex > 0) {
            flip(v, maxIndex);
            flips.push_back(maxIndex);                             // Agregar el �ndice del volteo al vector de volteos
        }
        flip(v, i);
        flips.push_back(i);                                         // Agregar el �ndice del volteo al vector de volteos
    }
    cout << "N�mero de movimientos: " << flips.size() << endl;       // Imprimir el n�mero de movimientos
    cout << "Movimientos efectuados: ";
    for (int i = 0; i < flips.size(); i++) {
        cout << flips[i] << " ";                                    // Imprimir los �ndices de los volteos realizados
    }
    cout << endl;
}

int main() {
    srand(time(0));                                             // Inicializar la semilla para generar n�meros aleatorios
    vector<char> v(10);                                                 // Crear un vector de tama�o 10
    for (int i = 0; i < 10; i++) {
        v[i] = 'A' + i;                                         // Llenar el vector con las letras del alfabeto
    }
    random_shuffle(v.begin(), v.end());                                 // Desordenar las letras aleatoriamente
    cout << "Pancakes desordenados: ";
    printVector(v);                                                 // Imprimir el vector desordenado
    pancakeSort(v);                                                     // Ordenar los pancakes
    cout << "Pancakes ordenados: ";
    printVector(v);                                                     // Imprimir el vector ordenado
    return 0;
}

