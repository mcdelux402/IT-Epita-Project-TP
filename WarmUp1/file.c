# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <err.h>

int HelloWorld(const char*path)
{
  int fd = open(path, O_WRONLY);
  if ( fd == -1){
    err(3, "err", path);
  }
  char* buf = "Hello World\n";
  open(path, O_WRONLY);
  write(fd, buf, 12);
}

void main()
{
  char* doc = "toto";
  HelloWorld(doc);
}
