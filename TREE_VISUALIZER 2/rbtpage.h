#ifndef RBTPAGE_H
#define RBTPAGE_H

#include <QWidget>
#include <QGraphicsScene>

// Add these constants at the top of your rbtpage.h file
const bool RED = true;
const bool BLACK = false;

// Modify your RBTreeNode structure in rbtpage.h
struct RBTreeNode {
    int value;
    bool color;
    RBTreeNode* parent;
    RBTreeNode* left;
    RBTreeNode* right;

    RBTreeNode(int val)
        : value(val)
        , color(RED)
        , parent(nullptr)
        , left(nullptr)
        , right(nullptr) {}
};

namespace Ui {
class rbtpage;
}

class rbtpage : public QWidget
{
    Q_OBJECT

public:
    explicit rbtpage(QWidget *parent = nullptr);
    ~rbtpage();


    Ui::rbtpage *ui;
    RBTreeNode* root;

    RBTreeNode* insertNode(RBTreeNode* node, int value);
    void insertFixup(RBTreeNode* node);


    RBTreeNode* deleteNode(RBTreeNode* node, int value);
    void deleteFixup(RBTreeNode* &node, RBTreeNode* child);
    void leftRotate(RBTreeNode* x);
    void rightRotate(RBTreeNode* y);


    void drawTree();
    void drawNode(RBTreeNode* node, int x, int y, int xOffset);
    void displayInorderTraversal();
    void displayPreorderTraversal();
    void displayPostorderTraversal();
    void inorderTraversal(RBTreeNode* node, QString &result);
    void preorderTraversal(RBTreeNode* node, QString &result);
    void postorderTraversal(RBTreeNode* node, QString &result);

    void updateTraversalDisplay(const QString &text);
private:
    RBTreeNode* minimum(RBTreeNode* node);
    void transplant(RBTreeNode* &root,RBTreeNode* u, RBTreeNode* v);
    RBTreeNode* findNode(RBTreeNode* rot, int value);

private slots:
    void goBack();

};

#endif // RBTPAGE_H

