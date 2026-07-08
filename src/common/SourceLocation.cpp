#include "../../include/common/SourceLocation.h"

SourceLocation::SourceLocation()
{
    line = 1;
    column = 1;
    fileName = "";
}

SourceLocation::SourceLocation(
    int line,
    int column,
    const std::string& fileName)
{
    this->line = line;
    this->column = column;
    this->fileName = fileName;
}

int SourceLocation::getLine() const
{
    return line;
}

int SourceLocation::getColumn() const
{
    return column;
}

std::string SourceLocation::getFileName() const
{
    return fileName;
}

void SourceLocation::setLine(int line)
{
    this->line = line;
}

void SourceLocation::setColumn(int column)
{
    this->column = column;
}

void SourceLocation::setFileName(const std::string& fileName)
{
    this->fileName = fileName;
}