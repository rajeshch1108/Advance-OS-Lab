#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#define max 1024
int main(int argc, char *argv[]){
                int fd;
                char buffer[max];
                ssize_t n;
                if(argc<2){
                    perror("Invalid Number of arguments");
                       return 0;
                  }
                for(int i=1;i<argc;i++){
                          fd=open(argv[i], O_RDONLY,0);
                              if(fd<0){
                                        perror(argv[i]);
                                               continue;
                              }
                              while((n=read(fd,buffer,max))>0){
                                      if(write(STDOUT_FILENO,buffer,n)!=n){
                                            perror("write");
                                                    close(fd);
                                                               return 0;
                                      }
                                      if(n<0){
                                          perror("read");
                                                 close(fd);
                               }
                               }
                           }    
                               return 0;
                               
      }
