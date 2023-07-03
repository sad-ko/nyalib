#include <nyatring.h>
#include <string.h> //temporary

Companyasion _cmp_(const char *s1, const char *s2);

Result Nyatring_new(const char *str, const size_t buffer_size) {
  Nyatring *nyastr;
  size_t length = 0;
  char *aux = (char *)str;

  for (; *aux != '\0' && length <= buffer_size; aux++, length++) {
  }

  if (*aux != '\0' || length > buffer_size ||
      (nyastr = calloc(1, sizeof(Nyatring))) == nullptr ||
      (nyastr->str = calloc(length + 1, sizeof(char))) == nullptr) {

    return (Result){.res = Err, .data = nullptr};
  }

  strncpy(nyastr->str, str, length);
  nyastr->size = length + 1;

  return (Result){.res = Ok, .data = nyastr};
}

size_t Nyatring_size(const Nyatring *ptr) { return ptr->size; }

Nyatring *Nyatring_cat(Nyatring *dest, const Nyatring *src) {
  size_t full_size = dest->size + src->size;

  char *aux = realloc(dest->str, full_size);
  strncpy(aux + dest->size, src->str, src->size);

  dest->size = full_size;
  dest->str = aux;

  return dest;
}

Result Nyatring_cpy(const Nyatring *src) {
  return Nyatring_new(src->str, src->size);
}

Companyasion _cmp_(const char *s1, const char *s2) {
  for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++) {
    if (*s1 != *s2) {
      int cmp = *s1 - *s2;
      return (cmp < 0) ? Smaller : Bigger;
    }
  }

  return Equal;
}

Companyasion Nyatring_cmp(const Nyatring *nya1, const Nyatring *nya2) {
  char *s1 = nya1->str;
  char *s2 = nya2->str;

  return _cmp_(s1, s2);
}

char *Nyatring_find(const Nyatring *haystack, const char *needle) {
  char *aux = haystack->str;

  for (; *aux != '\0'; aux++) {
    if (_cmp_(aux, needle) == Equal) {
      return aux;
    }
  }

  return nullptr;
}