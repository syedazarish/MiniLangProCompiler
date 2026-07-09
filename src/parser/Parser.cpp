#include "../../include/parser/Parser.h"
#include <stdexcept>

Parser::Parser(const std::vector<Token>& tokens)
{
    this->tokens = tokens;
    current = 0;
}

void Parser::parse()
{
    program();
}

void Parser::program()
{
    while (!isAtEnd())
    {
        if (isTypeSpecifier(currentToken().getType()))
        {
            declaration();
        }
        else
        {
            statement();
        }
    }
}

void Parser::declaration()
{
    // Type
    advance();

    // Identifier
    consume(
        TokenType::Identifier,
        "Expected identifier after type specifier."
    );

    // Optional initialization
    if (match(TokenType::Assign))
    {
        expression();
    }

    consume(
        TokenType::Semicolon,
        "Expected ';' after declaration."
    );
}
void Parser::statement()
{
    if (check(TokenType::KW_If))
    {
        ifStatement();
        return;
    }

    if (check(TokenType::Identifier))
    {
        assignmentStatement();
        return;
    }

    advance();
}

void Parser::expression()
{
    logicalOr();
}
void Parser::logicalOr()
{
    logicalAnd();

    while (match(TokenType::LogicalOr))
    {
        logicalAnd();
    }
}

void Parser::logicalAnd()
{
    equality();

    while (match(TokenType::LogicalAnd))
    {
        equality();
    }
}

void Parser::equality()
{
    comparison();

    while (match(TokenType::Equal) ||
           match(TokenType::NotEqual))
    {
        comparison();
    }
}

void Parser::comparison()
{
    term();

    while (match(TokenType::LessThan) ||
           match(TokenType::LessEqual) ||
           match(TokenType::GreaterThan) ||
           match(TokenType::GreaterEqual))
    {
        term();
    }
}

void Parser::term()
{
    factor();

    while (match(TokenType::Plus) ||
           match(TokenType::Minus))
    {
        factor();
    }
}

void Parser::factor()
{
    unary();

    while (match(TokenType::Multiply) ||
           match(TokenType::Divide) ||
           match(TokenType::Modulus))
    {
        unary();
    }
}

void Parser::unary()
{
    if (match(TokenType::LogicalNot) ||
        match(TokenType::Minus))
    {
        unary();
        return;
    }

    primary();
}

void Parser::primary()
{
    if (match(TokenType::IntegerLiteral)) return;

    if (match(TokenType::FloatLiteral)) return;

    if (match(TokenType::DoubleLiteral)) return;

    if (match(TokenType::BooleanLiteral)) return;

    if (match(TokenType::CharacterLiteral)) return;

    if (match(TokenType::StringLiteral)) return;

    if (match(TokenType::Identifier)) return;

    if (match(TokenType::LeftParenthesis))
    {
        expression();

        consume(
            TokenType::RightParenthesis,
            "Expected ')' after expression."
        );

        return;
    }

    throw std::runtime_error("Expected expression.");
}
void Parser::assignmentStatement()
{
    consume(
        TokenType::Identifier,
        "Expected identifier."
    );

    consume(
        TokenType::Assign,
        "Expected '=' after identifier."
    );

    // Parse complete expression
    expression();

    consume(
        TokenType::Semicolon,
        "Expected ';' after assignment."
    );
}
void Parser::ifStatement()
{
    consume(
        TokenType::KW_If,
        "Expected 'if'."
    );

    consume(
        TokenType::LeftParenthesis,
        "Expected '(' after if."
    );

    expression();

    consume(
        TokenType::RightParenthesis,
        "Expected ')' after condition."
    );

    consume(
        TokenType::LeftBrace,
        "Expected '{'."
    );

    while (!check(TokenType::RightBrace) && !isAtEnd())
    {
        if (isTypeSpecifier(currentToken().getType()))
        {
            declaration();
        }
        else
        {
            statement();
        }
    }

    consume(
        TokenType::RightBrace,
        "Expected '}' after if block."
    );

    if (check(TokenType::KW_Else))
    {
        elseStatement();
    }
}
bool Parser::isAtEnd() const
{
    return current >= tokens.size() ||
           tokens[current].getType() == TokenType::EndOfFile;
}

const Token& Parser::currentToken() const
{
    return tokens[current];
}

const Token& Parser::previousToken() const
{
    return tokens[current - 1];
}

void Parser::advance()
{
    if (!isAtEnd())
    {
        current++;
    }
}
bool Parser::check(TokenType type) const
{
    if (isAtEnd())
        return false;

    return currentToken().getType() == type;
}

bool Parser::match(TokenType type)
{
    if (check(type))
    {
        advance();
        return true;
    }

    return false;
}
void Parser::consume(TokenType type, const std::string& message)
{
    if (check(type))
    {
        advance();
        return;
    }

    throw std::runtime_error(message);
}

bool Parser::isTypeSpecifier(TokenType type) const
{
    switch (type)
    {
        case TokenType::KW_Int:
        case TokenType::KW_Float:
        case TokenType::KW_Double:
        case TokenType::KW_Bool:
        case TokenType::KW_Char:
        case TokenType::KW_String:
        case TokenType::KW_Void:
            return true;

        default:
            return false;
    }
}