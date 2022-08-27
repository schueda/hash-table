#include <math.h>

#include "table.h"

int hash1(int key) {
    return key % M;
}

int hash2(int key) {
    return floor(M * (key * 0.9 - floor(key * 0.9)));
}

int table_search(int key, table *t) {
    return 0;
}

int table_insert(int key, table *t) {
    return 0;
}

int table_remove(int key, table *t) {
    return 0;
}

void print_table(table *t) {
    return 0;
}