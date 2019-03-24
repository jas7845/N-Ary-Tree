/////////////////////////////////////////////////////////////////////
/// offspring.c: uses an n-arr tree to hold an offspring tree 
/// 	and has methods to manipulate the offspring tree
/// author: julie Sojkowski jas7845@g.rit.edu
/// date: March 20, 2019
/////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        char commandName[7];
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
                        printf("added + %s\n", imp);
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
		
	//theMenu();
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

        char commandName[7];
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

	while( cmp != 0){

                if( strcmp(commandName, CNValues[0]) == 0){
                        printf("added + %s\n", imp);
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
                        printf("quitnn\n");
                        cmp = 0;
                }
                else cmp = 3;
                printf("command: %s \n", commandName);

        }

	return 0;
}
