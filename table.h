#ifndef __TREE__
#define __TREE__

#define M 11

typedef struct {
    short int t1_deleted_flag[M];
    int t1[M];

    int t2[M];
} table;

int table_search(int key, table *t);
int table_insert(int key, table *t);
int table_remove(int key, table *t);

void print_table(table *t);

#endif