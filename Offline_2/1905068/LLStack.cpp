#include<iostream>
#include"Stack_Abstract.cpp"

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



template <typename E> class LLStack: public Stack<E>
{
private:
    Link<E>* top;
    int size;
public:
    LLStack(int sz = 10)
    {
        top = NULL;
        size = 0;
    }
    ~LLStack()
    {
        clear();
    }
    void clear()
    {
        while (top != NULL)
        {
            Link<E>* temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
    }
    void push(const E& it)
    {
        top = new Link<E>(it, top);
        size++;
    }
    E pop()
    {
        if(size != 0){
            E it = top->element;
            Link<E>* ltemp = top->next;
            delete top;
            top = ltemp;
            size--;
            return it;
        }
    }
    const E& topValue() const
    {
        if(size != 0)return top->element;
    }
    int length() const
    {
        return size;
    }
};


template <typename E> void print(LLStack<E>& st){
    int len = st.length();
    E* temp = new E[len];
    cout << "<";
    for(int i=0; i<len; i++){
        temp[i]= st.topValue();
        st.pop();
    }
    for(int i = len-1; i>=0; i--) {
        st.push(temp[i]);
        cout << temp[i];
        if(i != 0) cout << ", ";
    }
    delete [] temp;
    cout << ">\n";
}


int main(){
    int x;
    cin >> x;

    LLStack<int> st(x);

    int p, q;
    while(1){
        cin >> p >> q;
        if(p == 0) break;
        else if(p == 1){
            st.clear();
            print(st);
            cout << -1 << endl;
        }
        else if(p == 2){
            st.push(q);
            print(st);
            cout << -1 << endl;
        }
        else if(p == 3){
            int f = st.pop();
            print(st);
            cout << f << endl;
        }
        else if(p == 4){
            int f = st.topValue();
            print(st);
            cout << f << endl;
        }
        else if(p == 5){
            int f = st.length();
            print(st);
            cout << f << endl;
        }
    }
}
