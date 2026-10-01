#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"
using namespace std;

Clothing::Clothing(const string& name, double price, int qty,
                    const string& size, const string& brand)
        : Product("clothing", name, price, qty), size_(size),brand_(brand)
{

}

Clothing::~Clothing()
{

}

set<string> Clothing::keywords() const
{
  set<string> kw = parseStringToWords(name_);
  set<string> brandWords = parseStringToWords(brand_);
  kw = setUnion(kw, brandWords);
  return kw;
}

string Clothing::displayString() const
{
  ostringstream oss;
  oss << name_ << "\n" << "Size: " << size_ << " Brand: " << brand_ << "\n"
      << fixed << setprecision(2) << price_ << " " << qty_ << " left.";
  return oss.str();
}

void Clothing::dump(ostream& os) const
{
  Product::dump(os);
  os << size_ << "\n" << brand_ << endl;
}