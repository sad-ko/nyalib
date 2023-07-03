#ifndef __nyarror__
#define __nyarror__

#define nullptr ((void *)0)
#define nyaerr stderr

/// @brief Do you know Rust?
typedef enum {
  Err,
  Ok,
} Res;

/// @brief This is not Rust, however...
typedef struct {
  void *data;
  Res res;
} Result;

void *nyawrap(const Result *ptr);

#endif // __nyarror__