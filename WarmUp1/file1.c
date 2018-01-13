# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <err.h>
# include <sys/stat.h>


int main()
{
  char* path = "toto";
  struct stat FileStat;
  if(stat(path, &FileStat)<0)
    return 1;
  
  s_t write(1, const void *buf, size_t count);
  
  ("File Size: ", FileStat.st_size);
  return 0;
}

