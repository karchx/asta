#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int main() {
    char input[256];
    printf("Enter an expression (e.g., 5 + 5 - 2): ");
    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0'; // Remove newline character
    }

    Token *tokens = tokenize(input);

    printf("Tokens: %p\n", tokens);
    free(tokens);

    return 0;
}
