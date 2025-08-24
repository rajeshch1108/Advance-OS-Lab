#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
int main(int argc, char *argv[]){

        char *path;
        if(argc==1){
        path=".";
              DIR *dir=opendir(path);
        if(dir==NULL){
              perror("opendir");
               return 1;
          }
          
          struct dirent *entry;
          while((entry=readdir(dir))!=NULL){
                     if(entry->d_name[0]=='.')
                     continue;
                printf("%s\n", entry->d_name);
              }
              closedir(dir);
           }     
      else  if(argc==2 && strcmp(argv[1],"-a")==0){
              path=".";
                DIR *dir=opendir(path);
                    if(dir==NULL){
                              perror("opendir");
                                   return 1;
                       }
                       
                       struct dirent *x;
                       while((x=readdir(dir))!=NULL){
                                    printf("%s\n", x->d_name);}
                            closedir(dir);
                            
        }
        else{
                    path=argv[1];
                       DIR *dir=opendir(path);
        if(dir==NULL){
              perror("opendir");
               return 1;
          }
          
          struct dirent *entry;
          while((entry=readdir(dir))!=NULL){
                     if(entry->d_name[0]=='.')
                     continue;
                printf("%s\n", entry->d_name);
              }
              closedir(dir);
              
            }  
        
        
              
              return 0;
              
        }
