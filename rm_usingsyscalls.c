#include<stdio.h>
#include<errno.h>
#include<string.h>

#include<unistd.h>

int main(int argc, char *argv[]){
    int fd=0;
    char c;
    if(argc<2){
      perror("Invalid number of Arguments");
      return 0;
      }
      for(int i=1;i<argc;i++){
          if(strcmp(argv[i],"")!=0){
                    printf("Remove the file %s?",argv[i]);
                     c=getchar();
                        if((c=='y')||(c=='Y')){
                                if(unlink(argv[i])!=0){
                                      perror(argv[i]);
                                   }
                                   else{
                                   printf("Deleted file %s",argv[i]);
                                   
                                   }}
                    else{
                            return 0;
                            
                    }
              }
          }
        return 0;
        
        }
              
                          
                                  
                          
                            
      
