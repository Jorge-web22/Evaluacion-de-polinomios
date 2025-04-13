#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <fstream>
#include <vector>

const int NUM_PRUEBAS = 1000;
const int MIN_TAMANO = 10;
const int MAX_TAMANO = 1000;
const int INCREMENTO = 10;

void insercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = clave;
    }
}

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    ofstream archivoCSV("tiempos_ordenamiento.csv");
    archivoCSV << "Tama\244o,TiempoPromedio(ms)\n"; // Encabezado simplificado

    for (int tam = MIN_TAMANO; tam <= MAX_TAMANO; tam += INCREMENTO) {
        double sumaTiempos = 0.0;

        for (int prueba = 0; prueba < NUM_PRUEBAS; prueba++) {
            int *arreglo = new int[tam];
            for (int i = 0; i < tam; i++) {
                arreglo[i] = 1 + std::rand() % 1000; // Corregido a 1-1000
            }

            auto inicio = chrono::high_resolution_clock::now();
            insercion(arreglo, tam);
            auto fin = chrono::high_resolution_clock::now();

            chrono::duration<double, milli> duracion = fin - inicio;
            sumaTiempos += duracion.count();

            delete[] arreglo;
        }

        double promedio = sumaTiempos / NUM_PRUEBAS;
        archivoCSV << tam << "," << promedio << "\n"; // Formato CSV corregido
        cout << "Tama\244o: " << tam << " - Promedio: " << promedio << " ms\n";
    }

    archivoCSV.close();
    return 0;
}
