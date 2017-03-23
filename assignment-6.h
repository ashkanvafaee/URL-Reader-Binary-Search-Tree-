#pragma once

#define MAX_URL_LENGTH 100

struct tnode { /* the tree node: */
    char *key; /* points to the url string */
    int count; /* number of occurrences */
    struct tnode *left; /* left child */
    struct tnode *right; /* right child */
};

void populate_tree(char*, struct tnode**);
struct tnode* add_to_tree(struct tnode*, char* );
int lookup(struct tnode*, char*); 
int tree_traversal(int, struct tnode*, char [][MAX_URL_LENGTH], int*);

