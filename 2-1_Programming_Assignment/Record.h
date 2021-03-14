#include <iostream>
#include <string>
#include <fstream>

#ifndef Record_H
#define Record_H

using std::string;
using std::cout;
using std::ofstream;
using std::ifstream;

class Record {
private:
    string title;
    string author;
    string ISBN;
    string year;
    string edition;
public:
    string get_title() const ;
    void set_title(string title);
    string get_author() const ;
    void set_author(string title);
    string get_ISBN() const ;
    void set_ISBN(string title);
    string get_year() const ;
    void set_year(string title);
    string get_edition() const ;
    void set_edition(string title);
};

// Stream operators
std::istream& operator>>(std::istream& is, Record& rec);
std::ostream& operator<<(std::ostream& os, Record& rec);

// Comparison operators
bool operator==(const Record& r1, const Record& r2);
#endif