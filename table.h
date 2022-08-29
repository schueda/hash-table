#ifndef __TREE__
#define __TREE__

#define M 11

typedef struct {
    int *t1;
    short int *t1_valid;

    int *t2;
    int *t2_valid;
} table;

table *create_table();

int table_search(int key, table *t);
int table_insert(int key, table *t);
int table_remove(int key, table *t);

void print_table(table *t);

void destroy_table(table *t);

#endif