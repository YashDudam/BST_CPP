#include "Tree.hpp"

Tree::node::node(int key) : key_(key) {}

Tree::Tree() : root_(nullptr) {}

Tree::Tree(int key) {
    node *n = new node(key);
}
