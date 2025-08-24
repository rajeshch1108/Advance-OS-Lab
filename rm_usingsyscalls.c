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
      
      if(strcmp(argv[1],"-v")==0){
        for(int i=1;i<argc;i++){
                          if(argv[i]==NULL)continue;
                          if(unlink(argv[i])==0){
                                printf("Removed the file %s", argv[i]);
                            }else{
                                      perror(argv[i]);}
                                      }}
     else if(strcmp(argv[1],"-i")==0){
               char c;
               for(int i=1;i<argc;i++){
                              if(argv[i]==NULL)continue;
                             printf("Do you want to remove the file %s", argv[i]);
                                 scanf("%c", &c);
                                     if(c=='y' || c=='Y'){
                                                    if(unlink(argv[i])==0){
                                                            printf("Removed %s", argv[i]);
                                                      }else{
                                                                      perror(argv[i]);
                                                                  }
                                        }else if (c=='n' || c=='N'){
                                                      continue;
                                                     }else{
                                                        perror("rm");}
                                                        
              }
                                                  
              }
              
              else if(strcmp(argv[1],"-f")==0){
                            for(int i=1;i,argc;i++){
                            if(argv[i]==NULL){
                            continue;}
                            if(unlink(argv[i])==0){continue;}
                            else{continue;}}
              }
              else{
                        for(int i=1;i<argc;i++){
                            if(argv[i]==NULL)continue;
                            if(unlink(argv[i])==0)printf("Removed %s", argv[i]);
                            else{perror(argv[i]);}
                            }
          }
          
          
        return 0;
        
        }
              
                          
                                  
                          
                            
      
