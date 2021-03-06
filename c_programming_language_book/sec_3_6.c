#include <stdio.h>
#include <string.h>


/* reverse: reverse string s in place */
void reverse( char s[] )
{
    int c, i, j;

    for (i = 0, j = strlen( s ) - 1; i < j; i++, j--) {
        c = s[ i ];
        s[ i ] = s[ j ];
        s[ j ] = c;
    }
}


/* itoa: convert n to characters in s */
void itoa( int n, char s[] )
{
    int i, sign;

    // record sign
    if ( (sign = n) < 0 ) {
        // make n positive
        n = -n;
    }

    i = 0;

    // generate digits in reverse order
    do {
        // Get next digit
        s[ i++ ] = n % 10 + '0';
    // Delete it
    } while ( (n /= 10) > 0 );

    if (sign < 0)
        s[ i++ ] = '-';

    s[ i ] = '\0';
    reverse( s );
}

main()
{
    char s[ 100 ];
    itoa( 123, s );
    printf( "%s", s );
}

