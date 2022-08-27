#include <stdio.h>
#include <stdlib.h>

#include "table.h"

#define LINE_SIZE 20

int main() {
    char line[LINE_SIZE+1];
    int key;

    table *t = malloc(sizeof(table));
    
    fgets(line, LINE_SIZE, stdin);
    while (!feof(stdin)) {
        key = atoi(&line[1]);

        if (line[0] == 'i') {
            table_insert(key, t);
        }

        if (line[0] == 'r') {
            table_remove(key, t);
        }

        fgets(line, LINE_SIZE, stdin);
    }

    print_table(t);

    free(t);
    return 0;
}
