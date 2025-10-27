#include "../include/parser.h"

int parse(Token *tokens, int *result) {
    int pos = 0;
    if (tokens[pos].type != TOKEN_NUMBER) {
        return 0;
    }

    *result = tokens[pos].value;
    pos++;

    while (tokens[pos].type != TOKEN_END) {
        if (tokens[pos].type == TOKEN_PLUS) {
            pos++;
            if (tokens[pos].type != TOKEN_NUMBER) {
                return 0;
            }
            *result += tokens[pos].value;
        } else if (tokens[pos].type == TOKEN_MINUS) {
            pos++;
            if (tokens[pos].type != TOKEN_NUMBER) {
                return 0;
            }
            *result -= tokens[pos].value;
        } else if (tokens[pos].type == TOKEN_MULTIPLY) {
            pos++;
            if (tokens[pos].type != TOKEN_NUMBER) {
                return 0;
            }
            *result *= tokens[pos].value;
        } else if (tokens[pos].type == TOKEN_DIVIDE) {
            pos++;
            if (tokens[pos].type != TOKEN_NUMBER) {
                return 0;
            }
            if (tokens[pos].value == 0) {
                return 0; // Division by zero error
            }
            *result /= tokens[pos].value;
        } else {
            return 0; // Invalid token
        }
        pos++;
    }
    return 1;
}
