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
    destroy_tree(root_);
}

void Tree::destroy_tree(node *n) {
    if (n != nullptr) {
        destroy_tree(n->left_);
        destroy_tree(n->right_);
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
            n->left_ = rotate_left(n->left_);
        }
        n = rotate_right(n->left_);
    } else if (bal < -1) {
        if (key > n->right_->key_) {
            n->right_ = rotate_right(n->right_);
        }
        n = rotate_left(n);
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

Tree::node *Tree::rotate_left(node *n) {
    if (n == nullptr || n->right_ == nullptr) return n;

    node *new_root = n->right_;
    n->right_ = new_root->left_;
    new_root->left_ = n;

    update_height(n);
    update_height(new_root);

    return new_root;
}

Tree::node *Tree::rotate_right(node *n) {
    if (n == nullptr || n->left_ == nullptr) return n;

    node *new_root = n->left_;
    n->left_ = new_root->right_;
    new_root->right_ = n;

    update_height(n);
    update_height(new_root);

    return new_root;
}

bool Tree::remove(int key) {
    bool status = false;
    root_ = do_remove(root_, key, status);
    return status;
}

Tree::node *Tree::do_remove(node *n, int key, bool &status) {
    if (n != nullptr) {
        if (key < n->key_) {
            n->left_ = do_remove(n->left_, key, status);
            update_height(n);
            n = clean_tree(n);
        } else if (key > n->key_) {
            n->right_ = do_remove(n->right_, key, status);
            update_height(n);
            n = clean_tree(n);
        } else {
            status = true;
            Tree::node *temp = tree_join(n->left_, n->right_);
            free(n);
            n = temp;
        }
    }
    return n;
}

Tree::node *Tree::tree_join(node *n1, node *n2) {
    if (n1 == nullptr) return n2;
    if (n2 == nullptr) return n1;

    Tree::node *curr = n2;
    Tree::node *parent = nullptr;
    while (curr->left_ != nullptr) {
        parent = curr;
        curr = curr->left_;
    }
    if (parent != nullptr) {
        parent->left_ = curr->right_;
        curr->right_ = n2;
        update_height(parent);
    }
    curr->left_ = n1;
    update_height(curr);

    return curr;
}

Tree::node *Tree::clean_tree(node *n) {
    int bal = balance(n);
    if (bal > 1) {
        if (balance(n->left_) < 0) {
            n->left_ = rotate_left(n->left_);
        }
        return rotate_right(n);
    } else if (bal < -1) {
        if (balance(n->right_) > 0) {
            n->right_ = rotate_right(n->right_);
        }
        return rotate_left(n);
    }
    return n;
}

int Tree::kth_smallest(int k) {
    int count = 0;
    bool found = false;
    Tree::node *small = do_kth_smallest(root_, k, count, found);
    return small->key_;
}

Tree::node *Tree::do_kth_smallest(node *n, int k, int &count, bool &found) {
    node *small = NULL;
    if (n != nullptr) {
        small = do_kth_smallest(n->left_, k, count, found);
        count++;
        if (!found) {
            if (k == count) {
                found = true;
                return n;
            }
            small = do_kth_smallest(n->right_, k, count, found);
        }
    }
    return small;
}

int Tree::kth_largest(int k) {
    int count = 0;
    bool found = false;
    node *large = do_kth_largest(root_, k, count, found);
    return large->key_;
}

Tree::node *Tree::do_kth_largest(node *n, int k, int &count, bool &found) {
    node *large = nullptr;
    if (n != nullptr) {
        large = do_kth_largest(n->right_, k, count, found);
        count++;
        if (!found) {
            if (k == count) {
                found = true;
                return n;
            }
            large = do_kth_largest(n->left_, k, count, found);
        }

    }
    return large;
}
