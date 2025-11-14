#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tokenizer.h"
#include "../include/parser.h"
#include "../include/assembly.h"

int main() {
    char input[256];
    printf("Enter an expression (e.g., 5 + 5 - 2): ");
    fgets(input, sizeof(input), stdin);

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0'; // Remove newline character
    }

    Token *tokens = tokenize(input);
    int result;

    if (parse(tokens, &result)) {
        printf("Result: %d\n", result);
        generate_assembly(tokens);
    } else {
        printf("Error parsing expression.\n");
    }
    free(tokens);

    return 0;
}
