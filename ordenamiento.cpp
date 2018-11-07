#include<iostream>
#define INFINITE 999999999999.0

using namespace std;

void mergeSort(int p, int r);
void merge(int p, int q, int r);
void quicksort(int p, int r);
int particion(int p, int r);
void imprimir(double a1[], string nombre);

double a[] = {4.0, 5.0, 7.0, 1.0, 6.0, 8.0, 2.0, 3.0, 
            10.0, 6.0, 12.0, 2.0, 7.0, 1.0, 10.0, 12.0, 2.0, 8.0, 1.0, 0.0};

double b[] = {4.0, 5.0, 7.0, 1.0, 6.0, 8.0, 2.0, 3.0, 
            10.0, 6.0, 12.0, 2.0, 7.0, 1.0, 10.0, 12.0, 2.0, 8.0, 1.0, 0.0};

int main(){
    mergeSort(0, 19);
    imprimir(a, "Merge Sort");

    quicksort(0, 19);
    imprimir(b, "Quick Sort");

    return 0;
}

void mergeSort(int p, int r){
    int q;
    if(p < r){
        q = (p+r)/2;
        mergeSort(p, q);
        mergeSort(q+1, r);
        merge(p, q, r);
    }
}

void merge(int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int i, j;

    double L[n1 + 1];
    double R[n2 + 1];

    for(i = 0; i < n1; i++){
        L[i] = a[p + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = a[q + j + 1];
    }

    L[n1] = INFINITE;
    R[n2] = INFINITE;
    i = 0;
    j = 0;

    for(int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }else{
            a[k] = R[j];
            j++;
        }
    }
}

void quicksort(int p, int r){
    if(p < r){
        int q = particion(p, r);
        quicksort(p, q - 1);
        quicksort(q + 1, r);
    }
}

int particion(int p, int r){
    double temp;
    double x = b[r];
    int i = p - 1;

    for(int j = p; j <= (r-1); j++){
        if(b[j] <= x){
            i++;
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    }
    temp = b[i+1];
    b[i+1] = b[r];
    b[r] = temp;

    return ++i;
}

void imprimir(double a1[], string nombre){
    cout<<nombre<<endl;
    for(int i = 0; i < 20; i++){
        cout<<a1[i]<<endl; 
    }
}