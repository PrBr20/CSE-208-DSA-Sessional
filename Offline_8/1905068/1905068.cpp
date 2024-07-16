#include<iostream>

using namespace std;

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

int main(){ 
    int n,k;
    cin >> n >> k;
    
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    quicksort(a, 0, n-1, 0);

    long long int ans = 0;
    int cnt = 1;
    
    // taking the elements with maximum values first. when all friends have same number of items count is increased. 
    for(int i=n-1; i>=0; i--){
        ans += cnt*a[i];
        if((n - i)%k == 0) cnt++;
    }
    cout << ans << endl;
}