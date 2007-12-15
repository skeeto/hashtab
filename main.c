/* main.c - Hashtable test
 * Copyright (C) 2007 Christopher Wellons 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtab.h"

int main ()
{
  hashtab_t *test_ht = ht_init (2, NULL);

  /* create some data */
  char *ak = "Perl";
  char *av = "Language";

  char *bk = "GNU";
  char *bv = "System";

  char *ck = "Java";
  char *cv = "Mistake";

  char *dk = "Pidgin";
  char *dv = "Instant Message";

  char *ek = "Iceweasel";
  char *ev = "Browser";

  /* stick the data in the table */
  ht_insert (test_ht, ak, strlen (ak) + 1, av, strlen (av) + 1);
  ht_insert (test_ht, bk, strlen (bk) + 1, bv, strlen (bv) + 1);
  ht_insert (test_ht, ck, strlen (ak) + 1, cv, strlen (cv) + 1);
  ht_insert (test_ht, dk, strlen (ak) + 1, dv, strlen (dv) + 1);
  ht_insert (test_ht, ek, strlen (ak) + 1, ev, strlen (ev) + 1);

  /* display table data */
  hashtab_iter_t ii;
  ht_iter_init (test_ht, &ii);
  for (; ii.key != NULL; ht_iter_inc (&ii))
    {
      printf ("%s => %s\n", (char *) ii.key, (char *) ii.value);
    }

  /* grow the table */
  printf ("---\nGROW!\n---\n");
  test_ht = ht_grow (test_ht, 10);

  /* print the table contents again */
  ht_iter_init (test_ht, &ii);
  for (; ii.key != NULL; ht_iter_inc (&ii))
    {
      printf ("%s => %s\n", (char *) ii.key, (char *) ii.value);
    }

  /* free the hashtable */
  ht_destroy (test_ht);

  return EXIT_SUCCESS;
}
