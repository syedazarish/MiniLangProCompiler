#ifndef INPUT_BUFFER_H
#define INPUT_BUFFER_H

#include <string>

class InputBuffer
{
private:

    std::string source;

    size_t currentIndex;

public:

    InputBuffer();

    explicit InputBuffer(const std::string& source);

    char current() const;

    char peek() const;

    char advance();

    bool isAtEnd() const;

    void reset();

    size_t position() const;
};

#endif