/////////////////////////////////////////////////////////////////////
/// offspring.c: uses an n-arr tree to hold an offspring tree 
/// 	and has methods to manipulate the offspring tree
/// author: julie Sojkowski jas7845@g.rit.edu
/// date: March 20, 2019
/////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "N-Ary.h"


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

void add(char input[]){
	
	int i = 0;
	while( input[i] != ' '){
        	i++;
        }
	char names[100];
	int s = 0;
	for(unsigned int j = i; j<strlen(input); j++){
		names[s] = input[j];
	        s++;	
	}
	char *pch[10];
	pch[0] = strtok( names, "," );
	while ( pch[i] != NULL ) {
                i++;
                pch[i] = strtok( NULL, "," );
        }
	printf("parent: %s, child: %s\n", pch[0], pch[1]);

//	NTree new = find_node(tree, name);
//	if (new != NULL)
//		add_child(tree, name, child_name);
//	else
//		tree = add_child(tree, name, child_name);
}

void find(NTree tree, char name[]){

	NTree temp = find_node(tree, name);
        print_tree(temp);
	printf(" had ");
	for( int i = 0; i< temp->child_count; i++){
                if(temp->children[i]->name != NULL){
                        if( (i == 0) || (i == temp->child_count -1) ){
				print_tree(temp->children[i]);
			}
			else{
				print_tree(temp->children[i]);
				printf(" and ");
			}
		}
        }
}

void theMenu(){

	printf("offspring> ");
	
	int implen= 1024;
        char imp[implen];
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
        while( imp[i] != ' '){
		commandName[i] = imp[i];
                i++;
        }
        commandName[i]= '\0';
        char quit[] = "quit";
	int cmp=3;
	if(strcmp(commandName, quit) == 0){
		cmp =1;
	}
	while(cmp != 1 ){		//while the command is not quit

		if( strcmp(commandName, CNValues[0]) == 0){
                        printf("added\n");
			add(imp);
                }
                if( strcmp(commandName, CNValues[1]) == 0){
                        printf("found\n");
                }
                if( strcmp(commandName, CNValues[2]) == 0){
                        printf("printed\n");
                }
                if( strcmp(commandName, CNValues[3]) == 0){
                        printf("sized\n");
                }
                if( strcmp(commandName, CNValues[4]) == 0){
                        printf("high\n");
                }
                if( strcmp(commandName, CNValues[5]) == 0){
                        printf("helped\n");
                }
                if( strcmp(commandName, CNValues[6]) == 0){
                        printf("inited\n");
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
        	while( imp[i] != ' '){
        	        commandName[i] = imp[i];
        	        i++;
        	}
        	commandName[i]= '\0';
		if(strcmp(commandName, quit) == 0){
			printf("quitnn");
			cmp = 1;
		}
		else cmp = 3;
		printf("command: %s \n", commandName);

	}
	printf("quitted");
}


int main(int argc, char * argv[]){
	
	if(argc == 2){
		//make the tree then continue to while loop
	}
	theMenu();		
	return 0;
}
