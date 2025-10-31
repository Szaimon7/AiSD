#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std::chrono;
using namespace std;

void insertion_sort(int A[], int n, int &porównania, int &przypisania){
    for (int i=1; i<n; i++){
        porównania++;
        int x=A[i];
        przypisania++;
        
        int j = i-1;
        przypisania++;
        
        porównania++;
        // Sprawdzanie czy dany element jest większy
        while (j>=0 && A[j] > x){ 
            porównania+=2;
            A[j+1]=A[j];
            przypisania++;
            
            j--;
            przypisania++;
            
            porównania++;
        }
        porównania++;

        
        A[j+1]=x;
        przypisania++;
    }
}
void insertion_sort_2(int A[], int n, int &porównania, int &przypisania){
    for (int i=1; i<n; i+=2){
        porównania++;
        
        porównania++;
        if (A[i] < A[i-1]) { //Nadpisywanie elementów
            int temp = A[i];
            A[i] = A[i-1];
            A[i-1] = temp;
            przypisania += 3;
        }

	//Deklaracja który element jest mniejszy/większy
        int mniejszy_element = A[i-1]; 
        int większy_element = A[i];
        przypisania += 2;
        
        int j = i - 2;
        przypisania++;
            
            
            porównania++;

	    //Pętla gdy element jest większy od dwóch pozostałych 
            while (j>=0 && A[j] > większy_element){ 
                porównania+=2;
                A[j+2]=A[j];
                przypisania++;
                
                j--;
                przypisania++;
                
                
                porównania++;
            }
            porównania++;
                
            A[j+2]= większy_element;
            przypisania++;
            
            int k = j;
            przypisania++;
            
            porównania++;

            //Pętla gdy element jest tylko większy od mniejszego 
            while (k>=0 && A[k] > mniejszy_element){
                porównania+=2;
                
                A[k+1]=A[k];
                przypisania++;
                
                k--;
                przypisania++;
                
                porównania++;
            }
            porównania++;

	    //Przypis gdy element jest mniejszy od dwóch pozostałych
            A[k+1] = mniejszy_element;
            
            przypisania++;
        
    }
    //Wyjątek gdy i zatrzymuje się na i = n-1, gdzie n nieparzyste
    if (n % 2 == 1){
        
        int x = A[n-1];
        przypisania++;
        
        int j = n-2;
        przypisania++;
        
        porównania++;
        while (j>=0 && A[j] > x){
            porównania+=2;
            
            A[j+1]=A[j];
            przypisania++;
            
            j--;
            przypisania++;
            
            porównania++;
        }
        porównania++;
        A[j+1]=x;
        przypisania++;
        
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
        int wartosc =  rand() % 999 + 1;
        array1[i] = wartosc;
        array2[i] = wartosc;
    }   
    cout << "Pierwsze 30 elementów tablicy przed posortowaniem to: " << endl;
    for(int i = 0; i < min(30, n); i++) {
        cout << array1[i] << " ";
    }
    cout << endl << endl;
    
    // Zaczynamy porównania i przypisania inicjując jego wartość równą 0
    int por_1, por_2, prz_1, prz_2;
    por_1 = por_2 = prz_1 = prz_2 = 0;
    
    // funkcje na czas
    auto start1 = chrono::high_resolution_clock::now();
    insertion_sort(array1, n, por_1, prz_1);
    auto end1 = chrono::high_resolution_clock::now();
    auto czas1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

    auto start2 = chrono::high_resolution_clock::now();
    insertion_sort_2(array2, n, por_2, prz_2);
    auto end2 = chrono::high_resolution_clock::now();
    auto czas2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
    
    cout << "Tablica po sortowaniu przez insertion_sort(niezmodyfikowany):" << endl;
    for(int i = 0; i < min(30, n); i++) {
        cout << array1[i] << " ";
    }
    cout << endl;
    
    cout << "Tablica po sortowaniu przez insertion_sort(zmodyfikowany):" << endl;
    for(int i = 0; i < min(30, n); i++) {
        cout << array2[i] << " ";
    }
    cout << endl << endl;
    
    cout << "insertion_sort(niezmodyfikowany) ma " << por_1 << " porównań oraz " << prz_1 << " przypisań, a czas to: " << czas1.count() 
    << " mikrosekund, ponieważ ilość operacji to: "<< (por_1 + prz_1) << endl;
    cout << "insertion_sort(zmodyfikowany) ma " << por_2 << " porównań oraz " << prz_2 << " przypisań, a czas to:" << czas2.count()
    << " mikrosekund, ponieważ ilość operacji to: "<< (por_2 + prz_2) << endl;
    delete[] array1;
    delete[] array2;
    return 0;
}

