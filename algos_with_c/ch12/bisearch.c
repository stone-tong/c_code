#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "search.h"


int bisearch(void *sorted, const void *target, int size, int esize,
             int (*compare)(const void *key1, const void *key2)) {
    int left, middle, right;

    /* Continue searching until the left and right indices cross */
    left = 0;
    right = size - 1;

    while (left <= right) {
        middle = (left + right) / 2;
        printf("left = %d, middle = %d, right = %d\n", left, middle, right);
        printf("%c\n", *((char *) sorted + (esize * middle)));
        /* printf("sorted one = %s\n", (char *) sorted + (esize * middle)); */
        switch (compare(((char *) sorted + (esize * middle)), target)) {
            case -1:
                /* Prepare to search to the right of the middle index */
                left = middle + 1;
                break;
            case 1:
                /* Prepare to search to the left of the middle index */
                right = middle - 1;
                break;
            case 0:
                /* Return the exact index where data has been found */
                return middle;
        }
    }

    /* Return that the data wasn't found */
    return -1;
}
