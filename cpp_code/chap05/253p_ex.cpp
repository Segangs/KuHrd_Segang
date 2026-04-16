//미완성

#include <iostream>
#include <cstring>
using namespace std;

class Book
{
    double price;
    int pages;
    char *title;
    char *author;

public:
    Book(double pr, int pa, char *t, char *a);
    //Book(const Book &book);
    ~book();
};

Book::Book(double pr, int pa, char *t, char *a)
{
    this->price = pr;
    this->pages = pa;
    this->title = t;
    this->author = a;

    int len = strlen(title);
    int len2 = strlen(author);

    this->title = new char[len + 1];
    this->author = new char[len2 + 1];

    strcpy(this->title, title);
    strcpy(this->author, author);
}

// 복사 생성자

Book::Book(const Book &book)
{

    this->price = book.price;
    this->pages = book.pages;

    int len = strlen(book.title);
    int len2 = strlen(book.author);

    this->title = new char[len + 1];
    this->author = new char[len2 + 1];

    strcpy(this->title, book.title);            
    strcpy(this->author, book.author);
}

Book::~Book
{

}

int main()
{
    Book a(25000,12,"책이름","저자이름");
    Book b(a);

    return 0;
}