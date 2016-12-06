#ifndef AIRCRAFTS_
#define AIRCRAFTS_

#include <string>

class Aircrafts {
protected:
  unsigned int m_ammo_level;
  unsigned int m_max_ammo;
  int m_base_damage;
  int m_all_damage;
  std::string aircraft_type;
public:
  Aircrafts();
  unsigned int fight();
  void refill(unsigned int &ammo);
  std::string get_type();
  int get_damage();
  int get_ammo_level();
  int get_max_ammmo();
  std::string Aircrafts::to_string(int integer);
  std::string get_status();

  ~Aircrafts();
};


#endif // !AIRCRAFTS_