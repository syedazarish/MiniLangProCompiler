#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>

#include "../common/Token.h"
#include "../common/InputBuffer.h"
#include "LexerState.h"
#include "../common/TokenType.h"

class Lexer
{
private:

    InputBuffer buffer;

    int line;

    int column;

    std::vector<Token> tokens;

public:

    explicit Lexer(const std::string& source);

    std::vector<Token> tokenize();

private:

    void scanToken();

    void scanIdentifier();

    void scanNumber();

    void scanString();

    void scanCharacter();

    void scanOperator();

    void scanDelimiter();

    void skipWhitespace();

    void skipComment();

    void addToken(
        TokenType type,
        const std::string& lexeme
    );
};

#endif