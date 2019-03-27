/////////////////////////////////////////////////////////////////////
/// offspring.c: uses an n-arr tree to hold an offspring tree 
/// 	and has methods to manipulate the offspring tree
/// author: julie Sojkowski jas7845@g.rit.edu
/// version control is through git commits under offspring and
//	can be found in revisions.txt file
/// date: March 20, 2019
/////////////////////////////////////////////////////////////////////

#include "N-Ary.h"	//  contains the N-Ary tree functions and definition
#include "trimit.h"	//  contins the function to trim whitespace from string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// List of the input options 
char CNValues[9][7] = {
                         "add",
                         "find",
                         "print",
			 "size",
			 "height",
			 "help",
			 "init",
			 "quit"
                     };


// Function to compute the height of the tree at 
// 	a given node, if the node is not found print to stderr
// @param tree: the tree to compute the height from
// @param input: the name of the parent to start from
void height(NTree tree, char input[]){

	int i = 0;
        while( input[i] != ' ' && i < strlen(input)){
                i++;
        }
        char name[60];
        int s = 0;
        for(unsigned int j = i; j<strlen(input); j++){
                name[s] = input[j];
                s++;
        }
        name[s] = '\0';
        int height = -1;
        if(strlen(name)>1){
                trim(name);
                NTree tree2print = find_node(tree, name);
                if(tree2print!= NULL){
                        height = height_node(tree2print);
                }
		else
                	fprintf(stderr, "error: '%s' not found\n", name);
        }
        else height = height_node(tree);

        printf("height: %i\n", height);
}


// Function to find a node and print that node and it's children
// 	if node is not found print to stderr
// @param tree: the tree to search thorugh
// @param input: contains the name of the person to search for
void find(NTree tree, char input[]){
	
	int i = 0;
        while( input[i] != ' ' && i < strlen(input)){
                i++;
        }
        char name[60];
        int s = 0;
        for(unsigned int j = i; j<strlen(input); j++){
                name[s] = input[j];
                s++;
        }
        name[s] = '\0';
	trim(name);
	NTree temp = find_node(tree, name);
        if(temp == NULL)
		fprintf(stderr, "error: '%s' not found\n", name); 
	else print_node(temp);
}


// Function to print the tree at the given node if node
// 	is not found print to stderr
// @param tree: the tree to print
// @param input: contains the name of the parent to start 
// 	printing at
void print(NTree tree, char input[]){
	
	int i = 0;
        while( input[i] != ' '&& i < strlen(input)){
                i++;
        }
        char name[60];
        int s = 0;
        for(unsigned int j = i; j<strlen(input); j++){
                name[s] = input[j];
                s++;
        }
        name[s] = '\0';
	if(strlen(name)>1){
		trim(name);
		NTree tree2print = find_node(tree, name);
		if(tree2print!= NULL){
			print_tree(tree2print);
		}
		else fprintf(stderr, "error: '%s' not found\n", name);
	}
	else print_tree(tree);
}


// Function to free the current tree and start with empty tree
// @param tree: the tree to free
// @return: the null tree
NTree init(NTree tree){
	destroy(tree);
	tree = NULL;
	return tree;
}


// Funtion to print the menu options
void help(){

	printf("User Commands for offspring:\n");
	printf("add parent-name, child-name # find parent and add child.\n");
	printf("find name     # search and print name and children if name is found.\n");
	printf("print [name]  # breadth first traversal of offspring from name.\n");
	printf("size [name]   # count members in the [sub]tree.\n");
	printf("height [name] # return the height of [sub]tree.\n");
	printf("init          # delete current tree and restart with an empty tree.\n");
	printf("help          # print this information.\n");
	printf("quit          # delete current tree and end program.\n");
}


// Funciton to free the tree
// @param tree: the tree to tree
void quitit(NTree tree){

	destroy(tree);
}


// Function to compute and print the size of a tree
// @param tree: the tree to compute the size of
// @param input: input that contains the name, if given 
// 	of the starting parent
void size(NTree tree, char input[]){
	int i = 0;
        while( input[i] != ' ' && i < strlen(input)){
                i++;
        }
        char name[60];
        int s = 0;
        for(unsigned int j = i; j<strlen(input); j++){
                name[s] = input[j];
                s++;
        }
        name[s] = '\0';
	int size = 0;
        if(strlen(name)>1){
                trim(name);
                NTree tree2print = find_node(tree, name);
                if(tree2print!= NULL){
                        size = size_node(tree2print);
                }
        }
        else size = size_node(tree);

	printf("size: %i\n", size);

}


