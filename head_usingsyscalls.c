#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define max 1024
#define def_lines 10
void head(int fd, int n){
                  int lines =n;
                  char buffer[max];
                  int count=0;
                 ssize_t k;
                 while((k=read(fd,buffer,max))>0){
                              for(ssize_t i=0;i<k;i++){
                                            write(STDOUT_FILENO, &buffer[i], 1);
                                                      if(buffer[i]=='\n'){
                                                              count++;
                                                                        if(count>=lines){return;}}}}
                        }
  int main(int argc, char *argv[]){
      int n=5;
      if(argc==1){perror("Invalid no of arguments");}
      if(argc>1){
         if(argv[1][0]=='-'){
          n=atoi(argv[1]+1);
         // printf("%d", n);
          for(int i=1;i<argc;i++){
            int fd=open(argv[i], O_RDONLY,0);
            if(fd<0){perror(argv[i]);}
            
            head(fd,n);
            close(fd);
            }
          
          }
         
         else{
         for(int i=1;i<argc;i++){
            int fd=open(argv[i], O_RDONLY,0);
            if(fd<0){perror(argv[i]);}
            
            head(fd,n);
            close(fd);
            }
      
      
      }}
      
      return 0;
      
      }
                      
          
        
