#include <iostream>
#include <string>

#include "Tree.hpp"

int main(void) {
    Tree tree(5);

    tree.insert(10);
    tree.insert(15);
    tree.insert(20);
    tree.insert(25);

    tree.print("i");

    std::cout << tree.kth_largest(6) << std::endl;
    std::cout << tree.kth_smallest(3) << std::endl;

    return 0;
}