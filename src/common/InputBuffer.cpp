#include "../../include/common/InputBuffer.h"

InputBuffer::InputBuffer()
{
    source = "";
    currentIndex = 0;
}

InputBuffer::InputBuffer(const std::string& source)
{
    this->source = source;
    currentIndex = 0;
}

char InputBuffer::current() const
{
    if(currentIndex >= source.length())
        return '\0';

    return source[currentIndex];
}

char InputBuffer::peek() const
{
    if(currentIndex + 1 >= source.length())
        return '\0';

    return source[currentIndex + 1];
}

char InputBuffer::advance()
{
    if(currentIndex >= source.length())
        return '\0';

    return source[currentIndex++];
}

bool InputBuffer::isAtEnd() const
{
    return currentIndex >= source.length();
}

void InputBuffer::reset()
{
    currentIndex = 0;
}

size_t InputBuffer::position() const
{
    return currentIndex;
}