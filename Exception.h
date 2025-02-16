#ifndef EX4_EXEPTION_H
#define EX4_EXEPTION_H

#include <iostream>
#include <string>
#include <cstring>


class DeckFileNotFound:public std::exception
{
    public:
    const char * what() const noexcept override
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError:public std::exception
{
    int m_line;
    std::string message;
public:
    explicit DeckFileFormatError(int line): std::exception() ,message()
    {
        m_line = line;
        message = "Deck File Error: File format error in line "
                                              +std::to_string(m_line);
    }
    const char * what() const noexcept override
    {
        return message.c_str();
    }
};

class DeckFileInvalidSize:public std::exception
{
public:
    const char * what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif //EX4_EXEPTION_H
