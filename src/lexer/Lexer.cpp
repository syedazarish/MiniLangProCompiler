#include "../../include/lexer/Lexer.h"
#include "../../include/lexer/CharacterClassifier.h"
#include "../../include/lexer/LexerConfig.h"
#include "../../include/lexer/CharacterClassifier.h"

Lexer::Lexer(const std::string& source)
    : buffer(source)
{
    line = 1;
    column = 1;
}

std::vector<Token> Lexer::tokenize()
{
    while (!buffer.isAtEnd())
    {
        scanToken();
    }

    addToken(TokenType::EndOfFile, "EOF");

    return tokens;
}
void Lexer::scanToken()
{
    
   skipWhitespace();

    if (buffer.isAtEnd())
        return;
    if (buffer.isAtEnd())
        return;

    char ch = buffer.current();

    // Identifier or Keyword
    if (CharacterClassifier::isIdentifierStart(ch))
    {
        scanIdentifier();
        return;
    }

    // Number
    if (CharacterClassifier::isDigit(ch))
    {
        scanNumber();
        return;
    }

    // TODO
    // String
    // Character
    // Operator
    // Delimiter
    // Comment

    buffer.advance();
    if (CharacterClassifier::isOperator(ch))
{
    scanOperator();
    return;
}
if (CharacterClassifier::isDelimiter(ch))
{
    scanDelimiter();
    return;
}
}
void Lexer::scanIdentifier()
{
    std::string lexeme;

  auto keyword = LexerConfig::KeywordMap.find(lexeme);

if (keyword != LexerConfig::KeywordMap.end())
{
    addToken(keyword->second, lexeme);
}
else if (LexerConfig::BooleanLiterals.count(lexeme))
{
    addToken(TokenType::BooleanLiteral, lexeme);
}
else
{
    addToken(TokenType::Identifier, lexeme);
}

    if (LexerConfig::Keywords.count(lexeme))
    {
        addToken(TokenType::Identifier, lexeme);   // Temporary
    }
    else if (LexerConfig::BooleanLiterals.count(lexeme))
    {
        addToken(TokenType::BooleanLiteral, lexeme);
    }
    else
    {
        addToken(TokenType::Identifier, lexeme);
    }
}

void Lexer::scanNumber()
{

    char ch = buffer.current();


    std::string lexeme;

    bool isFloat = false;

    while (!buffer.isAtEnd())
    {
        char ch = buffer.current();

        if (CharacterClassifier::isDigit(ch))
        {
            lexeme += ch;
            buffer.advance();
            column++;
        }
        else if (ch == '.' && !isFloat)
        {
            isFloat = true;

            lexeme += ch;

            buffer.advance();

            column++;
        }
        else
        {
            break;
        }
    }

    if (isFloat)
    {
        addToken(TokenType::FloatLiteral, lexeme);
    }
    else
    {
        addToken(TokenType::IntegerLiteral, lexeme);
    }
}
void Lexer::scanOperator()
{
    char ch = buffer.current();

    std::string lexeme;
    lexeme += ch;

    switch (ch)
    {
        case '+':
            addToken(TokenType::Plus, lexeme);
            break;

        case '-':
            addToken(TokenType::Minus, lexeme);
            break;

        case '*':
            addToken(TokenType::Multiply, lexeme);
            break;

        case '/':
            addToken(TokenType::Divide, lexeme);
            break;

        case '=':
            addToken(TokenType::Assign, lexeme);
            break;

        case '<':
            addToken(TokenType::LessThan, lexeme);
            break;

        case '>':
            addToken(TokenType::GreaterThan, lexeme);
            break;

        default:
            return;
    }

    buffer.advance();
    column++;
}
void Lexer::scanDelimiter()
{
    char ch = buffer.current();

    std::string lexeme;
    lexeme += ch;

    switch (ch)
    {
        case '(':
            addToken(TokenType::LeftParenthesis, lexeme);
            break;

        case ')':
            addToken(TokenType::RightParenthesis, lexeme);
            break;

        case '{':
            addToken(TokenType::LeftBrace, lexeme);
            break;

        case '}':
            addToken(TokenType::RightBrace, lexeme);
            break;

        case '[':
            addToken(TokenType::LeftBracket, lexeme);
            break;

        case ']':
            addToken(TokenType::RightBracket, lexeme);
            break;

        case ';':
            addToken(TokenType::Semicolon, lexeme);
            break;

        case ',':
            addToken(TokenType::Comma, lexeme);
            break;

        case ':':
            addToken(TokenType::Colon, lexeme);
            break;

        case '.':
            addToken(TokenType::Dot, lexeme);
            break;

        default:
            return;
    }

    buffer.advance();
    column++;
}
void Lexer::skipWhitespace()
{
    while (!buffer.isAtEnd())
    {
        char ch = buffer.current();

        if (ch == ' ')
        {
            buffer.advance();
            column++;
        }
        else if (ch == '\t')
        {
            buffer.advance();
            column += 4;
        }
        else if (ch == '\n')
        {
            buffer.advance();
            line++;
            column = 1;
        }
        else if (ch == '\r')
        {
            buffer.advance();
        }
        else
        {
            break;
        }
    }
}
void Lexer::addToken(
    TokenType type,
    const std::string& lexeme)
{
    SourceLocation location(
        line,
        column - static_cast<int>(lexeme.length())
    );

    Token token(
        type,
        lexeme,
        location
    );

    tokens.push_back(token);
}