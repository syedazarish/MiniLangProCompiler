#include "../../include/lexer/Lexer.h"
#include "../../include/lexer/CharacterClassifier.h"
#include "../../include/lexer/LexerConfig.h"

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

    char ch = buffer.current();

    // Identifier / Keyword
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

    // String
    if (ch == '"')
    {
        scanString();
        return;
    }

    // Character
    if (ch == '\'')
    {
        scanCharacter();
        return;
    }

    // Comment
    if (ch == '/' && (buffer.peek() == '/' || buffer.peek() == '*'))
    {
        skipComment();
        return;
    }

    // Operator
    if (CharacterClassifier::isOperator(ch))
    {
        scanOperator();
        return;
    }

    // Delimiter
    if (CharacterClassifier::isDelimiter(ch))
    {
        scanDelimiter();
        return;
    }

    // Unknown character
    buffer.advance();
    column++;
}
void Lexer::scanIdentifier()
{
    std::string lexeme;

    while (!buffer.isAtEnd() &&
           CharacterClassifier::isIdentifierPart(buffer.current()))
    {
        lexeme += buffer.current();
        buffer.advance();
        column++;
    }

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
}
void Lexer::scanNumber()
{
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
    char next = buffer.peek();

    std::string lexeme;

    switch (ch)
    {
        case '+':
            if (next == '+')
            {
                lexeme = "++";
                addToken(TokenType::Increment, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else if (next == '=')
            {
                lexeme = "+=";
                addToken(TokenType::PlusAssign, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else
            {
                lexeme = "+";
                addToken(TokenType::Plus, lexeme);
                buffer.advance();
                column++;
            }
            break;

        case '-':
            if (next == '-')
            {
                lexeme = "--";
                addToken(TokenType::Decrement, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else if (next == '=')
            {
                lexeme = "-=";
                addToken(TokenType::MinusAssign, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else
            {
                lexeme = "-";
                addToken(TokenType::Minus, lexeme);
                buffer.advance();
                column++;
            }
            break;

        case '*':
            if (next == '=')
            {
                lexeme = "*=";
                addToken(TokenType::MultiplyAssign, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else
            {
                lexeme = "*";
                addToken(TokenType::Multiply, lexeme);
                buffer.advance();
                column++;
            }
            break;

        case '/':
            if (next == '=')
            {
                lexeme = "/=";
                addToken(TokenType::DivideAssign, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else
            {
                lexeme = "/";
                addToken(TokenType::Divide, lexeme);
                buffer.advance();
                column++;
            }
            break;

        case '%':
            lexeme = "%";
            addToken(TokenType::Modulus, lexeme);
            buffer.advance();
            column++;
            break;

        case '=':
            if (next == '=')
            {
                lexeme = "==";
                addToken(TokenType::Equal, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else
            {
                lexeme = "=";
                addToken(TokenType::Assign, lexeme);
                buffer.advance();
                column++;
            }
            break;

        case '!':
            if (next == '=')
            {
                lexeme = "!=";
                addToken(TokenType::NotEqual, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else
            {
                lexeme = "!";
                addToken(TokenType::LogicalNot, lexeme);
                buffer.advance();
                column++;
            }
            break;

        case '<':
            if (next == '=')
            {
                lexeme = "<=";
                addToken(TokenType::LessEqual, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else
            {
                lexeme = "<";
                addToken(TokenType::LessThan, lexeme);
                buffer.advance();
                column++;
            }
            break;

        case '>':
            if (next == '=')
            {
                lexeme = ">=";
                addToken(TokenType::GreaterEqual, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else
            {
                lexeme = ">";
                addToken(TokenType::GreaterThan, lexeme);
                buffer.advance();
                column++;
            }
            break;

        case '&':
            if (next == '&')
            {
                lexeme = "&&";
                addToken(TokenType::LogicalAnd, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else
            {
                lexeme = "&";
                addToken(TokenType::BitAnd, lexeme);
                buffer.advance();
                column++;
            }
            break;

        case '|':
            if (next == '|')
            {
                lexeme = "||";
                addToken(TokenType::LogicalOr, lexeme);
                buffer.advance();
                buffer.advance();
                column += 2;
            }
            else
            {
                lexeme = "|";
                addToken(TokenType::BitOr, lexeme);
                buffer.advance();
                column++;
            }
            break;

        case '^':
            lexeme = "^";
            addToken(TokenType::BitXor, lexeme);
            buffer.advance();
            column++;
            break;

        case '~':
            lexeme = "~";
            addToken(TokenType::BitNot, lexeme);
            buffer.advance();
            column++;
            break;

        default:
            buffer.advance();
            column++;
            break;
    }
}
void Lexer::scanDelimiter()
{
    char ch = buffer.current();

    std::string lexeme(1, ch);

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
            buffer.advance();
            column++;
            return;
    }

    buffer.advance();
    column++;
}
void Lexer::scanString()
{
    std::string lexeme;

    // Skip opening quote
    buffer.advance();
    column++;

    while (!buffer.isAtEnd())
    {
        char ch = buffer.current();

        if (ch == '"')
        {
            // Closing quote found
            buffer.advance();
            column++;

            addToken(TokenType::StringLiteral, lexeme);
            return;
        }

        // New line before closing quote
        if (ch == '\n')
        {
            // Temporary error recovery
            buffer.advance();
            line++;
            column = 1;
            return;
        }

        lexeme += ch;
        buffer.advance();
        column++;
    }

    // EOF reached before closing quote
    return;
}
void Lexer::scanCharacter()
{
    std::string lexeme;

    // Skip opening single quote
    buffer.advance();
    column++;

    if (buffer.isAtEnd())
        return;

    char ch = buffer.current();

    // Handle escape sequences
    if (ch == '\\')
    {
        lexeme += ch;
        buffer.advance();
        column++;

        if (buffer.isAtEnd())
            return;

        lexeme += buffer.current();
        buffer.advance();
        column++;
    }
    else
    {
        lexeme += ch;
        buffer.advance();
        column++;
    }

    // Closing quote required
    if (!buffer.isAtEnd() && buffer.current() == '\'')
    {
        buffer.advance();
        column++;

        addToken(TokenType::CharacterLiteral, lexeme);
    }
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
void Lexer::skipComment()
{
    // Single-line comment
    if (buffer.current() == '/' && buffer.peek() == '/')
    {
        while (!buffer.isAtEnd() && buffer.current() != '\n')
        {
            buffer.advance();
            column++;
        }

        return;
    }

    // Multi-line comment
    if (buffer.current() == '/' && buffer.peek() == '*')
    {
        // Skip /*
        buffer.advance();
        buffer.advance();
        column += 2;

        while (!buffer.isAtEnd())
        {
            if (buffer.current() == '*' && buffer.peek() == '/')
            {
                // Skip */
                buffer.advance();
                buffer.advance();
                column += 2;
                return;
            }

            if (buffer.current() == '\n')
            {
                buffer.advance();
                line++;
                column = 1;
            }
            else
            {
                buffer.advance();
                column++;
            }
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