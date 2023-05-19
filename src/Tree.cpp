#include <cstdlib>

#include "Tree.hpp"

Tree::node::node(int key) : key_(key), left_(nullptr), right_(nullptr), height_(0) {}

Tree::Tree() : root_(nullptr) {}

Tree::Tree(int key) {
    root_ = new node(key);
}

bool Tree::search(int key) {
    return do_search(root_, key);
}

bool Tree::do_search(node *n, int key) {
    if (n == nullptr) return false;

    if (key < n->key_) {
        return do_search(n->left_, key);
    } else if (key > n->key_) {
        return do_search(n->right_, key);
    } else {
        return true;
    }
}

bool Tree::insert(int key) {
    bool status = false;
    root_ = do_insert(root_, key, status);
    return status;
}

Tree::node *Tree::do_insert(node *n, int key, bool &status) {
    if (n == nullptr) {
        status = true;
        return new node(key);
    }

    if (key < n->key_) {
        return do_insert(n->left_, key, status);
    } else if (key > n->key_) {
        return do_insert(n->right_, key, status);
    } else {
        status = false;
        return n;
    }

    update_height(n);
    int bal = balance(n);
    
}

int Tree::max(int a, int b) {
    return (a > b) ? a : b;
}

int Tree::balance(node *n) {
    int left = (n->left_ == nullptr) ? -1 : n->left_->height_;
    int right = (n->right_ == nullptr) ? -1 : n->right_->height_;

    return left - right;
}
