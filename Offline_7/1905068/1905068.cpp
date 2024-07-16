#include<iostream>
#include<fstream>
#include<algorithm>
#include<utility>
#include<chrono>
using namespace std;
using namespace std::chrono;

void mergesort(int arr[], int temp[], int left, int right){
    if(left == right) return;
    int mid = (left + right) / 2;
    mergesort(arr, temp, left, mid);
    mergesort(arr, temp, mid+1, right);

    for(int i=left; i<=right; i++) temp[i] = arr[i];
    int i1 = left, i2 = mid + 1;
    for(int curr = left; curr <= right; curr++){
        if(i1 == mid + 1) arr[curr] = temp[i2++];
        else if(i2 > right) arr[curr] = temp[i1++];
        else{
            if(temp[i1] <= temp[i2]) arr[curr] = temp[i1++];
            else arr[curr] = temp[i2++];
        }
    }
}

void quicksort(int arr[], int left, int right, int op){
    if(right <= left) return;
    int pivot;
    if(op == 1) pivot = right;
    else {
        pivot = rand()%(right - left + 1) + left;
        swap(arr[pivot], arr[right]);
        pivot = right;
    }

    int i1 = left - 1, i2 = right;
    do{
        while(arr[++i1] < arr[pivot]);
        while(i1<i2 && arr[pivot] < arr[--i2]);
        swap(arr[i1], arr[i2]);
    }while(i1 < i2);

    swap(arr[right], arr[i1]);
    quicksort(arr,left, i1-1, op);
    quicksort(arr, i1+1, right, op);
}

void insertionsort(int arr[], int n){
    for(int i=0; i<n; i++){
        int mn = arr[i], ind = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < mn){
                mn = arr[j];
                ind = j;
            }
        }
        swap(arr[i], arr[ind]);
    }
}

void sort_selction(int param, int arr[], int temp[], int n){
    if(param == 1){
        mergesort(arr, temp, 0, n-1);
    }
    else if(param == 2){
        quicksort(arr, 0, n-1, 1);
    }
    else if(param == 3){
        quicksort(arr, 0, n-1, 0);
    }
    else if(param == 4){
        insertionsort(arr, n);
    }
    else if(param == 5){
        quicksort(arr, 0, n-1, 1);
    }
    else if(param == 6){
        quicksort(arr, 0, n-1, 0);
    }
    else if(param == 7){
        sort(arr, arr+n);
    }
}


int main(){
    int n[6] = {5,10,100,1000,10000,100000};

    fstream fout;
    fout.open("runtime_table.csv", ios::out | ios::app);
    fout << ",Time required in ms,,,,,," << "\n";
    fout << "n,Merge Sort,Quicksort,Randomized quicksort,Insertion Sort,Quicksort with Sorted Input,Randomized Quicksort with Sorted Input,STL sort() function\n";

    for(int i=0; i<6; i++){
        fout << n[i] << ",";
        for(int j=1; j<=7; j++){
            double total = 0;
            for(int k=0; k<20; k++) {
                srand(k*100+2);
                int arr[n[i]];
                for(int l=0; l<n[i]; l++) arr[l] = rand();
                if(j == 5 || j == 6) sort(arr, arr+n[i]);
                int temp[n[i]];
                auto start = high_resolution_clock::now();
                sort_selction(j, arr, temp, n[i]);
                auto stop = high_resolution_clock::now();
                double duration = duration_cast<milliseconds> (stop - start).count();
                total += duration;
            }
            fout << total*1.0/20;
            if(j != 7) fout << ",";
        }
        fout << "\n";
    }
}
