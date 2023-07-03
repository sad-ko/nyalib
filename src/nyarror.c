#include <nyarror.h>

void *nyawrap(const Result *ptr) {
  if (ptr->res == Ok) {
    return ptr->data;
  }

  return nullptr;
}