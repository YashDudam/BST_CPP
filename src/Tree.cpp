#include <iostream>
#include <cstdlib>
#include <queue>

#include "Tree.hpp"

Tree::node::node(int key) : key_(key), left_(nullptr), right_(nullptr), height_(0) {}

Tree::Tree() : root_(nullptr) {}

Tree::Tree(int key) {
    root_ = new node(key);
}

Tree::~Tree() {
    delete_tree(root_);
}

void Tree::delete_tree(node *n) {
    if (n != nullptr) {
        delete_tree(n->left_);
        delete_tree(n->right_);
        delete n;
    }
}

void Tree::print(std::string order) {
    if (order == "preorder" || order == "pr") {
        preorder(root_);
    } else if (order == "inorder" || order == "i") {
        inorder(root_);
    } else if (order == "postorder" || order == "po") {
        postorder(root_);
    } else if (order == "levelorder" || order == "l") {
        levelorder();
    } else if (order == "visual" || order == "v") {
        visual(root_, 0);
    } else {
        std::cerr << "Invalid print option.\n";
        exit(EXIT_FAILURE);
    }
    std::cout << std::endl;
}

void Tree::inorder(node *n) {
    if (n != nullptr) {
        inorder(n->left_);
        std::cout << n->key_ << " ";
        inorder(n->right_);
    }
}

void Tree::preorder(node *n) {
    if (n != nullptr) {
        std::cout << n->key_ << " ";
        preorder(n->left_);
        preorder(n->right_);
    }
}

void Tree::postorder(node *n) {
    if (n != nullptr) {
        postorder(n->left_);
        postorder(n->right_);
        std::cout << n->key_ << " ";
    }
}

void Tree::levelorder() {
    std::queue<node *> q;
    q.push(root_);

    while (!q.empty()) {
        node *n = q.front();
        q.pop();

        std::cout << n->key_ << " ";

        if (n->left_ != nullptr) {
            q.push(n->left_);
        }
        if (n->right_ != nullptr) {
            q.push(n->right_);
        }
    }
}

void Tree::visual(node *n, int depth) {
    if (n != nullptr) {
        visual(n->right_, depth + 1);
        for (int i = 0; i < depth; i++) {
            std::cout << "\t";
        }
        std::cout << n->key_ << std::endl;
        visual(n->left_, depth + 1);
    }
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
        n->left_ = do_insert(n->left_, key, status);
    } else if (key > n->key_) {
        n->right_ = do_insert(n->right_, key, status);
    } else {
        return n;
    }

    update_height(n);
    int bal = balance(n);
    if (bal > 1) {
        if (key > n->left_->key_) {
            n->left_ = rotateLeft(n->left_);
        }
        n = rotateRight(n->left_);
    } else if (bal < -1) {
        if (key > n->right_->key_) {
            n->right_ = rotateRight(n->right_);
        }
        n = rotateLeft(n);
    }
    return n;
}

int Tree::max(int a, int b) {
    return (a > b) ? a : b;
}

int Tree::height(node *n) {
    return (n == nullptr) ? -1 : n->height_;
}

void Tree::update_height(node *n) {
    n->height_ = max(height(n->left_), height(n->right_)) + 1;
}

int Tree::balance(node *n) {
    return height(n->left_) - height(n->right_);
}

Tree::node *Tree::rotateLeft(node *n) {
    if (n == nullptr || n->right_ == nullptr) return n;

    node *new_root = n->right_;
    n->right_ = new_root->left_;
    new_root->left_ = n;

    update_height(n);
    update_height(new_root);

    return new_root;
}

Tree::node *Tree::rotateRight(node *n) {
    if (n == nullptr || n->left_ == nullptr) return n;

    node *new_root = n->left_;
    n->left_ = new_root->right_;
    new_root->right_ = n;

    update_height(n);
    update_height(new_root);

    return new_root;
}
