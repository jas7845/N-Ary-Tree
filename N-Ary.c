////////////////////////////////////////////////////////////////////
/// Implementation of the N-Ary.h file 
/// Implements an n-ary tree with functions to modify the tree
/// author: julie sojkowski jas7845@g.rit.edu
/// due: March 28, 2019
/////////////////////////////////////////////////////////////////////

#define _DEFAULT_SOURCE				// to use strdup()
#define max(a, b) (((a) > (b)) ? (a) : (b))	//finds the max of numbers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "N-Ary.h"				// include for N-Ary header


// structure for the N-Ary tree
typedef struct NTree_S {
      char * name;                      /// name of the person
      struct NTree_S ** children;       /// dynamic collection of children
      size_t child_count;               /// number of children
      size_t capacity;			/// capacity of the collection of children
}N; 

// structure for the Queue
typedef struct Queue_S{
        struct NTree_S ** nodes;	/// collection of NTree_S in the queue
        int size;			/// size of the queue
        int front;			/// index of first NTree in the queue
}Q;


// Fucntion to creat a dynamic NTree 
// @param name: the name to be assigned to the NTree
// @param capacity: the capacity of the collection of children
// @return: the tree that is created
NTree create_node( char name[]){
	NTree tree_node = NULL;
	if((tree_node = malloc(sizeof(struct NTree_S)))== NULL)
		return NULL;
	tree_node->children =  NULL;
	tree_node->name = strdup(name);
	tree_node->child_count = 0;
	return tree_node;
}


// Function to return the name of the tree
// @param tree: the tree to get the name of
// @return: the name of the tree
char * getName(NTree tree){
	return tree->name;
}


// Function to get the child count of the tree
// @param tree: the tree
// @return: the number of children
int getChildCount(NTree tree){
	return tree->child_count;
}


// Function to get the child of a tree
// @param tree: the tree
// @param i: the index the child is at
// @return: the child at the index
NTree getChild(NTree tree, int i){
	if(tree->children[i] == NULL)
		return NULL;
	return tree->children[i];
}


// Function to free all memory allocated to the tree
// @param tree: the tree
void destroy(NTree tree){
	for (unsigned int i = 0; i< tree->child_count; i++){
		if (tree != NULL){
			destroy(tree->children[i]);
		}
	}	
	free(tree->children);
	free(tree->name);
	free(tree);
}


// Function to free al dynamic memory for the queue
// @param q: the queue
void destroy_q(Queue q){

	for(int i = 0; i < q->size; i++){
              free(q->nodes[i]);
        }
        free(q->nodes);
        free(q);
}


// Function to get the front NTree in the queue
// @param q: the queue
// @return: the Ntree at the front
NTree front(Queue q){
        if(q->front != q->size){
		NTree n = q->nodes[q->front]; 
        	return n;
	}
	return NULL;
}


// Function to deqeue the first element in a queue
// @param q: the queue
void dequeue(Queue q){
        if(q->front != q->size){
		q->nodes[q->front] = NULL; 
		q->front= q->front +1;
	}
}


// Function to add a node to the end of the queue
// @param q: the queue
// @param node: the node to add
void enqueue(Queue q, NTree node){
	if(node != NULL){	
		q->size++;
		q->nodes = realloc(q->nodes, (sizeof(NTree)*(q->size)));
	        q->nodes[q->size - 1] = node;
	}
}


// Function to create and allocate memory to the queue
// @param tree: the tree used for the size of the queue
// @return: the queue
Queue makequeue(){

        Queue q = NULL;
        q = malloc(sizeof(struct Queue_S));
	q->nodes = malloc(sizeof(NTree));
        q->size = 0;
        q->front = 0;
        return q;
}


// Function using DFS to compute the height of the tree
// @param tree: the tree to find the height of
// @return: int the height of the tree
int height_node(NTree tree){
	
	int height = 0;
	if(tree->child_count == 0)
		return 0;
	else{
		for(unsigned int i = 0; i< tree->child_count; i++){
               		if(tree->children[i] != NULL){
				height = max(height, height_node(tree->children[i]));		
			}
		}
		return height +1;
	}	
}


