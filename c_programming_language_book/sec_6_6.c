#include <string.h>


#define HASHSIZE 101


// Pointer table
static struct nlist *hashtab[HASHSIZE];
// Table entry
struct nlist {
    // Next entry in chain
    struct nlist *next;
    // Defined name
    char *name;
    // Replacement text
    char *defn;
};


// hash: form hash value for string s
unsigned hash(char *);
// lookup: look for s in hashtab
struct nlist *lookup(char *);
char *strDup(char *);
// install: put (name, defn) in hashtab
struct nlist *install(char *, char*);


unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}


struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            // Found
            return np;

    // Not found
    return NULL;
}


char *strDup(char *s)
{
    char *p;

    // +1 for '\0'
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);

    return p;
}


struct nlist *install(char *name, char*defn)
{
    struct nlist *np;
    unsigned hashval;

    // Not found
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strDup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = 
