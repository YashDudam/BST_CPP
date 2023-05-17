#ifndef NODE_HPP
#define NODE_HPP

class Node {
private:
    int key;
    Node *left;
    Node *right;
    int height;

public:
    int key();
    int height();
    Node *left();
    Node *right();
};

#endif
