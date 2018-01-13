# define _XOPEN_SOURCE 700

# include <err.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>


static
unsigned compute_hash(const unsigned char *data, size_t len) {
  unsigned h = 0;
  for (size_t i = 0; i < len; i++) {
    unsigned ho = h & 0xf8000000;
    h <<= 5;
    h ^= (ho >> 27);
    h ^= (unsigned)(data[i]);
  }
  return h;
}

static
void read_data(int request_fd, int result_fd) {
  size_t capa = 32, len = 0;
  unsigned char *data = malloc(capa * sizeof (unsigned char));
  memset(data, 0xff, capa);
  int r;
  while ( (r = read(request_fd, data + len, capa - len)) ) {
    if (r == -1) {
      if (errno == EINTR) continue;
      err(3, "Can't read data");
    }
    len += r;
    if (len > 2 && data[len - 2] == 0 && data[len - 1] == 0) {
      // Message end
      unsigned result = compute_hash(data, len - 2);
      len = 0;
      write(result_fd, &result, sizeof (unsigned));
      memset(data, 0xff, capa);
      continue;
    }
    if (len >= capa) {
      capa *= 2;
      data = realloc(data, capa * sizeof (unsigned char));
    }
  }
  free(data);
}

int main() {
  read_data(STDIN_FILENO, STDOUT_FILENO);
  return 0;
}