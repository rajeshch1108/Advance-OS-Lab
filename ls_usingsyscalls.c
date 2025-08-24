#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
int main(int argc, char *argv[]){

        char *path;
        if(argc>1){path=argv[1];}
        else{
        path=".";}
        DIR *dir=opendir(path);
        if(dir==NULL){
              perror("opendir");
               return 1;
          }
          
          struct dirent *entry;
          while((entry=readdir(dir))!=NULL){
                    printf("%s\n", entry->d_name);
              }
              closedir(dir);
              
              return 0;
              
        }
