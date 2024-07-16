#include<iostream>
using namespace std;

class Heap{
    int h_size;
    int* arr;
    void upshift(int ind){
        if(ind != 0){
            if(arr[(ind - 1)/2] < arr[ind]){
                int te = arr[ind];
                arr[ind] = arr[(ind - 1)/2];
                arr[(ind - 1)/2] = te;
                upshift((ind - 1)/2);
            }
        }
    }
    void buildheap(){
        for(int i = h_size/2 - 1; i>=0; i--) downshift(i);
    }
    void downshift(int ind){
        int l = 2*ind+1, r = 2*ind+2, largest;
        if(l < h_size && arr[l] > arr[ind]) largest = l;
        else largest = ind;
        if(r < h_size && arr[r] > arr[largest]) largest = r;

        if(largest != ind){
            int te = arr[ind];
            arr[ind] = arr[largest];
            arr[largest] = te;
            downshift(largest);
        }
    }
public:
    Heap(int h_size){
        arr = new int[h_size];
        this->h_size = 0;
    }
    Heap(vector<int>& v){
        h_size = v.size();
        arr = new int[h_size];
        for(int i=0; i<h_size; i++) arr[i] = v[i];
        buildheap();
    }
    ~Heap(){
        delete[] arr;
    }
    void insert(int val){
        arr[h_size] = val;
        h_size++;
        upshift(h_size-1);
    }
    int getMax(){
        return arr[0];
    }
    void deleteKey(){
        arr[0] = arr[h_size - 1];
        h_size--;
        downshift(0);
    }
    int size(){
        return h_size;
    }
};


void heapsort(vector<int>& v){
    Heap h(v);

    for(int i=0; i<v.size(); i++){
        v[i] = h.getMax();
        h.deleteKey();
    }
}
