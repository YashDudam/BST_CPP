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

How will the BST handle initialising an empty tree? This is easy in C, using a tree struct that holds the 
root of the BST and optionally some additional information like size. The root node would house the information, 
left and right pointers. How would something similar be implemented using classes in C++? Maybe a tree class that 
holds a pointer to a node object, but then how would I access the node's members? Maybe inheritance could help 
but it doesn't make sense for a parent class to access the members of a child class. I think the best thing to do
is to create a tree class that has a pointer to a node object and use accessor and mutator functions to interact
with the data of the node object.

## What else can I learn?

 - How do I use the catch testing framework?
 - How are namespaces used?
 - What are STL containers?

## Progress Log:
16/05/2023
 - It hath begun
 - Started working out the plan, how to approach this problem and what features can we use to solve it.
 - Created stub files for the Tree and Node classes.