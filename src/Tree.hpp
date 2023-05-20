#ifndef TREE_HPP
#define TREE_HPP

#include <string>

#define UNDEFINED INT_MIN

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
    int size_;

    void destroy_tree(node *n);
    void inorder(node *n);
    void preorder(node *n);
    void postorder(node *n);
    void levelorder();
    void visual(node *n, int depth);
    bool do_search(node *n, int key);
    node *do_insert(node *n, int key, bool &status);
    int max(int a, int b);
    int height(node *n);
    void update_height(node *n);
    int balance(node *n);
    node *rotate_left(node *n);
    node *rotate_right(node *n);
    node *do_remove(node *n, int key, bool &status);
    node *tree_join(node *n1, node *n2);
    node *clean_tree(node *n);
    node *do_kth_smallest(node *n, int k, int &count, bool &found);
    node *do_kth_largest(node *n, int k, int &count, bool &found);
    int do_lca(node *n, int a, int b);
    int do_floor(node *n, int key);
    int get_smallest(node *n);
    int do_ceiling(node *n, int key);
    int get_largest(node *n);
public:
    Tree();
    Tree(int key);

    ~Tree();

    int size();
    void print(std::string order = "preorder");
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
