#include<stdio.h>
#include<errno.h>
#include<string.h>

#include<unistd.h>
# define max 1024
int main(int argc, char *argv[]){

   char cwd[max];
   if(argc<2){
        perror("Invalid no of arguments");
        return 0;
    }
   if(chdir(argv[1])!=0){
          perror("chdir failed");
           return 1;
      }
      
      if(getcwd(cwd, sizeof(cwd) )!=NULL){
            printf("Present in %s",cwd);
        }
        else{
           perror("getcwd error");
           return 1;
          }
          
          return 0;
      }
        
