//
// Created by Andrei Vitan on 5/11/2024.
//
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <chrono> // pentru std::chrono
using namespace std;
using namespace std::chrono;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Construim un heap (max-heap) din array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extragem elementele din heap și recontruim heap-ul
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    const int size = 10000;
    int arr[size];

    srand(time(NULL));
    for (int i = size; i >0; i--) {
        arr[i] = rand() %10000;
        //cout<<arr[i]<<" ";
    }

    // Măsurarea timpului pentru sortare
    auto start = high_resolution_clock::now();
    heapSort(arr, size);
    auto end = high_resolution_clock::now();

    // Calcularea timpului total de sortare
    duration<double> time_taken = duration_cast<duration<double>>(end - start);

    // Afișarea timpului cu 10 zecimale
    cout << fixed << setprecision(10);
    cout << "Time taken by heap sort: " << time_taken.count() << " seconds" << endl;

    return 0;
}
