#ifndef TOKEN_H
#define TOKEN_H

#include <string>

#include "TokenType.h"
#include "SourceLocation.h"

class Token
{
private:

    TokenType type;

    std::string lexeme;

    SourceLocation location;

public:

    Token();

    Token(
        TokenType type,
        const std::string& lexeme,
        const SourceLocation& location
    );

    TokenType getType() const;

    std::string getLexeme() const;

    SourceLocation getLocation() const;

    void setType(TokenType type);

    void setLexeme(const std::string& lexeme);

    void setLocation(const SourceLocation& location);

    std::string toString() const;
};

#endif