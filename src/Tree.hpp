#ifndef TREE_HPP
#define TREE_HPP

typedef struct node *Node;

class Tree {
private:
    struct node {
        int key;
        Node left;
        Node right;
    };

    Node root;
public:
    Tree();
    Tree(int key);

    ~Tree();

    bool search(int key);
    bool insert(int key);
    bool remove(int key);
    int kth_smallest(int k);
    int kth_largest(int k);
    int LCA(int a, int b);
    int floor(int key);
    int ceiling(int key);
};

#endif
