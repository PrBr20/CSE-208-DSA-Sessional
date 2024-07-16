#include<iostream>
#include "queue_adt.cpp"

using namespace std;


template <typename E> class AQueue: public Queue<E>
{
private:
    int initSize, maxSize;
    int front;
    int rear;
    E *listArray;
    void Isize(){
        int sz = this->length(), prevm = maxSize;
        maxSize += initSize;
        E* temp = new E[maxSize];
        rear = 0;
        for(int i=0; i<sz; i++){
            rear = (rear+1) % maxSize;
            temp[rear] = listArray[front];
            front = (front+1) % prevm;
        }
        delete [] listArray;
        listArray = temp;
        front = 1;
    }
public:
    AQueue(int size = 3)
    {
        initSize = size;
        maxSize = size+1;
        rear = 0;
        front = 1;
        listArray = new E[maxSize];
    }
    ~AQueue()
    {
        delete [] listArray;
    }
    void clear()
    {
        rear = 0;
        front = 1;
    }
    void enqueue(const E& it)
    {
        if((rear+2) % maxSize == front) Isize();
        rear = (rear+1) % maxSize;
        listArray[rear] = it;
    }
    E dequeue()
    {
        if(this->length() == 0) return NULL;
        else {
            E it = listArray[front];
            front = (front+1) % maxSize;
            return it;
        }
    }
    virtual int length() const
    {
        return ((rear+maxSize) - front + 1) % maxSize;
    }
    E frontValue() const
    {
        if(this->length() == 0) return -1;
        else return listArray[front];
    }
    const E& rearValue() const
    {
        if(this->length() == 0) return -1;
        else return listArray[rear];
    }
    E leaveQueue(){
        if(this->length() == 0) return NULL;
        else{
            E it = listArray[rear];
            rear = (rear-1+maxSize) % maxSize;
            return it;
        }
    }
};

template <typename E> void print(AQueue<E>& qq){
    int sz = qq.length();
    cout << "<";
    while(sz--){
        E it = qq.dequeue();
        cout << it;
        if(sz != 0) cout << ", ";
        qq.enqueue(it);
    }
    cout << ">\n";
}


/*int main(){
    AQueue<int> qu;


    int p,q;
    while(1){
        cin >> p >> q;
        if(p == 1) {
            qu.clear();
            print(qu);
            cout << -1 << endl;
        }
        else if(p == 2) {
            qu.enqueue(q);
            print(qu);
            cout << -1 << endl;
        }
        else if(p == 3) {
            int elem = qu.dequeue();
            print(qu);
            cout << elem << endl;
        }
        else if(p == 4) {
            int len = qu.length();
            print(qu);
            cout << len << endl;
        }
        else if(p == 5) {
            int elem = qu.frontValue();
            print(qu);
            cout << elem << endl;
        }
        else if(p == 6) {
            int elem = qu.rearValue();
            print(qu);
            cout << elem << endl;
        }
        else if(p == 7) {
            int elem = qu.leaveQueue();
            print(qu);
            cout << elem << endl;
        }
        else if(p == 0) break;
    }
}*/
