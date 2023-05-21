# BST_CPP
Date Started: 16/05/2023
Join me as I learn C++ and apply some object-oriented principles :).

This is an implementation of a binary search tree using C++.

## What do I want to achieve?

The goal is to learn and practise solving problems with C++ and utilise the object-oriented programming
features provided. I've chosen an AVL binary search tree data structure to implement in C++ using
classes and objects. I chose this data structure since it's a moderately difficult structure to implement 
that gives me some exposure to how memory works in C++ and it makes sense why classes would be used to 
implement a binary search tree. Hopefully by the end of this mini-project I'll have a working understanding
of C++ in general, as well as the industry practises surrounding solving problems in an object-oriented manner.

## How am I going to use object-oriented principles?

I'll need a tree class to hold the information, left and right nodes, and height. Then define methods
to interact with the BST. That covers encapsulation and abstraction, but how would I apply polymorphism
and inheritance? 

Polymorphism could be used to make a binary search tree with multiple types, using function overloading, but
that just means writing the same function with different types. Maybe we can use (void *)? but that loses 
all type safety. Maybe there is a better C++ equivelent to (void *)? Further investigation is required.

## How will the BST handle initialising an empty tree?

This is easy in C, using a tree struct that holds the root of the BST and optionally some additional information 
like size. The root node would house the information, left and right pointers. How would something similar be 
implemented using classes in C++? Maybe a tree class that holds a pointer to a node object, but then how would I
access the node's members? Maybe inheritance could help but it doesn't make sense for a parent class to access the
members of a child class. I think the best thing to do is to create a tree class that has a pointer to a node object 
and use accessor and mutator functions to interact with the data of the node object.

UPDATE: Using a Tree class that holds a struct node as a private member seems to be the best way to go about this.
This will have the effect of encapsulating the node information, while allowing my tree methods to access the 
node. Why complicate things you don't have to?

## What else can I learn?

 - How do I use the catch testing framework?
 - How are namespaces used?
 - What are STL containers?

## Progress Log:
16/05/2023
 - It hath begun
 - Started working out the plan, how to approach this problem and what features can we use to solve it.
 - Created stub files for the Tree and Node classes.

17/05/2023
 - Created a Makefile to manage our dependencies. This isn't really needed since we only have one dependancy, but 
   it'll speed up compilation and it is a good automation that'll prove useful for larger projects in the future.
 - Deleted the Node.cpp and Node.hpp files since we are no longer using a node class, but instead a struct node
 - Designed the tree class. Added the necessary private members and public methods.

20/05/2023
 - Fully implemented all public methods.
 - We're done!!!...jokes we can make a lot of improvements

## Improvements to be made
 - Write more C++ style code (use "const", and "auto")
 - Learn templates to make our binary search tree take multiple types as an input. Should also use a compare function instead.
 - Learn CMake to build program. Not necessary for a small project but is needed for larger projects
 - Use catch testing framework
