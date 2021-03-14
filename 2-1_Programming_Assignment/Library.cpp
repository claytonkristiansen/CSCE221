#include "Library.h"
#include "TemplatedDLList.h"
#include <fstream>

using std::cout;
using std::cin;

int CharIndex(char c)
{
    c = toupper(c);
    return (int)(c - 65);
}

bool AlphabeticallyLess(const string s1, const string s2)
{
    int length;
    int l1 = s1.length();
    int l2 = s2.length();
    if(l1 < l2) {length = l1;}
    else        {length = l2;}

    for(int i = 0; i < length; ++i)
    {
        if(toupper(s1[i]) < toupper(s2[i])) {return true;}
        if(toupper(s1[i]) > toupper(s2[i])) {return false;}
    }
    if(l1 >= l2) {return false;}
    return true;
}

bool operator<(const Record& r1, const Record& r2)
{
    if(AlphabeticallyLess(r1.get_title(), r2.get_title())) {return true;}
    if((r1.get_title() == r2.get_title()) && AlphabeticallyLess(r1.get_author(), r2.get_author())) {return true;}
    if((r1.get_title() == r2.get_title()) && (r1.get_author() == r2.get_author()) && AlphabeticallyLess(r1.get_ISBN(), r2.get_ISBN())) {return true;}
    return false;
}

std::vector<Record> Library::search(std::string title) //TODO: Implement binary search
{
    std::vector<Record> matchingRecords;

    int index = CharIndex(title[0]);
    DLList<Record> subList = book_db[index];
    DLListNode<Record>* curr = subList.first_node();

    while(curr != subList.after_last_node())
    {
        if(curr->obj.get_title() == title)
        {
            matchingRecords.push_back(curr->obj);
        }
        curr = curr->next;
    }

    return matchingRecords;
}

//Imports records from a file.  Does not import duplicates.
// Return the number of records added to the database
int Library::import_database(std::string filename)
{
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << filename << " not found";
        return 1;
    }

    
    int count = 0;

    while(!ifs.eof())
    {
        Record rec;
        ifs >> rec;
        bool added = this->add_record(rec);
        if(added) {++count;}
    }

    return count;
}

//Exports the current database to a file
//Return the number of records exported
int Library::export_database(std::string filename)
{
    ofstream ofs(filename);
    if (!ofs.is_open()) {
        cout << filename << " not found";
        return 1;
    }

    int count = 0;

    for(DLList<Record> list : book_db)
    {
        DLListNode<Record>* curr = list.first_node();
        while(curr != list.after_last_node())
        {
            ofs << curr->obj << "\n";
            ++count;
            curr = curr->next;
        }
    }

    return count;
}

void Library::print_database()
{
    for(DLList<Record> list : book_db)
    {
        DLListNode<Record>* curr = list.first_node();
        while(curr != list.after_last_node())
        {
            std::cout << curr->obj << "\n";
            curr = curr->next;
        }
    }
}

//add record to database, avoid complete duplicates
bool Library::add_record(Record book)
{
    if( 
    book.get_title() == "" ||
    book.get_author() == "" ||
    book.get_ISBN() == "" ||
    book.get_year() == "" ||
    book.get_edition() == "") 
    {
        return false;
    }
    int index = CharIndex(book.get_title()[0]);
    DLList<Record> *list = &book_db[index];
    DLListNode<Record>* curr = list->first_node();
    while(curr != list->after_last_node())
    {
        if( 
        curr->obj.get_title() == book.get_title() &&
        curr->obj.get_author() == book.get_author() &&
        curr->obj.get_ISBN() == book.get_ISBN() &&
        curr->obj.get_year() == book.get_year() &&
        curr->obj.get_edition() == book.get_edition()) 
        {
            return false;
        }
        if(book < curr->obj)
        {
            list->insert_before(*curr, book);
            return true;
        }
        curr = curr->next;
    }
    list->insert_last(book);
    return true;
}

//Deletes a record from the database
void Library::remove_record(Record book)
{
    int index = CharIndex(book.get_title()[0]);
    DLList<Record> *list = &book_db[index];
    DLListNode<Record>* curr = list->first_node();
    while(curr != list->after_last_node())
    {
        if( 
        curr->obj.get_title() == book.get_title() &&
        curr->obj.get_author() == book.get_author() &&
        curr->obj.get_ISBN() == book.get_ISBN() &&
        curr->obj.get_year() == book.get_year() &&
        curr->obj.get_edition() == book.get_edition()) 
        {
            list->remove_before(*curr->next);
        }
        curr = curr->next;
    }
}

//Prompts user for yes or no and returns choice Y or N
char Library::prompt_yes_no()
{
    cout << "Yes(Y) or No(N): ";
    char input;
    cin >> input;
    if(input == 'y' || input == 'Y') {return 'Y';}
    if(input == 'n' || input == 'N') {return 'N';}
    return 'N';
}

//Given a vector of menu options returns index of choice
int Library::prompt_menu(std::vector<std::string> options)
{
    for(int i = 0; i < options.size(); ++i)
    {
        cout << i + 1 << ". " << options[i] << "\n";
    }
    cout << "Enter option: ";
    int input = 0;
    cin >> input;
    return input - 1;
}

//Prompts user for a new record
Record Library::prompt_record()
{
    string title = prompt_string("Title: ");
    string author = prompt_string("Author: ");
    string ISBN = prompt_string("ISBN: ");
    string year = prompt_string("Year: ");
    string edition = prompt_string("Edition: ");
    Record rec;
    rec.set_title(title);
    rec.set_author(author);
    rec.set_ISBN(ISBN);
    rec.set_year(year);
    rec.set_edition(edition);
    return rec;
}

//Prompt for a valid title
std::string Library::prompt_title()
{
    return prompt_string("Title: ");
}

// Prompt for a valid string
std::string Library::prompt_string(std::string prompt)
{
    cout << prompt;
    string input = "";
    getline(cin, input);
    cout << "\n";
    return input;
}