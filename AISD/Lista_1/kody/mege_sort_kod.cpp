#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std::chrono;
using namespace std;
void MERGE(int A[], int p, int s, int k, int &porównania, int &przypisania){
    int n_1, n_2;
    n_1 = s - p + 1;
    n_2 = k - s;
    vector<int> L(n_1), R(n_2);
    int i, j;
    for(i = 0; i < n_1; i++){
        L[i] = A[i + p];
        przypisania++;
    }
    for(j = 0; j < n_2; j++){
        R[j] = A[j + s + 1];
        przypisania++;
    }
    int t;
    i = 0;
    j = 0;
    t = p;
    
    porównania++;
    while(i < n_1 && j < n_2){
        porównania+=2;
        
        
        
        
        porównania++;
        if (L[i] <= R[j]){
            A[t++] = L[i++];
            przypisania+=3;
        }
        else{
            A[t++] = R[j++];
            przypisania+=3;
        }
        porównania++;
    }
    porównania++;
    while(i < n_1){
        porównania++;
        A[t++] = L[i++];
        porównania++;
        
        przypisania+=3;
    }
    porównania++;
}

void MERGE_SORT(int A[], int p, int k, int &porównania, int &przypisania){
    porównania++;
    if (p < k){
        int s;
        s = p + (k-p)/2;
        przypisania++;
        MERGE_SORT(A, p, s, porównania, przypisania);
        MERGE_SORT(A, s+1, k, porównania, przypisania);
        MERGE(A, p, s, k, porównania, przypisania);
    } 
}

void MERGE_2(int A[], int low, int mid_1, int mid_2, int high, int &porównania, int &przypisania){
    int n_1, n_2, n_3;
    n_1 = mid_1 - low + 1;
    n_2 = mid_2 - mid_1;
    n_3 = high - mid_2;
    vector<int> L(n_1), M(n_2), R(n_3);
    int i, j, k;
    for(i = 0; i < n_1; i++){
        L[i] = A[low + i];
        przypisania++;
    }
    for(j = 0; j < n_2; j++){
        M[j] = A[j + mid_1 + 1];
        przypisania++;
    }
    for(k = 0; k < n_3; k++){
        R[k] = A[k + mid_2 + 1];
        przypisania++;
    }
    int t;
    i = 0;
    j = 0;
    k =0;
    t = low;
    
    porównania++;
    while(i < n_1 && j < n_2 && k < n_3){
        porównania+=3;
        
        porównania+=2;
        if (L[i] <= M[j] && L[i] <= R[k]){
            A[t++] = L[i++];
            przypisania+=3;
        }
        else {
            porównania+=2;
            if (M[j] <= R[k] && M[j] <= L[i]){
            A[t++] = M[j++];
            przypisania+=3;
        }
        else{
            A[t++] = R[k++];
            przypisania+=3;
        }
        }
        porównania++;
    }
    porównania++;
    
    
    porównania++;
    while(i < n_1 && j < n_2) {
        porównania++;
        if(L[i] <= M[j]) {
            A[t++] = L[i++];
            przypisania+=3;
        }
        else {
            A[t++] = M[j++];
            przypisania+=3;
        }
        porównania++;
    }
    
    
    porównania++;
    while(i < n_1 && k < n_3) {
        porównania++;
        if(L[i] <= R[k]) {
            A[t++] = L[i++];
            przypisania+=3;
        }
        else {
            A[t++] = R[k++];
            przypisania+=3;
        }
        porównania++;
    }
    
    
    porównania++;
    while(j < n_2 && k < n_3) {
        porównania++;
        if(M[j] <= R[k]) {
            A[t++] = M[j++];
            przypisania+=3;
        }
        else {
            A[t++] = R[k++];
            przypisania+=3;
        }
        porównania++;
    }
    
    
    porównania++;
    while(i < n_1){
        porównania++;
        A[t++] = L[i++];
        
        przypisania+=3;
        
        
        
        porównania++;
    }
    porównania++;
    
    
    porównania++;
    while(j < n_2){
        porównania++;
        A[t++] = M[j++];
        
        przypisania+=3;
        
        
        porównania++;
    }
    porównania++;
    
    porównania++;
    while(k < n_3){
        porównania++;
        A[t++] = R[k++];
        
        przypisania+=3;
        
        
        porównania++;
    }
    porównania++;
    
}
void MERGE_SORT_2(int A[], int low, int high, int &porównania, int &przypisania){
    porównania++;
    if (low < high){
        int mid_1;
        int mid_2;
        mid_1 = (2 * low + high)/3;
        przypisania++;
        mid_2 = (low + 2 * high)/3;
        
        przypisania++;
        MERGE_SORT_2(A, low, mid_1, porównania, przypisania);
        MERGE_SORT_2(A, mid_1 + 1, mid_2, porównania, przypisania);
        MERGE_SORT_2(A, mid_2 + 1, high, porównania, przypisania);
        MERGE_2(A, low, mid_1, mid_2, high, porównania, przypisania);
    } 
}

int main(){
    srand(time(0));
    int n;
    
    cout << "Podaj n";
    cin >> n;
    
    int *array1 = new int[n];
    int *array2 = new int[n];
    
    for(int i = 0; i < n; i++){
        array1[i] = array2[i] = rand() % 999 + 1;
    }
    cout << "Pierwsze 30 elementów tablicy przed posortowaniem to: " << endl;
    for(int i = 0; i < min(30, n); i++) {
        cout << array1[i] << " ";
    }
    cout << endl << endl;
    int por_1, por_2, prz_1, prz_2;
    por_1 = por_2 = prz_1 = prz_2 = 0;
    
    auto start2 = chrono::high_resolution_clock::now();
    MERGE_SORT_2(array2, 0, n-1, por_2, prz_2);
    auto end2 = chrono::high_resolution_clock::now();
    auto czas2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
    
    auto start1 = chrono::high_resolution_clock::now();
    MERGE_SORT(array1, 0, n-1, por_1, prz_1);
    auto end1 = chrono::high_resolution_clock::now();
    auto czas1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
    
    cout << "Tablica po sortowaniu przez MERGE_SORT(niezmodyfikowany):" << endl;
    for(int i = 0; i < min(30, n); i++) {
    cout << array1[i] << " ";
    }
    cout << endl;
    
    cout << "Tablica po sortowaniu przez MERGE_SORT(zmodyfikowany):" << endl;
    for(int i = 0; i < min(30, n); i++) {
        cout << array2[i] << " ";
    }
    cout << endl << endl;
    
    
    cout << "MERGE_SORT(niezmodyfikowany) ma " << por_1 << " porównań oraz " << prz_1 << " przypisań, a czas to: " << czas1.count() 
    << " mirkosekund, ponieważ ilość operacji to: "<< (por_1 + prz_1) << endl;
    cout << "MERGE_SORT(zmodyfikowany) ma " << por_2 << " porównań oraz " << prz_2 << " przypisań, a czas to:" << czas2.count()
    << " mirkosekund, ponieważ ilość operacji to: "<< (por_2 + prz_2) << endl;
    
    delete[] array1;
    delete[] array2;
    return 0;
}