#ifndef __nyatring__
#define __nyatring__

#include <nyanory.h>
#include <nyarror.h>

typedef long unsigned int size_t;

/// @brief Safe String type, made for the programs with the most performant and
/// thightest security ever.
/// [Should use its auto type for better memory managment]
typedef struct {
  char *str;
  size_t size;
} Nyatring;

/// @brief Comparasion...
typedef enum {
  Smaller,
  Bigger,
  Equal,
} Companyasion;

/// @brief Creates a new and amazing Nyatring!!!
/// [Cast the result data with cast type and use it as auto tye for better
/// memory managment]
/// @param str: Please try to give it a null-terminated str...
/// @param buffer_size: Or we will force you
/// @return Result: Check .res to see if it return Ok or had an Err, if it had
/// an Err, the .data will have a nullptr.
Result Nyatring_new(const char *str, const size_t buffer_size);

/// @brief Top notch with incredible speed of O(-1) to return the Nyatring size
/// @param ptr: We are not responsible if you pass a nullptr...
/// @return The secrets of the universe
size_t Nyatring_size(const Nyatring *ptr);

/// @brief Concatenates and amazing Nyatring with, get ready to this...
/// and another AMAZING NYATRING!!!
/// @param dest: First Amazing Nyatring
/// @param src: Second Amazing Nyatring or...?
/// @return A pointer to dest and one step closer to a nyatring centepide
Nyatring *Nyatring_cat(Nyatring *dest, const Nyatring *src);

/// @brief Recreates the universe and kills everything EXCEPT this Nyatring
/// @param src: The Nyatring to be spared
/// @return Result: Check .res to see if it return Ok or had an Err, if it had
/// an Err, the .data will have a nullptr.
Result Nyatring_cpy(const Nyatring *src);

/// @brief Makes some very intellectual tests two both Nyatrings and compares
/// its performance
/// @param nya1: A Nyatring that crams the whole test material last night
/// @param nya2: A very diligent Nyatring
/// @return Two Nyatrings very stressed...
Companyasion Nyatring_cmp(const Nyatring *nya1, const Nyatring *nya2);

/// @brief Hires a private detective to find this subNyatring in another
/// Nyatring.
/// @param haystack: A very suspicious Nyatring...
/// @param needle: A very insecure Nyatring
/// @return A broken relationship
char *Nyatring_find(const Nyatring *haystack, const char *needle);

static inline void clean_nyatring(void *p) {
  Nyatring *nya = *(Nyatring **)p;
  free(nya->str);
  free(*(void **)p);
}

DEFNYAN_CLEANYAP_FUNCTYAN(Nyatring *, clean_nyatring)
#define autoNyatring Nyatring *__attribute__((cleanup(clean_nyatring)))
#define castNyatring Nyatring *

#endif // __nyatring__
