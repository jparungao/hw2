#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"
using namespace std;

Book::Book(const string& name, double price, int qty,
            const string& isbn, const string& author) 
          : Product("book", name, price, qty), isbn_(isbn), author_(author)
{

}


Book::~Book()
{

}


set<string> Book::keywords() const{
  set<string> kw = parseStringToWords(name_);
  set<string> authorWords = parseStringToWords(author_);
  kw = setUnion(kw, authorWords);
  kw.insert(convToLower(isbn_));
  return kw;
}

string Book::displayString() const{
  ostringstream oss;
  oss << name_ << "\n" << "Author: " << author_ << " ISBN: " << isbn_ << "\n"
      << fixed << setprecision(2) << price_ << " " << qty_ << " left.";
      return oss.str();
}

void Book::dump(ostream& os) const{
  Product::dump(os);
  os << isbn_ << "\n" << author_ << endl;
}