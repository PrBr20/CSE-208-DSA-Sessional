#include<iostream>
#include "queue_adt.cpp"

using namespace std;

template<typename E> class Link
{
public :
    E element;
    Link<E>* next;

    Link(const E& it, Link<E>* nextval)
    {
        element = it;
        next = nextval;
    }
    Link(){

    }
    Link<E> getNext()
    {
        return next;
    }
    Link<E> setNext(Link<E> nextval)
    {
        return next = nextval;
    }
    E getElement()
    {
        return element;
    }
    void setElement(E it)
    {
        element = it;
    }
};


template <typename E> class LQueue: public Queue<E>
{
private:
    Link<E>* front;
    Link<E>* rear;
    int size;
public:
    LQueue(int sz = 3)
    {
        front = rear = new Link<E>();
        size = 0;
    }
    ~LQueue()
    {
        clear();
        delete front;
    }
    void clear()
    {
        while(front->next != NULL)
        {
            rear = front;
            delete rear;
        }
        rear = front;
        size = 0;
    }
    void enqueue(const E& it)
    {
        rear->next = new Link<E>(it, NULL);
        rear = rear->next;
        size++;
    }
    E dequeue()
    {
        if(size == 0) return NULL;
        else {
            E it = front->next->element;
            Link<E>* ltemp = front->next;
            front->next = ltemp->next;
            if (rear == ltemp) rear = front;
            delete ltemp;
            size --;
            return it;
        }
    }
    virtual int length() const
    {
        return size;
    }
    const E& frontValue() const
    {
        if(size == 0) return -1;
        else return front->next->element;
    }
    const E& rearValue() const
    {
        if(size == 0) return -1;
        else return rear->element;
    }
    E leaveQueue(){
        if(this->length() == 0) return NULL;
        else{
            E it = rear->element;
            Link<E>* temp = front;
            while(temp->next != rear){
                temp = temp->next;
            }
            rear = temp;
            delete temp->next;
            size--;
            return it;
        }
    }
};


template <typename E> void print(LQueue<E>& qq){
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


int main(){
    LQueue<int> qu;


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
}
