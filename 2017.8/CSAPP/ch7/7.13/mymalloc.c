#ifdef COMPILETIME
#include <stdio.h>
#include <malloc.h>

void *mymalloc(size_t size) {
  void *ptr = malloc(size);
  printf("malloc(%d)=%p\n",
         (int)size, ptr);
  return ptr;
}

void myfree(void *ptr) {
  free(ptr);
  printf("free(%p)\n", ptr);
}
#endif

#ifdef LINKTIME
#include <stdio.h>

void *__real_malloc(size_t size);
void __real_free(void *ptr);

void *__wrap_malloc(size_t size) {
  void *ptr = __real_malloc(size);
  printf("malloc(%d) = %p\n", (int)size, ptr);
  return ptr;
}

void *__wrap_free(void *ptr) {
  __real_free(ptr);
  printf("free(%p)\n", ptr);
}
#endif

#ifdef RUNTIME
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void *malloc(size_t size) {
  void *(*mallocp)(size_t size);
  char *error;
  mallocp = dlsym(RTLD_NEXT, "malloc");
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }
  char *ptr = mallocp(size);
  printf("malloc(%d) = %p\n", (int)size, ptr);
  return ptr;
}

void free(void *ptr) {
  void (*freep)(void *) = NULL;
  char *error;
  if (!ptr)
    return;
  freep = dlsym(RTLD_NEXT, "free");
  if ((error = dlerror()) != NULL) {
    fputs(error, stderr);
    exit(1);
  }
  freep(ptr);
  printf("free(%p)\n", ptr);
}
#endif
