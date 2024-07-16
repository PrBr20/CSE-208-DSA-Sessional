#include<iostream>
#include"Aqueue.cpp"

using namespace std;

int main(){
    AQueue<int> booth1, booth2;

    int n;
    cin >> n;
    int arr1[n], arr2[n];
    for(int i=0; i<n; i++) cin >> arr1[i] >> arr2[i];

    int b1, b2, curr = 0, t1, t2;
    b1 = b2 = 0;
    t1 = t2 = 0;
    for(int i=0; ; i++){
        if(booth1.length() != 0) t1++;
        if(booth2.length() != 0) t2++;
        if(t1 == booth1.frontValue()) {
            booth1.dequeue(); t1 = 0; b1 = i;
        }
        if(t2 == booth2.frontValue()) {
            booth2.dequeue(); t2 = 0; b2 = i;
        }
        while(curr < n && arr1[curr] ==  i){
            if(booth1.length() <= booth2.length()){
                booth1.enqueue(arr2[curr]);
            }
            else {
                booth2.enqueue(arr2[curr]);
            }
            curr++;
        }
        while(booth1.length() - 1 > booth2.length()){
            booth2.enqueue(booth1.leaveQueue());
        }
        while(booth2.length() - 1 > booth1.length()){
            booth1.enqueue(booth2.leaveQueue());
        }
        if(booth1.length() == 0 && booth2.length() == 0 && curr == n) break;
    }

    cout << "Booth 1 finishes service at t = " << b1 << endl;
    cout << "Booth 2 finishes service at t = " << b2 << endl;
}

