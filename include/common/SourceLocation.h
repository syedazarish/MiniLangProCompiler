#ifndef SOURCE_LOCATION_H
#define SOURCE_LOCATION_H

#include <string>

class SourceLocation
{
private:

    int line;

    int column;

    std::string fileName;

public:

    SourceLocation();

    SourceLocation(
        int line,
        int column,
        const std::string& fileName = ""
    );

    int getLine() const;

    int getColumn() const;

    std::string getFileName() const;

    void setLine(int line);

    void setColumn(int column);

    void setFileName(const std::string& fileName);
};

#endif