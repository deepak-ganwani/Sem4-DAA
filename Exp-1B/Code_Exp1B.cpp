#include<bits/stdc++.h>
#include<chrono>
#include<fstream>
using namespace std;
void swap(int arr[], int ind1, int ind2);
int minInd(int arr[], int sInd, int eInd);
void selectionSort(int arr[]);
void insertionSort(int arr[]);

void selectionSort(int arr[], int len){
    for(int i=0; i<len-1; i++){
        int min=minInd(arr, i, len-1);
        swap(arr, min, i);
    }
}

int minInd(int arr[], int sInd, int eInd){
    int min=sInd;
    for(int i=sInd; i<eInd+1; i++){
        if(arr[i]<arr[min]) min=i;
    }
    return min;
}

void insertionSort(int arr[], int len) {
    for(int i=0; i<len-1; i++){
        for(int j=i+1; j>0; j--) {
            if(arr[j]<arr[j-1]) swap(arr, j, j-1);
            else break;
        }
    }
}

void swap(int arr[], int ind1, int ind2) {
    int temp=arr[ind1];
    arr[ind1]=arr[ind2];
    arr[ind2]=temp;
}

int main(){
    int n=100000;
    int array[n], arr1[n], arr2[n];

    ofstream arrayData;
    arrayData.open("arrayValues.csv");
    ofstream output;
    output.open("output.csv");

    for (int i = 0; i < n; i++)
    {
        array[i]=rand()%n;
        arrayData<<array[i]<<",\n";
    }
    
    cout<<"n\tSelectionSort\tInsertionSort"<<endl;
    int prev=0;
    for (int i = 100; i < n+1; i+=100)
    {
        copy(array, array+n, arr1);
        copy(array, array+n, arr2);

        auto start= chrono::high_resolution_clock::now();
        selectionSort(arr1, i);
        auto end= chrono::high_resolution_clock::now();
        output<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;
        cout<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;

        start= chrono::high_resolution_clock::now();
        insertionSort(arr2, i);
        end= chrono::high_resolution_clock::now();
        output<<i<<", "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<", ";
        cout<<i<<"\t"<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<"\t";

    }
    
    output.close();
    arrayData.close();
    return 0;
}