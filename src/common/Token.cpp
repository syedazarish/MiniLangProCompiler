#include "../../include/common/Token.h"

Token::Token()
{
    type = TokenType::Unknown;
    lexeme = "";
    location = SourceLocation();
}

Token::Token(
    TokenType type,
    const std::string& lexeme,
    const SourceLocation& location)
{
    this->type = type;
    this->lexeme = lexeme;
    this->location = location;
}

TokenType Token::getType() const
{
    return type;
}

std::string Token::getLexeme() const
{
    return lexeme;
}

SourceLocation Token::getLocation() const
{
    return location;
}

void Token::setType(TokenType type)
{
    this->type = type;
}

void Token::setLexeme(const std::string& lexeme)
{
    this->lexeme = lexeme;
}

void Token::setLocation(const SourceLocation& location)
{
    this->location = location;
}

std::string Token::toString() const
{
    return lexeme;
}