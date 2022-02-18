#include "landlord.h"

tenant::tenant(string n, int aNo) {
  this->name = n;
  this->aptNumber = aNo; 
}

tenant::~tenant() {

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

void tenantList::insertTenant(tenant* tenant) {
  setPtrsTens.insert(tenant);
}

int main() {
  tenant tenantObj("wilson", 134);

  cout << tenantObj << endl;
}