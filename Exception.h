#ifndef EX4_EXEPTION_H
#define EX4_EXEPTION_H

#include <iostream>
#include <string>
#include <cstring>


class DeckFileNotFound:public std::exception{
    public:
    const char * what() const noexcept override {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError:public std::exception{
    int m_line;
public:
    explicit DeckFileFormatError(int line): std::exception()
    {
        m_line = line;
    }
    const char * what() const noexcept override {
        std::string temp  = "Deck File Error: File format error in line " +std::to_string(m_line)+"\0";
        char * tempChars = new char[temp.size()];
        std::strcpy (tempChars, temp.c_str());
        return  tempChars;
    }
};

class DeckFileInvalidSize:public std::exception{
public:
    const char * what() const noexcept override {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif //EX4_EXEPTION_H