// Function to compute the size of the tree
// @param tree: the tree
// @return the size of the tree and all sub children
int size_node(NTree tree){
	int tree_size= 0;
	NTree node = tree;
	Queue q = NULL;
        q = makequeue();
        enqueue(q,  node);
        while( q->size > 0){
                node = front(q);
                dequeue(q);
                if(node == NULL){ 
			free(q->nodes);
                        free(q);
			return tree_size;
		}
		tree_size++;
                if(node->child_count > 0){
                        for(unsigned int i = 0; i< node->child_count; i++){
                                if(node->children[i] != NULL){
                                        enqueue(q, node->children[i]);
                                }
                        }
                }
        }
	destroy_q(q);
	return tree_size;
}


// Function using BFS to find a node in the tree
// @param node: the tree node to search through
// @param name: the name to search for
// @return: the node with the name or NULL
NTree find_node( NTree node, char name[]){
	
	Queue q = NULL;
	q = makequeue();
	enqueue(q,  node);
	while( q->size > 0){
		node = front(q);
		dequeue(q);
		if(node == NULL)
			break;
		if (strcmp(node->name, name) == 0){
			free(q->nodes);
        		free(q);
			return node;
		}
		else{
			for(unsigned int i = 0; i< node->child_count; i++){
				if(node->children[i] != NULL){
					enqueue(q, node->children[i]);
				}
			}
		}
	}
	destroy_q(q);
	return NULL;
}


// Function to print the given Node and its children
// 	in format 'parent' had 'child 1' and 'child 2'...
// @param node: the node to print
void print_node(NTree node){

	printf("%s ", node->name);
	if(node->child_count > 0){
		printf("had ");
		for(unsigned int i = 0; i< node->child_count; i++){
        	                if(node->children[i] != NULL){
                	                printf("%s", node->children[i]->name);
					if (i == node->child_count - 1) printf(".\n");
                                	else printf(" and ");
                        	}
                }
	}
	else printf("had no offspring.\n");

}


// Function to print the given tree in BFS order
// @param tree: the tree 
void print_tree(NTree tree){
	
	NTree node = tree;
	Queue q = NULL;
        q = makequeue();
        enqueue(q,  node);
        while( q->size > 0){
                node = front(q);
                dequeue(q);
	 	if(node == NULL)  
                        break;
                print_node(node);
		if(node->child_count > 0){
			for(unsigned int i = 0; i< node->child_count; i++){
                		if(node->children[i] != NULL){
					enqueue(q, node->children[i]);
				}
			}
		}
        }
	destroy_q(q);
}	


// Function add a child to the tree
// @param tree: the tree to search for the parent
// 	and then add the child
// @param parent_name: the name of the parent to add the child to
// @param child_name: the name of the child to add to the parent
// @return: the edited tree
NTree add_child( NTree tree, char  parent_name[], char child_name[] ){
	if(tree == NULL){
		tree = create_node(parent_name);
	}
	NTree parent = find_node(tree, parent_name);
	NTree current = tree;
	if(parent != NULL){
		
		for(unsigned int i = 0; i< parent->child_count; i++){		//check if its already a child
			if( strcmp(parent->children[i]->name, child_name) == 0 ){
				fprintf(stderr, "error: '%s' is already a child of '%s'.\n", child_name, parent_name);
                		return current;
			}
		}
		parent->child_count = parent->child_count + 1;
		parent->children = realloc(parent->children,(sizeof(NTree)*(parent->child_count))); 
		parent->children[parent->child_count - 1] = create_node(child_name); 
		return current;
	}
	else if( strcmp(current->name, child_name) == 0){
		//  if the parent is not in the tree, check if child is the root
		//  	and add the parent as the new root
		parent = create_node(parent_name);
		parent->child_count = 1;
		parent->children = malloc((sizeof(tree)*(parent->child_count)));
		parent->children[0] = tree;
		return parent;
	}
	else
		fprintf(stderr, "error: '%s' is not in the tree and '%s' is not the root.\n", parent_name,  child_name);
	return tree;			
	}
