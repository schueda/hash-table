#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "table.h"

int hash1(int key) {
    return key % M;
}

int hash2(int key) {
    return floor(M * (key * 0.9 - floor(key * 0.9)));
}

table *create_table() {
    table *t = malloc(sizeof(table));

    t->t1 = malloc(M * sizeof(int));
    t->t1_valid = calloc(M * sizeof(short int), M);

    t->t2 = malloc(M * sizeof(int));
    t->t2_valid = calloc(M * sizeof(int), M);

    return t;
}

int table_search(int key, table *t) {
    int index = hash1(key);

    if((t->t1[index] == key) && (t->t1_valid[index])) {
        return index;
    }

    int index2 = hash2(key);

    if ((t->t2[index2] == key) && (t->t2_valid[index2])) {
        return index2;
    }

    return -1;
}

int table_insert(int key, table *t) {
    int index = hash1(key);

    if (!t->t1_valid[index]) {
        t->t1[index] = key;
        t->t1_valid[index] = 1;
        
        return index;
    }

    if (t->t1[index] == key) {
        return index;
    }

    int index2 = hash2(key);
    if (t->t2_valid[index2]) {
        return -1;
    }

    int found_key = t->t1[index];
    int found_index2 = hash2(found_key);

    t->t2[found_index2] = found_key;
    t->t2_valid[found_index2] = 1;

    t->t1[index] = key;
    t->t1_valid[index] = 1;

    return index;
}

int table_remove(int key, table *t) {
    int index = hash1(key);

    if (t->t1[index] == key) {
        t->t1_valid[index] = 0;
        return index;
    }

    int index2 = hash2(key);
    t->t2_valid[index2] = 0;

    return index2;
}


int compare_strings(const void *a, const void *b) {
    int value_a = atoi(*(const char **)a);
    int value_b = atoi(*(const char **)b);

    char *first_comma_a = strchr(*(const char **)a, ',');
    char *first_comma_b = strchr(*(const char **)b, ',');
    int table_a = atoi(first_comma_a + 2);
    int table_b = atoi(first_comma_b + 2);

    char *second_comma_a = strchr(first_comma_a + 1, ',');
    char *second_comma_b = strchr(first_comma_b + 1, ',');
    int index_a = atoi(second_comma_a + 1);
    int index_b = atoi(second_comma_b + 1);

    if (value_a < value_b) {
        return -1;
    } else if (value_a > value_b) {
        return 1;
    } else {
        if (table_a < table_b) {
            return -1;
        } else if (table_a > table_b) {
            return 1;
        } else {
            if (index_a < index_b) {
                return -1;
            } else if (index_a > index_b) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

void print_table(table *t) {
    char **elements = calloc(M * sizeof(char*), M);

    int i, j = 0;
    for (i = 0; i < M; i++) {
        if (t->t1_valid[i]) {
            elements[j] = malloc(20 * sizeof(char));
            sprintf(elements[j], "%d,T1,%d", t->t1[i], i);
            j++;
        }
    }

    for (i = 0; i < M; i++) {
        if (t->t2_valid[i]) {
            elements[j] = malloc(20 * sizeof(char));
            sprintf(elements[j], "%d,T2,%d", t->t2[i], i);
            j++;
        }
    }

    qsort(elements, j, sizeof(char*), compare_strings);

    for (i = 0; i < j; i++) {
        printf("%s\n", elements[i]);
        free(elements[i]);
    }
    free(elements);
}

void destroy_table(table *t) {
    free(t->t1);
    free(t->t1_valid);

    free(t->t2);
    free(t->t2_valid);

    free(t);
}