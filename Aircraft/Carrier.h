#ifndef CARRIER_
#define CARRIER_

#include "F16.h"
#include "F35.h"
#include <vector>

class Carrier {
private:
  std::vector<Aircrafts*> aircrafts_vector;
  unsigned int m_ammo_storage;
  unsigned int m_total_damage;
  int m_health_point;
public:
  Carrier(int ammo, int health_point);
  void add_aircraft(std::string aircraft_type);
  void fill();
  void fight(Carrier &c);
  int Carrier::get_total_damage();
  std::string to_string(int integer);
  std::string get_status();
  ~Carrier();
};


#endif // !CARRIER_

