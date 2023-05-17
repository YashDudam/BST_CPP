#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"

class Tree {
private:
    Node *root_;

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
