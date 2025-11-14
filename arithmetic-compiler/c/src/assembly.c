#include <stdio.h>
#include "../include/assembly.h"

void generate_assembly(Token *tokens) {
    int pos = 0;
    printf("LOAD: %f.2\n", tokens[pos].value);
    pos++;

    while(tokens[pos].type != TOKEN_END) {
        if (tokens[pos].type == TOKEN_PLUS) {
            pos++;
            printf("ADD: %f.2\n", tokens[pos].value);
        } else if (tokens[pos].type == TOKEN_MINUS) {
            pos++;
            printf("MINUS: %f.2\n", tokens[pos].value);
        } else if (tokens[pos].type == TOKEN_MULTIPLY) {
            pos++;
            printf("MULTIPLY: %f.2\n", tokens[pos].value);
        } else if (tokens[pos].type == TOKEN_DIVIDE) {
            pos++;
            printf("DIVIDE: %f.2\n", tokens[pos].value);
        }
        pos++;
    }
}
