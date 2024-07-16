#include<iostream>
#include"bst_adt.cpp"

using namespace std;

template <typename Key>
class BSTNode : public BinNode<Key>
{
private:
    Key k;
    BSTNode* lc;
    BSTNode* rc;
public:
    BSTNode()
    {
        lc = rc = NULL;
    }
    BSTNode(Key K, BSTNode* l = NULL, BSTNode* r = NULL)
    {
        k = K;
        lc = l;
        rc = r;
    }
    ~BSTNode() {}
    Key& key()
    {
        return k;
    }
    void setKey(const Key& K)
    {
        k = K;
    }
    inline BSTNode* left() const
    {
        return lc;
    }
    void setLeft(BinNode<Key>* b)
    {
        lc = (BSTNode*)b;
    }
    inline BSTNode* right() const
    {
        return rc;
    }
    void setRight(BinNode<Key>* b)
    {
        rc = (BSTNode*)b;
    }
    bool isLeaf()
    {
        return (lc == NULL) && (rc == NULL);
    }
};
