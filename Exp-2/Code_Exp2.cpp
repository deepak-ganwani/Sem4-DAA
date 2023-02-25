#include<bits/stdc++.h>
#include<chrono>
#include<fstream>
using namespace std;
void mergeSort(int arr[], int sInd, int eInd);
void merge(int arr[], int sInd, int mid, int eInd);
void quickSort(int arr[], int low, int high);

void mergeSort(int arr[], int sInd, int eInd) {
    if(sInd >= eInd) return;
    int mid=sInd+(eInd-sInd)/2;
    mergeSort(arr, sInd, mid);
    mergeSort(arr, mid+1, eInd);
    merge(arr, sInd, mid, eInd);
    return;
}

void merge(int arr[], int sInd, int mid, int eInd) {
    int i=sInd, j=mid+1, k=0;
    int arr1[eInd-sInd+1];
    while (i<mid+1 && j<eInd+1) {
        if(arr[i]<arr[j]) {
            arr1[k]=arr[i];
            k++;
            i++;
        }
        else {
            arr1[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<mid+1) {
        arr1[k]=arr[i];
        i++;
        k++;
    }
    while(j<eInd+1) {
        arr1[k]=arr[j];
        j++;
        k++;
    }
    k=0;
    for (i = sInd; i < eInd+1; i++)
    {
        arr[i]=arr1[k];
        k++;
    }
    
    return;
}

void quickSort(int arr[], int sInd, int eInd){
    if(sInd>=eInd) return;
    int low=sInd, high=eInd;
    int mid=low+(high-low)/2;
    int pivot=arr[mid];

    while(low<=high) {
        while(arr[low]<pivot) low++;
        while(arr[high]>pivot) high--;

        if(low<=high) {
            int temp=arr[low];
            arr[low]=arr[high];
            arr[high]=temp;
            low++;
            high--;
        }
    }
    
    quickSort(arr, sInd, high);
    quickSort(arr, low, eInd);
    return;
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
        arrayData<<array[i]<<","<<endl;
    }
    
    cout<<"n\tMergeSort\tQuickSort"<<endl;
    int prev=0;
    for (int i = 100; i < n+1; i+=100)
    {
        copy(array, array+n, arr1);
        copy(array, array+n, arr2);
        
        auto start= chrono::high_resolution_clock::now();
        mergeSort(arr1, 0, i-1);
        auto end= chrono::high_resolution_clock::now();
        output<<i<<", "<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<", ";
        cout<<i<<"\t"<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<"\t";

        start= chrono::high_resolution_clock::now();
        quickSort(arr2, 0, i-1);
        end= chrono::high_resolution_clock::now();
        output<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;
        cout<<chrono::duration_cast<chrono::microseconds>(end-start).count()<<endl;
    }
    
    arrayData.close();
    output.close();
}