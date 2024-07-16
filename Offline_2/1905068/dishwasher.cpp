#include<iostream>
#include"AStack.cpp"
#include"LLStack.cpp"

using namespace std;

class Dish{
public:
    int person_id;
    int pushtime;
    int dish_no;
    int washed_time;

    Dish(){
        person_id = 0;
        pushtime = 0;
        dish_no = 0;
        washed_time = 0;
    }
    Dish(int a, int b, int c){
        person_id = a;
        pushtime = b;
        dish_no = c;
        washed_time = 0;
    }
    Dish(const Dish& d){
        person_id = d.person_id;
        pushtime = d.pushtime;
        dish_no = d.dish_no;
        washed_time = 0;
    }
};

int n,d;
int* a;
int* b;
int currtime = 0;


template <typename E> void push_dish(Dish dis, E& dirty, E& clean){
    if(currtime >= dis.pushtime) dirty.push(dis);
    else {
        while(currtime < dis.pushtime && dirty.length() != 0){
            Dish t = dirty.topValue();
            if(currtime <= t.pushtime) currtime = t.pushtime;
            currtime += a[t.dish_no - 1];
            t.washed_time = currtime - 1;
            clean.push(t);
            dirty.pop();
        }
        dirty.push(dis);
    }
}

template <typename E> void wash_remain(E& dirty, E& clean){
    while(dirty.length() != 0){
        Dish t = dirty.topValue();
        if(currtime < t.pushtime) currtime = t.pushtime;
        currtime += a[t.dish_no - 1];
        t.washed_time = currtime - 1;
        clean.push(t);
        dirty.pop();
    }
}

template <typename E> void show(E& dirty, E& clean){
    cout << clean.topValue().washed_time << endl;
    int len = clean.length();
    Dish* temp = new Dish[len];
    int j = 0;
    for(int i=0; i<len; i++){
        temp[i]= clean.topValue();
        if(temp[i].dish_no == d) b[j++] = temp[i].person_id;
        clean.pop();
    }
    for(int i = len-1; i>=0; i--) {
        clean.push(temp[i]);
        cout << temp[i].washed_time;
        if(i != 0) cout << ",";
    }
    cout << endl;

    if(b[n-1] != -1) cout << "Y\n";
    else cout << "N\n";

    for(int i=0; i<n; i++){
        cout << b[i];
        if(b[i+1] == -1) break;
        else cout << ",";
    }
    cout << endl;
    delete [] temp;
}


int main(){
    cin >> n >> d;

    a = new int[d];
    b = new int[n+1];
    //Dish* arr = new Dish[n*d+1];
    //AStack<Dish> dirty(arr, n*d+1, 1), clean(arr, n*d+1, -1);
    AStack<Dish> dirty, clean;

    for(int i=0; i<=n; i++) b[i] = -1;
    for(int i=0; i<d; i++) cin >> a[i];

    int k,t,x;
    while(1){
        cin >> k >> t >> x;
        if(k == 0) {
            wash_remain(dirty, clean);
            break;
        }
        Dish d(k,t,x);
        push_dish(d, dirty, clean);
    }

    show(dirty, clean);
}




