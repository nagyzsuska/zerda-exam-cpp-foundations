#include "Carrier.h"

#include <sstream>
#include <iostream>

Carrier::Carrier(int ammo, int health_point) {
  aircrafts_vector.resize(0, NULL);
  m_ammo_storage = ammo;
  m_health_point = health_point;
  m_total_damage = 0;
}

void Carrier::add_aircraft(std::string aircraft_type) {
  if (aircraft_type == "F16") {
    F16* f16 = new F16;
    aircrafts_vector.push_back(f16);
  }
  if (aircraft_type == "F35") {
    F35* f35 = new F35;
    aircrafts_vector.push_back(f35);
  }
}

void Carrier::fill() throw (std::string) {
  if (m_ammo_storage == 0) {
    throw "There is no ammo.";
  }
  int ammo_needed = 0;
  for (int i = 0; i < aircrafts_vector.size(); i++) {
    ammo_needed = ammo_needed + (aircrafts_vector[i]->get_max_ammmo() - aircrafts_vector[i]->get_ammo_level());
  }
  if (m_ammo_storage < ammo_needed) {
    for (int i = 0; i < aircrafts_vector.size(); i++) {
      if ("F35" == aircrafts_vector[i]->get_type()) {
        aircrafts_vectors[i]->refill(m_ammo_storage);
        if (m_ammo_storage <= 0) {
          break;
        }
      }
    }
  } else if (m_ammo_storage >= ammo_needed) {
    for (int i = 0; i < aircrafts_vector.size(); i++) {
      aircrafts_vector[i]->refill(m_ammo_storage);
      if (m_ammo_storage <= 0) {
        break;
      }
    }
  }
}

/*void Carrier::fight(Carrier &c) {
  for (unsigned int i = 0; i < aircrafts_vector.size(); i++) {
   (aircrafts_vector[i]->fight());
  }
}*/

int Carrier::get_total_damage() {
  for (int i = 0; i < aircrafts_vector.size(); i++) {
    m_total_damage += aircrafts_vector[i]->get_damage();
  }
  return m_total_damage;
}

std::string Carrier::to_string(int integer) {
  std::stringstream ss;
  ss << integer;
  return ss.str();
}

std::string Carrier::get_status() {
  for (int i = 0; i < aircrafts_vector.size(); i++) {
   std::cout << aircrafts_vector[i]->get_status();
  }
  return "Aircraft count: " + to_string(aircrafts_vector.size()) + ", Ammo Storage: " + to_string(m_ammo_storage) + ", Total Damage: " + to_string(get_total_damage()) + ", Health Point: " + to_string(get_total_damage()) + "\n";
}

Carrier::~Carrier() {
}