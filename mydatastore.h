#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <iostream>
#include "datastore.h"
#include "product.h"
#include "user.h"

class MyDataStore : public DataStore {
public:
  MyDataStore();
  virtual ~MyDataStore();

  virtual void addProduct(Product* p);
  virtual void addUser(User* u);
  virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);
  virtual void dump(std::ostream& ofile);

  bool addToCart(const std::string& username, std::vector<Product*>& hits, int hitIndex);
  bool viewCart(const std::string& username);
  bool buyCart(const std::string& username);

private:
  std::vector<Product*> products_;
  std::map<std::string, User*> users_;
  std::map<std::string, std::set<Product*> > keywordMap_;
  std::map<std::string, std::deque<Product*> > carts_;
};
#endif