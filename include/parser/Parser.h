#ifndef PARSER_H
#define PARSER_H

#include <vector>

#include "../common/Token.h"

class Parser
{
private:

    std::vector<Token> tokens;

    size_t current;

public:

    explicit Parser(const std::vector<Token>& tokens);

    void parse();

private:

    // Grammar Entry
    void program();

    // Declarations
    void declaration();

    // Statements
    void statement();

    // Expressions
    void expression();
    void assignmentStatement();
    void ifStatement();

    // Utility
    bool isAtEnd() const;

    const Token& currentToken() const;

    const Token& previousToken() const;
    bool check(TokenType type) const;

bool match(TokenType type);

void consume(TokenType type, const std::string& message);

bool isTypeSpecifier(TokenType type) const;

    void advance();
};

#endif