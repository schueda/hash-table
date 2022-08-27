#include <stdio.h>
#include <stdlib.h>

#include "table.h"

#define LINE_SIZE 20

int main() {
    char line[LINE_SIZE+1];
    int key;
    
    fgets(line, LINE_SIZE, stdin);
    while (!feof(stdin)) {
        key = atoi(&line[1]);

        if (line[0] == 'i') {
            table_insert(key);
        }

        if (line[0] == 'r') {
            tbale_remove(key);
        }

        fgets(line, LINE_SIZE, stdin);
    }

    //PRINTA AS TABELAS


    return 0;
}
