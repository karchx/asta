#include <stdlib.h>
#include <ctype.h>
#include "../include/tokenizer.h"

Token *tokenize(const char *input) {
    Token *tokens = malloc(256 * sizeof(Token));
    int pos = 0;

    while (*input) {
        if (isdigit(*input)) {
            tokens[pos].type = TOKEN_NUMBER;
            tokens[pos].value = strtol(input, (char **)&input, 10);
            pos++;
        } else if (*input == '+') {
            tokens[pos].type = TOKEN_PLUS;
            input++;
            pos++;
        } else if (*input == '-') {
            tokens[pos].type = TOKEN_MINUS;
            input++;
            pos++;
        } else if (*input == '*') {
            tokens[pos].type = TOKEN_MULTIPLY;
            input++;
            pos++;
        } else if (*input == '/') {
            tokens[pos].type = TOKEN_DIVIDE;
            input++;
            pos++;
        } else if (isspace(*input)) {
            input++;
        } else {
            input++;
        }
    }

    tokens[pos].type = TOKEN_END;
    return tokens;
}
