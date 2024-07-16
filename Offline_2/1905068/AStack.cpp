#include<iostream>
#include"Stack_Abstract.cpp"

using namespace std;


template <typename E> class AStack: public Stack<E>
{
private:
    int maxSize;
    int initSize;
    int top;
    E* listArray;
    void incSize(){
        cout << "foo" << endl;
        int sz = maxSize - top - 1;
        maxSize += initSize;
        E* tempArray = new E[maxSize];
        if(mode == -1){
            top = maxSize - sz - 1;
            for(int i=maxSize-1; i>top; i--){
                tempArray[i] = listArray[i - initSize];
            }
        }
        else {
            for(int i=0; i<top; i++){
                tempArray[i] = listArray[i];
            }
        }
        delete[] listArray;
        listArray = tempArray;
    }
public:
    int mode;
    AStack(int size = 10)
    {
        mode = 1;
        initSize = size;
        maxSize = size;
        top = 0;
        listArray = new E[maxSize];
    }
    AStack(E* givenArray, int sz, int dir){
        listArray = givenArray;
        maxSize = sz;
        if(dir == -1) {
            mode = -1;
            top = maxSize - 1;
        }
        else {
            mode = 1;
            top = 0;
        }
    }
    ~AStack()
    {
        delete [] listArray;
    }
    void clear()
    {
        top = 0;
    }
    void push(const E& it)
    {
        if(mode == 1){
            if(top == maxSize) incSize();
            listArray[top++] = it;
        }
        else if (mode == -1){
            if(top == 0) incSize();
            listArray[top--] = it;
        }
    }
    E pop()
    {
        if(mode == -1) return listArray[++top];
        else return listArray[--top];
    }
    const E& topValue() const
    {
        if(mode == -1) return listArray[top+1];
        else return listArray[top-1];
    }
    int length() const
    {
        if(mode == -1)return maxSize - top - 1;
        else return top;
    }
    void setDirection(const int x){
        if(this->length() == 0) {
            if(x == -1) {
                mode = -1;
                top = maxSize - 1;
            }
        }
    }
};


template <typename E> void print(AStack<E>& st){
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



/*int main(){
    int x;
    cin >> x;

    AStack<int> st(x);

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
        else if(p == 6){
            st.setDirection(q);
            print(st);
            cout << -1 << endl;
        }
    }
}*/
