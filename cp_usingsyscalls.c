#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<errno.h>
#include<libgen.h>


# define max 1024
int main(int argc, char *argv[]){
        if(argc!=3){
              perror("Invalid no of arguments");
              return 1;
              
            }
            char *source=argv[1];
            char *destination=argv[2];
            
            struct stat st;
            int dir=(stat(destination,&st)==0 && S_ISDIR(st.st_mode));
            
            char final[max];
            if(dir){
              snprintf(final, sizeof(final), "%s/%s", destination, basename(source));
            }else{
              snprintf(final, sizeof(final),  "%s", destination);
              
              }
              FILE *src=fopen(source, "rb");
              if(src==NULL){
                      perror("file opening");
                           return 1;}
              FILE *dest=fopen(final, "ab");
                if(dest==NULL){
                      perror("file opening");
                         fclose(src);
                         return 1;
                      }
                      
                      char buffer[max];
                      size_t b;
                      while((b=fread(buffer, 1,max,src))>0){
                          if(fwrite(buffer,1,b,dest)!=b){
                            perror("error writing");
                            fclose(src);
                            fclose(dest);
                            return 1;
                          }}
                          fclose(src);
                          fclose(dest);
                          return 0;
                    }
                         
            
            
            
                
