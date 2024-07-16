#include<iostream>
#include"List_interface.cpp"

using namespace std;


template <typename E>
class AList : public List<E>
{
private:
    int initialSize;
    int currSize;
    int listSize;
    int curr;
    E* listArray;
    void incSize(){
        currSize += initialSize;
        E* tempArray = new E[currSize];
        for(int i=0; i<listSize; i++){
            tempArray[i] = listArray[i];
        }
        delete[] listArray;
        listArray = tempArray;
    }
public:
    AList(int arrSize, int chunckSize, E arr[])
    {
        initialSize = chunckSize;
        currSize = initialSize;
        listArray = new E[currSize];
        listSize = arrSize;
        curr = 0;
        for(int i=0; i<listSize; i++){
            listArray[i] = arr[i];
        }
    }
    AList(){
        initialSize = 10;
        currSize = 10;
        listArray = new E[currSize];
        listSize = 0;
        curr = 0;
    }
    ~AList()
    {
        delete [] listArray;
    }
    void clear()
    {
        delete [] listArray;
        listSize = curr = 0;
        listArray = new E[currSize];

    }
    void insert(const E& it)
    {
        if(listSize == currSize) incSize();
        for(int i=listSize; i>curr; i--)
            listArray[i] = listArray[i-1];
        listArray[curr] = it;
        listSize++;
    }
    void append(const E& it)
    {
        if(listSize == currSize) incSize();
        listArray[listSize++] = it;
    }
    E remove()
    {
        if(curr<0 || curr > listSize) cout << "No element\n";
        E it = listArray[curr];
        for(int i=curr; i<listSize-1; i++)
            listArray[i] = listArray[i+1];
        listSize--;
        if(listSize == curr) curr--;
        return it;
    }
    void moveToStart()
    {
        curr = 0;
    }
    void moveToEnd()
    {
        curr = listSize - 1;
    }
    void prev()
    {
        if (curr != 0) curr--;
    }
    void next()
    {
        if (curr < listSize) curr++;
    }
    int length()
    {
        return listSize;
    }
    int currPos()
    {
        return curr;
    }
    void moveToPos(int pos)
    {
        if(pos>=0 && pos<=listSize)curr = pos;
    }
    E getValue()
    {
        if(curr>=0 && curr<listSize) return listArray[curr];
        else return -1;

    }
    int search(const E& item){
        int pos = -1;
        for(int i=0; i<listSize; i++){
            if(listArray[i] == item) {
                pos = i;
                break;
            }
        }
        return pos;
    }
};


template <typename E>
void print(AList<E>& l){
    if(l.length() == 0){
        cout << "<>\n";
        return ;
    }
    int curr = l.currPos();
    l.moveToStart();
    cout << "<";
    for(int i=0 ;i<l.length(); i++){
        if(curr == i) cout << "| ";
        cout << l.getValue();
        if(i != l.length() - 1) cout << " ";
        l.next();
    }
    if(curr == l.length()) cout << "| ";
    cout << ">";
    cout << endl;
    l.moveToPos(curr);
}

