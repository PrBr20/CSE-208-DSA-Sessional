#include<iostream>
#include"LList.cpp"
#include"AList.cpp"


using namespace std;

template <typename E> class TNL {
    E Rs, Bs, Ts;
    int route;
public :
    TNL(int ri, int a[], int bu, int b[], int tr, int t[]){
        route = ri;
        for(int i=0; i<ri; i++) Rs.append(a[i]);
        for(int i=0; i<bu; i++) Bs.append(b[i]);
        for(int i=0; i<tr; i++) Ts.append(t[i]);
    }
    void print(){
        for(int i=0; i<route; i++){
            if(Rs.getValue() != i) cout << ",";
            else {
                cout << Rs.getValue();
                if(i != route - 1) cout << ",";
                Rs.next();
            }
        }
        cout << endl;
        for(int i=0; i<route; i++){
            if(Bs.getValue() != i) cout << ",";
            else {
                cout << Bs.getValue();
                if(i != route - 1) cout << ",";
                Bs.next();
            }
        }
        cout << endl;
        for(int i=0; i<route; i++){
            if(Ts.getValue() != i) cout << ",";
            else {
                cout << Ts.getValue();
                if(i != route - 1) cout << ",";
                Ts.next();
            }
        }
        cout << endl;
    }
};


int main(){
    /*int R, B, T;
    cin >> R >> B ;
    int b[B];
    for(int i=0; i<B; i++) cin >> b[i];
    cin >> T;
    int c[T];
    for(int i=0; i<T; i++) cin >> c[i];
    int a[R];
    for(int i=0; i<R; i++) a[i] = i;

    TNL<AList<int>> Transit(R, a, B, b, T, c);

    int q;
    while(1){
        cin >> q;
        if(q == 0) break;
        else if(q == 1) Transit.print();
    }*/


    int k,x;
    cin >> k;
    int a[k];
    for(int i=0; i<k; i++) cin >> a[i];

    LList<int> list(k,a);
    print(list);

    int q,p;
    while(1){
        cin >> q >> p;
        if(q == 0) break;
        else if(q == 1) {
            list.clear();
            print(list);
            cout << -1 << endl;
        }
        else if(q == 2) {
            list.insert(p);
            print(list);
            cout << -1 << endl;
        }
        else if(q == 3) {
            list.append(p);
            print(list);
            cout << -1 << endl;
        }
        else if(q == 4) {
            int x = list.remove();
            print(list);
            cout << x << endl;
        }
        else if(q == 5) {
            list.moveToStart();
            print(list);
            cout << -1 << endl;
        }
        else if(q == 6) {
            list.moveToEnd();
            print(list);
            cout << -1 << endl;
        }
        else if(q == 7) {
            list.prev();
            print(list);
            cout << -1 << endl;
        }
        else if(q == 8) {
            list.next();
            print(list);
            cout << -1 << endl;
        }
        else if(q == 9) {
            print(list);
            cout << list.length() << endl;
        }
        else if(q == 10) {
            print(list);
            cout << list.currPos() << endl;
        }
        else if(q == 11) {
            list.moveToPos(p);
            print(list);
            cout << -1 << endl;
        }
        else if(q == 12) {
            print(list);
            cout << list.getValue() << endl;
        }
        else if(q == 13) {
            print(list);
            cout << list.search(p) << endl;
        }
    }


    return  0;

}