// Function to process command line arguments
// @param tree: the tree to process command line arg with
void theMenu(NTree tree){

	printf("offspring> ");
	
	int implen= 1024;
        char imp[1024];
        if(fgets(imp, implen, stdin)){
		char *c;
                if((c = strchr(imp, '\n'))){    //check for newline
                        *c = 0;                 //assign newline to 0
                } else {
                        scanf("%*[^\n]");
			scanf("%*c");           //clear upto newline
		}
        }

        char commandName[10];
	int i= 0;
        while( imp[i] != ' ' && i < strlen(imp)){
		commandName[i] = imp[i];
                i++;
        }
        commandName[i]= '\0';
        char quit[] = "quit";
	
	while(strcmp(commandName, quit) != 0 ){		//while the command is not quit

		if(strcmp(commandName, CNValues[0]) == 0){		// if add
			int i = 0;
       			while( imp[i] != ' ' && i < strlen(imp)){
                		i++;
        		}
        		char names[60];
        		int s = 0;
        		for(unsigned int j = i; j<strlen(imp); j++){
        		        names[s] = imp[j];
                		s++;
        		}
        		names[s] = '\0';
        		if(strlen(names)>2){
                		char parent[30];
                		char child[30];
                		int h = 0;
                		while(names[h] != ','){
                        		parent[h] = names[h];
                        		h++;
                		}
                		parent[h] = '\0';
                		int p = 0;
                		h++;
                		while(names[h] != '\0'){
                        		child[p] = names[h];
                        		h++;
                       			p++;
                		}
                		child[p] = '\0';
                		trim(parent);
                		trim(child);
                		tree = add_child(tree, parent, child);
			}
			else{
                		printf("Usage: 'add parent name , child name'\n'");
			}
		}
                if( strcmp(commandName, CNValues[1]) == 0){		// if find
			find(tree, imp);
                }
                if( strcmp(commandName, CNValues[2]) == 0){		// if print
			print(tree, imp);
                }
                if( strcmp(commandName, CNValues[3]) == 0){		// if size
                	size(tree, imp);
		}
                if( strcmp(commandName, CNValues[4]) == 0){		// if height
			height(tree, imp);
                }
                if( strcmp(commandName, CNValues[5]) == 0){		// if help
			help();
                }
                if( strcmp(commandName, CNValues[6]) == 0){		// if init
			tree = init(tree);
                }
		
		printf("offspring> ");
		if(fgets(imp, implen, stdin)){
                	char *c;
                	if((c = strchr(imp, '\n'))){    //check for newline
                	        *c = 0;                 //assign newline to 0
                	} else {
                        	scanf("%*[^\n]");
                	        scanf("%*c");           //clear upto newline
       		        }
        	}

		i = 0;
        	while( imp[i] != ' ' && i < strlen(imp)){
        	        commandName[i] = imp[i];
        	        i++;
        	}
        	commandName[i]= '\0';
	}
	quitit(tree);
}


int main(int argc, char * argv[]){
	
	NTree tree = NULL;
	if(argc == 2){				//if there is a file
		//makes the tree then continues to while loop
		FILE *fp;
    		int MAXCHAR = 1024;
		char str[MAXCHAR];
    		char* filename = argv[1];
    		fp = fopen(filename, "r");
    		if (fp == NULL){
        		fprintf(stderr, "error: could not open file %s", filename);
    			theMenu(tree);
		}
		char *pch[10];
    		for(int j = 0; j < 10; j++){
			pch[j] = NULL;
		}
		char child[30];
		char parent[30];
		fgets(str, MAXCHAR, fp);
		int j = 0;
	        while(j< strlen(str) && str[j] != ','){	//  check if the first line has a comma (multiple names)
			j++;		
		}
		if(j >= (strlen(str) - 1)){		//  if there is not a comma, create new tree ith name
			trim(str);
			tree = create_node(str, 10);
		}
		else{

			pch[0] = strtok( str, ",\n" );
                        int i =0;
                        strcpy(parent, pch[0]);
                        trim(parent);
                        while ( pch[i] != NULL ) {
                                i++;
                                pch[i] = strtok( NULL,",\n" );
                                trim(pch[i]);
                                if(pch[i] != NULL){
                                        strcpy(child, pch[i]);
                                        trim(child);
                                        tree = add_child(tree, parent, child);
				}
			}
		}

		while ((fgets(str, MAXCHAR, fp) != NULL) || !(feof(fp))){
			pch[0] = strtok( str, ",\n" );
			if(pch[0] != NULL){
				int i =0;
				strcpy(parent, pch[0]);
				trim(parent);
				while ( pch[i] != NULL ) {
                			i++;
                			pch[i] = strtok( NULL,",\n" );
					trim(pch[i]);
					if(pch[i] != NULL){
						strcpy(child, pch[i]);
						trim(child);
						tree = add_child(tree, parent, child);
					}
				}
			}
		}
    		fflush(fp);
		fclose(fp);
	}
	theMenu(tree); 			//call the menu		
	return 0;
}
