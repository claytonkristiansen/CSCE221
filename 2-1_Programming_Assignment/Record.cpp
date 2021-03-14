//implementation of record class

#include "Record.h"


string Record::get_title() const { return title; }
void Record::set_title(string title) { this->title = title; }
string Record::get_author() const { return author; }
void Record::set_author(string author) { this->author = author; }
string Record::get_ISBN() const { return ISBN; }
void Record::set_ISBN(string ISBN) { this->ISBN = ISBN; }
string Record::get_year() const { return year; }
void Record::set_year(string year) { this->year = year; }
string Record::get_edition() const { return edition; }
void Record::set_edition(string edition) { this->edition = edition; }


std::istream& operator>>(std::istream& is, Record& rec)
{
    if(!is.eof())
    {
        string title = "";
        string author = "";
        string ISBN = "";
        string year = "";
        string edition = "";
        if(!is.eof()) std::getline(is, title);
        while(title == "" && !is.eof())
        {
            if(!is.eof()) std::getline(is, title);
        }
        if(!is.eof()) std::getline(is, author);
        if(!is.eof()) std::getline(is, ISBN);
        if(!is.eof()) std::getline(is, year);
        if(!is.eof()) std::getline(is, edition);
        rec.set_title(title);
        rec.set_author(author);
        rec.set_ISBN(ISBN);
        rec.set_year(year);
        rec.set_edition(edition);
    }
    return is;
}
std::ostream& operator<<(std::ostream& os, Record& rec)
{
    os << rec.get_title() << "\n";
    os << rec.get_author() << "\n";
    os << rec.get_ISBN() << "\n";
    os << rec.get_year() << "\n";
    os << rec.get_edition() << "\n";
    return os;
}

// Comparison operators
bool operator==(const Record& r1, const Record& r2)
{
    if( 
    r1.get_title() == r2.get_title() &&
    r1.get_author() == r2.get_author() &&
    r1.get_ISBN() == r2.get_ISBN())
    {
        return true;
    }
    return false;
}

