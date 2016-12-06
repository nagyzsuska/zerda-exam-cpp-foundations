#include "Carrier.h"

#include <iostream>

using namespace std;

int main() {
  F16 f16;
  cout << f16.get_status() << endl;
  unsigned int ammo = 4;
  f16.refill(ammo);
  cout << f16.get_status() << endl;
  f16.fight();
  cout << f16.get_status() << endl;
  cout << ammo << endl;
  f16.refill(ammo);
  cout << f16.get_type() << endl;
  
  Carrier c(0, 600);
  c.add_aircraft("F16");
  c.add_aircraft("F16");
  c.add_aircraft("F16");
  c.add_aircraft("F35");
  c.add_aircraft("F35");
  c.add_aircraft("F35");
 
  try {
    c.fill();
  }
  catch (string str) {
  cout << str;
  }
  cout << c.get_status();

  cout << "Total damage: "<< c.get_total_damage();
  return 0;
}
