#include <unistd.h>
 
int main(void) {
  char *binaryPath = "/bin/ls";
  char *args[] = {binaryPath, "-lh", NULL};
 
  execv(binaryPath, args);
 
  return 0;
}

