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
    switch (type)
    {
        case TokenType::KW_Int: return "KW_Int";
        case TokenType::KW_Float: return "KW_Float";
        case TokenType::KW_Double: return "KW_Double";
        case TokenType::KW_Bool: return "KW_Bool";
        case TokenType::KW_Char: return "KW_Char";
        case TokenType::KW_String: return "KW_String";
        case TokenType::KW_Void: return "KW_Void";
        case TokenType::KW_Const: return "KW_Const";

        case TokenType::Identifier: return "Identifier";

        case TokenType::IntegerLiteral: return "IntegerLiteral";
        case TokenType::FloatLiteral: return "FloatLiteral";
        case TokenType::StringLiteral: return "StringLiteral";
        case TokenType::CharacterLiteral: return "CharacterLiteral";
        case TokenType::BooleanLiteral: return "BooleanLiteral";

        case TokenType::Plus: return "Plus";
        case TokenType::Minus: return "Minus";
        case TokenType::Multiply: return "Multiply";
        case TokenType::Divide: return "Divide";
        case TokenType::Assign: return "Assign";
        case TokenType::Increment: return "Increment";
        case TokenType::Semicolon: return "Semicolon";

        case TokenType::LeftParenthesis: return "LeftParenthesis";
        case TokenType::RightParenthesis: return "RightParenthesis";
        case TokenType::LeftBrace: return "LeftBrace";
        case TokenType::RightBrace: return "RightBrace";

        case TokenType::EndOfFile: return "EndOfFile";

        default:
            return "Unknown";
    }
}