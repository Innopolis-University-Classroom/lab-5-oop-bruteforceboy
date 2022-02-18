#include "landlord.h"

tenant::tenant(string n, int aNo) {
  this->name = n;
  this->aptNumber = aNo;
}

tenant::~tenant() {

}

string tenant::getName() {
  return name;
}

int tenant::getAptNumber() {
  return aptNumber;
}

bool operator<(const tenant& t1, const tenant& t2) {
  return t1.name < t2.name;
}

bool operator==(const tenant& t1, const tenant& t2) {
  return t1.name == t2.name;
}

ostream& operator<<(ostream& os, const tenant& tenant) {
  os << "Apartment Number: " << tenant.aptNumber << std::endl;
  os << "Name: " << tenant.name;

  return os;
}

bool compareTenants::operator() (tenant* t1, tenant* t2) const {
  return t1 <= t2;
}

tenantList::~tenantList() {

}

void tenantList::insertTenant(tenant* tenant) {
  setPtrsTens.insert(tenant);
}

int tenantList::getAptNo(string tenant) {
  for (auto& t : setPtrsTens) {
    if (t->getName() == tenant) {
      return t->getAptNumber();
    }
  }
  return -1; // returns if the tenant's name was not found in our set
}

int main() {
  tenant tenantObj1("wilson", 134);
  tenant tenantObj2("fred", 543);

  cout << tenantObj1 << endl;
  cout << tenantObj2 << endl;

  tenantList list;
  list.insertTenant(&tenantObj1);
  list.insertTenant(&tenantObj2);

  cout << list.getAptNo("fred") << endl;
}