/////////////////////////////////////////////////////////////////////
/// Header for the N-Ary.c file
/// author: julie sojkowski jas7845@g.rit.edu
/// date: March 28, 2019
/////////////////////////////////////////////////////////////////////
#ifndef N_ARY_H
#define N_ARY_H


// definition for the NTree structure to be implemented
typedef struct NTree_S * NTree;		


// Definition for the helper Queue structure
typedef struct Queue_S * Queue;


// Function to create a NTree node
// @param name: the name of the tree
// @return: the created NTree
NTree create_node( char name[]);


// Function to free all dynamic memory in the tree
// @param tree: the tree to free
void destroy(NTree tree);


// Funciton to find a node in the tree
// @param tree: the tree to search through
// @param name: the name of the person to find
// @return: the node of the person if found or NULL
NTree find_node( NTree tree, char name[]);


// Funciton to print the tree
// @param tree: the tree to print
void print_tree(NTree tree);


// Function to add a child to the parent
// @param tree: the tree to edit
// @param parent_name: the name of the parent 
// @param child_name: the name of the child to add
// @return: the edited tree
NTree add_child( NTree tree, char parent_name[], char child_name[] );

#endif
