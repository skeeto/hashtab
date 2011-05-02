/* strht.h - String front-end macros to hashtab
 */

/* This is a demonstration of a possible string front-end to the hash
 * table. Note that this will double-eval arguments. */

#ifndef STRING_HT_H
#define STRING_HT_H

#include "hashtab.h"

#define strht_search(h, k)    ht_search(h, k, strlen(k) + 1)
#define strht_insert(h, k, v) ht_insert(h, k, strlen(k) + 1, v, strlen(v) + 1)
#define strht_remove(h, k)    ht_remove(h, k, strlen(k) + 1);

#endif
