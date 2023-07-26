#include <stdio.h>
#include <stdlib.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

int main() {
	    char *line = NULL;
	        size_t bufsize = 0;
		    ssize_t chars_read;
      printf("Enter a line of text (Ctrl+D to exit):\n");
      while ((chars_read = _getline(&line, &bufsize, stdin)) != -1) {
          printf("Line read: %s", line);
          printf("Characters read: %zd\n", chars_read);
      }
      free(line);
      return 0;
}
