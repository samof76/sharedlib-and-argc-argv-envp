#include <stdio.h>
#include <stdlib.h>

static int foo_init(int argc, char** argv, char** envp) {
  printf("foo constructor\n");

  printf("======================== args ========================\n");
  printf("argv ptr = %p\n", argv);
  for (int i = 0; i < argc; ++i) {
      printf("%d %p %s\n", i, (void*)argv[i], argv[i]);
  }

  printf("======================== envs after argv ========================\n");
  printf("envp after argv ptr = %p\n", &argv[argc+1]);
  for (int i = argc+1; argv[i] != NULL; ++i) {
      printf("%d %p %s\n", i, (void*)argv[i], argv[i]);
  }

  printf("======================== envs from envp ========================\n");
  printf("envp ptr = %p\n", envp);
  for (int i = 0; envp[i] != NULL; ++i) {
      printf("%d %p %s\n", i, (void*)envp[i], envp[i]);
  }
}

__attribute__((section(".init_array"))) static void *ctr = &foo_init;

extern char** environ;

void Hello() {
    printf("hello from foo lib\n");
    printf("environ ptr = %p\n", environ);

    for (int i = 0; environ[i] != NULL; ++i) {
        printf("%d %p %s\n", i, (void*)environ[i], environ[i]);
    }
}

/* int main(int argc, char** argv, char** env) { */
/*     printf("in main\n"); */
/*     foo_init(argc, argv, env); */
/*     return 0; */
/* } */
