# define _XOPEN_SOURCE 700
# include <err.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*
unsigned ReadUp(int* fd1, int* fd2, char* name){
  FILE* fp;
  char * line = NULL;
  ssize_t count;
  size_t len = 0;
  unsigned* tab;
  fp = fopen(name, "r");
  while((count = getline(&line, &len, fp)) > -1){
      write(fd1[1], line, count);
      write(fd1[1],"\0\0", 2);
      unsigned j;
      read(fd2[0], &j, sizeof(unsigned));
      return j;
      free(line);
      line = NULL;
  }
 }
*/

  int main(int arg, char** argv) {
  int fd1[2];
  int fd2[2];
  pipe(fd1);
  pipe(fd2);
  int r;
  int r_fork = fork();
  if (r_fork >= 1){
    //PARENT
    
    FILE* fp;
    char * line = NULL;
    ssize_t count;
    size_t len = 0;
    fp = fopen(argv[2], "r");
    while((count = getline(&line, &len, fp)) != -1){
      write(fd2[1], line, count);
      write(fd2[1],"\0\0", 2);
      unsigned j;
      read(fd1[0], &j, sizeof(unsigned));
      printf("%x", j);
      free(line);
      line = NULL;
    }
    //read input line by lined
    
  }
  else{
    //FILS
    
    //exe worker
    dup2(fd1[1],1);
    dup2(fd2[0],0);
    char* param[arg];
    for(int i = 0; i<arg; i++)
      param[i] = argv[i+1];
    execvp(param[0], param);
  }
    return 0;
}
