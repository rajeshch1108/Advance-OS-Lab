#include<stdio.h>
#include<errno.h>
#include<string.h>

#include<unistd.h>
#include<fcntl.h>

#define max 1024
#define def_lines 10
int main(int argc,char *argv[]){
        int fd,count=0;
        char buffer[max];
        ssize_t n;
        int l,num=0;
        int i;
        if(argc==1){
                perror("Invalid no of arguments");
                   return 0;
          }
          
          if(argv[1][0]=='-'){
                  l=strlen(argv[1]);
                      for(int i=1;i<l;i++){
                            num=num*10+argv[1][i]-48;}
                          i=2;
              }
              else{
                     num=10;
                     i=1;
            }
            printf("%d", num);
            for(;i<argc;i++){
                        fd=open(argv[i], O_RDONLY,0);
                            if(fd<0){
                                  perror(argv[i]);
                                       continue;
                            }
                            while((n=read(fd,buffer,max))>0){
                                    for(ssize_t k=0;k<n;n++){
                                              write(STDOUT_FILENO, &buffer[k],1);
                                                      if(buffer[k]=='\n'){
                                                                    count++;
                                                                                  if(count>num){return 0;}
                                                      }
                                      }}
                                      close(fd);
                                      
              }
              
              
              
              return 0;
              
              }
            
                     
              
                              
                      
          
        
