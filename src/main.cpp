#include <iostream>
#include <string>

#include "Tree.hpp"

int main(void) {
    Tree tree(5);

    tree.insert(10);
    tree.insert(15);

    tree.print();

    return 0;
}