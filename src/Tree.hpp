#ifndef TREE_HPP
#define TREE_HPP

class Tree {
private:
    struct node {
        int key_;
        node *left_;
        node *right_;
        int height_;

        node(int key);
    };
    node *root_;

    bool do_search(node *n, int key);
    node *do_insert(node *n, int key, bool &status);
    int max(int a, int b);
    void update_height(node *n);
    int balance(node *n);
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
