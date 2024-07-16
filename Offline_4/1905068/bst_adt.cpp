template <typename E> class BinNode
{
public:
    virtual ~BinNode() {}

    virtual BinNode* left() const = 0;

    virtual void setLeft(BinNode*) = 0;

    virtual BinNode* right() const = 0;

    virtual void setRight(BinNode*) = 0;

    virtual bool isLeaf() = 0;
};
