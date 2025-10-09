#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef enum {
    TOKEN_END,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
} TokenType;

typedef struct {
    TokenType type;
    double value;
} Token;

Token *tokenize(const char *input);

#endif // TOKENIZER_H
