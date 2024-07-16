#include<iostream>
#include <cstdlib>
#include"bst_node.cpp"

using namespace std;


template <typename Key> class BST
{
private:
    BSTNode<Key>* root;
    int nodecount;
    BSTNode<Key>* getroot(){ return root; }

    BSTNode<Key>* deletemin(BSTNode<Key>* rt)
    {
        if (rt->right() == NULL)
            return rt->left();
        else
        {
            rt->setRight(deletemin(rt->right()));
            return rt;
        }
    }
    BSTNode<Key>* deletemax(BSTNode<Key>* rt)
    {
        if (rt->right() == NULL)
            return rt->left();
        else
        {
            rt->setRight(deletemax(rt->right()));
            return rt;
        }
    }
    BSTNode<Key>* getmin(BSTNode<Key>* rt)
    {
        if (rt->left() == NULL)
            return rt;
        else return getmin(rt->left());
    }
    BSTNode<Key>* getmax(BSTNode<Key>* rt)
    {
        if (rt->right() == NULL)
            return rt;
        else return getmax(rt->right());
    }
public:
    BST()
    {
        root = NULL;
        nodecount = 0;
    }
    ~BST()
    {
        clearhelp(root);
    }
    // traverse
    void traverse(string s2){
        if(s2 == "Pre")
        {
            preorder(root);
        }
        else if(s2 == "Post")
        {
            postorder(root);
        }
        else if(s2 == "In")
        {
            inorder(root);
        }
        cout << endl;
    }
    // pre order
    void preorder(BSTNode<Key>* root)
    {
        if (root == NULL) return;
        cout << root->key() << " ";
        preorder(root->left());
        preorder(root->right());

    }
    // post order
    void postorder(BSTNode<Key>* root)
    {
        if (root == NULL) return;
        postorder(root->left());
        postorder(root->right());
        cout << root->key() << " ";
    }
    // in order
    void inorder(BSTNode<Key>* root)
    {
        if (root == NULL) return;
        inorder(root->left());
        cout << root->key() << " ";
        inorder(root->right());
    }

    // clear
    void clear()
    {
        clearhelp(root);
        root = NULL;
        nodecount = 0;
    }
    void clearhelp(BSTNode<Key>* root)
    {
        if (root == NULL) return;
        clearhelp(root->left());
        clearhelp(root->right());
        delete root;
    }
    //
    // insert
    void insert(const Key& k)
    {
        root = inserthelp(root, k);
        nodecount++;
    }
    BSTNode<Key>* inserthelp(BSTNode<Key>* root, const Key& k)
    {
        if (root == NULL)
            return new BSTNode<Key>(k, NULL, NULL);
        if (k < root->key())
            root->setLeft(inserthelp(root->left(), k));
        else root->setRight(inserthelp(root->right(), k));
        return root;
    }
    //
    // remove
    bool remove(const Key& k)
    {
        BSTNode<Key>* temp = findhelp(root, k);
        if (temp != NULL)
        {
            root = removehelp(root, k);
            nodecount--;
            return true;
        }
        else if(temp == NULL) return false;
    }
    BSTNode<Key>* removehelp(BSTNode<Key>* rt, const Key& k)
    {
        if (rt == NULL) return NULL;
        else if (k < rt->key())
            rt->setLeft(removehelp(rt->left(), k));
        else if (k > rt->key())
            rt->setRight(removehelp(rt->right(), k));
        else
        {
            BSTNode<Key>* temp = rt;
            if (rt->left() == NULL)
            {
                rt = rt->right();
                delete temp;
            }
            else if (rt->right() == NULL)
            {
                rt = rt->left();
                delete temp;
            }
            else
            {
                BSTNode<Key>* temp = getmax(rt->left());
                rt->setKey(temp->key());
                rt->setLeft(deletemax(rt->left()));
                delete temp;
            }
        }
        return rt;
    }

    //
    // find
    bool find(const Key& k) const {
         return findhelp(root, k) != NULL;
    }
    BSTNode<Key>* findhelp(BSTNode<Key>* root, const Key& k) const {
        if (root == NULL) return NULL;
        if (k < root->key())
            return findhelp(root->left(), k);
        else if (k > root->key())
            return findhelp(root->right(), k);
        else return root;
    }
    //
    int size()
    {
        return nodecount;
    }
    // print
    void print() const {
        if (root != NULL)
        {
            printhelp(root, 0);
            cout << endl;
        }
    }
    void printhelp(BSTNode<Key>* root, int level) const {
        if (root == NULL) return;
        cout << root->key();
        if(root->left() == NULL && root->right() == NULL) return;
        cout << "(";
        printhelp(root->left(), level+1);
        cout << ")";
        cout << "(";
        printhelp(root->right(), level+1);
        cout << ")";
    }
    //
};


int main(){
    string s1, s2;
    BST<int> b;

    while(1){
        cin >> s1 >> s2;
        if(s1 == "I"){
            int a = stoi(s2);
            b.insert(a);
            b.print();
        }
        else if(s1 == "D"){
            int a = stoi(s2);
            if(b.remove(a))b.print();
            else cout << "Invalid Operation\n";
        }
        else if(s1 == "F"){
            int a = stoi(s2);
            if(b.find(a)) cout << "True\n";
            else cout << "False\n";
        }
        else if(s1 == "T"){
            b.traverse(s2);
        }
        else if(s1 == "0") break;
    }
}
