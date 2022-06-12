#ifndef EX4_EXEPTION_H
#define EX4_EXEPTION_H

#include <iostream>
#include <string>

class DeckFileNotFound:public std::exception{
    public:
    const char * what() const noexcept override {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError:public std::logic_error{
    int m_line;
public:
    DeckFileFormatError(int line):
    std::logic_error("Deck File Error: File format error in line"
    +std::to_string(line)){
        m_line = line;
    }
};

class DeckFileInvalidSize:public std::exception{
public:
    const char * what() const noexcept override {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif //EX4_EXEPTION_H
