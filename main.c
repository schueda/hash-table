#include <stdio.h>
#include <stdlib.h>

#include "table.h"

#define LINE_SIZE 20

int main() {
    char line[LINE_SIZE+1];
    int key;

    //Cria a tabela
    table *t = create_table();
    
    fgets(line, LINE_SIZE, stdin);
    while (!feof(stdin)) {
        //Recebe o valor
        key = atoi(&line[1]);

        //Insere o valor na tabela se o comando for 'i'
        if (line[0] == 'i') {
            table_insert(key, t);
        }

        //Insere o valor na tabela se o comando for 'r'
        if (line[0] == 'r') {
            table_remove(key, t);
        }

        fgets(line, LINE_SIZE, stdin);
    }

    //Exibe a tabela
    print_table(t);

    destroy_table(t);
    return 0;
}