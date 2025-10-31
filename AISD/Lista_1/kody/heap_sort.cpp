#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Inicjalizacje dwóch odgałezień kopca binarnego
int LEFT(int i) { return 2 * i + 1; }
int RIGHT(int i) { return 2 * i + 2; }

void HEAPIFY(vector<int>& A, int i, int heap_size, int &por, int &prz) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;

    por++;

    # Znajdowanie wiekszego z dzieci
    if (l < heap_size && A[l] > A[largest])
        largest = l;
    
    por++;
    if (r < heap_size && A[r] > A[largest])
        largest = r;
	
    # Sprawdzamy czy któryś z dzieci jest większy od rodzica
    if (largest != i) {
        prz += 3; 

    //Jeżeli tak to zmieniamy miejscami rodzica z dzieckiem
        swap(A[i], A[largest]);
    // Kopiec mógł zostać zdeformowany więc rekurnecyjnie ponawiamy kopcowanie
        HEAPIFY(A, largest, heap_size, por, prz);
    }
}

void BUILD_HEAP(vector<int>& A, int &por, int &prz) {
    int heap_size = A.size();
    # Budowa kopca -> dzielimy przez 2 bo tyle odgałęzień jest w binarnym
    for (int i = heap_size / 2 - 1; i >= 0; i--)
    
   // Kopcowanie, by stworzyć kopiec(ale nie jest on dokładny)
        HEAPIFY(A, i, heap_size, por, prz);
}

void HEAP_SORT(vector<int>& A, int &por, int &prz) {

    // Inicjujemy kopiec
    BUILD_HEAP(A, por, prz);
    int heap_size = A.size();

    for (int i = heap_size - 1; i > 0; i--) {
        prz += 3;
// Zamiana z indeksu 0 na ostatni, tak by spełniało własności kopca(nie może być przerwy w tablicy)
        swap(A[0], A[i]);
        heap_size--;
// Kopcujemy, ponieważ kopiec mógł zostac zdeformowany
        HEAPIFY(A, 0, heap_size, por, prz);
    }
}

// Inicjalizacje 3 odgałęzień w przypadku kopca ternarnego
int LEFT_2(int i)  { return 3 * i + 1; }
int MID_2(int i)   { return 3 * i + 2; }
int RIGHT_2(int i) { return 3 * i + 3; }

void HEAPIFY_2(vector<int>& A, int i, int heap_size, int &por, int &prz) {
    int l = LEFT_2(i);
    int m = MID_2(i);
    int r = RIGHT_2(i);
    int largest = i;


    // Znajdowanie wiekszego z dzieci
    por++;
    if (l < heap_size && A[l] > A[largest])
        largest = l;
    
    por++;
    if (m < heap_size && A[m] > A[largest])
        largest = m;
    
    por++;
    if (r < heap_size && A[r] > A[largest])
        largest = r;

    // Sprawdzamy czy któryś z dzieci jest większy od rodzica
    if (largest != i) {
        prz += 3;
    //Jeżeli tak to zmieniamy miejscami rodzica z dzieckiem
        swap(A[i], A[largest]);
    // Kopiec mógł zostać zdeformowany więc rekurnecyjnie ponawiamy kopcowanie
        HEAPIFY_2(A, largest, heap_size, por, prz);
    }
}

void BUILD_HEAP_2(vector<int>& A, int &por, int &prz) {
    int heap_size = A.size();

    // Budowa kopca -> dzielimy przez 3 bo tyle odgałęzień jest w ternarnym
    for (int i = heap_size / 3 - 1; i >= 0; i--)

   // Kocowanie, by stworzyć kopiec(ale nie jest on dokładny)
        HEAPIFY_2(A, i, heap_size, por, prz);
}

void HEAP_SORT_2(vector<int>& A, int &por, int &prz) {
    BUILD_HEAP_2(A, por, prz);

    // Inicjujemy kopiec
    int heap_size = A.size();

    for (int i = heap_size - 1; i > 0; i--) {
        prz += 3;

// Zamiana z indeksu 0 na ostatni, tak by spełniało własności kopca(nie może być przerwy w tablicy)
        swap(A[0], A[i]);
        heap_size--;

// Kopcujemy, ponieważ kopiec mógł zostac zdeformowany
        HEAPIFY_2(A, 0, heap_size, por, prz);
    }
}


int main() {
    srand(time(0));
    int n;
    cout << "Podaj n: ";
    cin >> n;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        int val = rand() % 999 + 1;
        A[i] = B[i] = val;
    }

    cout << "Pierwsze 30 elementów przed sortowaniem:" << endl;
    for (int i = 0; i < min(30, n); i++) cout << A[i] << " ";
    cout << endl << endl;

   // Zaczynamy porównania i przypisania inicjując jego wartość równą 0
    int por_1 = 0, prz_1 = 0, por_2 = 0, prz_2 = 0;

    // funkcje na czas   
    auto start1 = high_resolution_clock::now();
    HEAP_SORT(A, por_1, prz_1);
    auto end1 = high_resolution_clock::now();
    auto czas1 = duration_cast<microseconds>(end1 - start1);

    auto start2 = high_resolution_clock::now();
    HEAP_SORT_2(B, por_2, prz_2);
    auto end2 = high_resolution_clock::now();
    auto czas2 = duration_cast<microseconds>(end2 - start2);

    cout << "Pierwsze 30 elementów po HEAP_SORT(binarny):" << endl;
    for (int i = 0; i < min(30, n); i++) cout << A[i] << " ";
    cout << endl;

    cout << "Pierwsze 30 elementów HEAP_SORT(ternarny):" << endl;
    for (int i = 0; i < min(30, n); i++) cout << B[i] << " ";
    cout << endl << endl;

    cout << "HEAP_SORT(binarny) ma " << por_1 << " porównań oraz " << prz_1 << " przypisań, a czas to: " << czas1.count() 
    << " mirkosekund, ponieważ ilość operacji to: "<< (por_1 + prz_1) << endl;
    
    cout << "HEAP_SORT(ternarny) ma " << por_2 << " porównań oraz " << prz_2 << " przypisań, a czas to:" << czas2.count()
    << " mirkosekund, ponieważ ilość operacji to: "<< (por_2 + prz_2) << endl;

    return 0;
}