#ifndef __nyanory__
#define __nyanory__

#include <stdlib.h>

#define DEFNYAN_CLEANYAP_FUNCTYAN(type, func)                                  \
  static inline void func##p(type *p) {                                        \
    if (*p) {                                                                  \
      func(*p);                                                                \
    }                                                                          \
  }

static inline void freep(void *p) { free(*(void **)p); }
#define nya_char char *__attribute__((cleanup(freep)))

DEFNYAN_CLEANYAP_FUNCTYAN(char *, freep)

#endif // __nyanory__