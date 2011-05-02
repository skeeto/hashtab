/* main.c - Hashtable test
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashtab.h"
#include "strht.h"

int main()
{
    hashtab_t *test_ht = ht_init(2, NULL);

    /* stick some data into the table (using the string front-end) */
    strht_insert(test_ht, "Perl", "Language");
    strht_insert(test_ht, "GNU", "System");
    strht_insert(test_ht, "Java", "Verbose");
    strht_insert(test_ht, "Pidgin", "Instant Messenger");
    strht_insert(test_ht, "Firefox", "Web Browser");

    /* display table data */
    hashtab_iter_t ii;
    ht_iter_init(test_ht, &ii);
    for (; ii.key != NULL; ht_iter_inc(&ii)) {
	printf("%s => %s\n", (char *) ii.key, (char *) ii.value);
    }

    /* grow the table */
    printf("---\nGROW!\n---\n");
    test_ht = ht_grow(test_ht, 10);

    /* print the table contents again */
    ht_iter_init(test_ht, &ii);
    for (; ii.key != NULL; ht_iter_inc(&ii)) {
	printf("%s => %s\n", (char *) ii.key, (char *) ii.value);
    }

    /* free the hashtable */
    ht_destroy(test_ht);

    return EXIT_SUCCESS;
}
