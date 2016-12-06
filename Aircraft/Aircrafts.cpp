#include "Aircrafts.h"
#include <sstream>

using namespace std;

Aircrafts::Aircrafts() {
  m_ammo_level = 0;
}

unsigned int Aircrafts::fight() {
  m_all_damage = m_base_damage * m_ammo_level;
  m_ammo_level = 0;
  return m_all_damage;
}

void Aircrafts::refill(unsigned int &ammo) {
  int needed_ammo = m_max_ammo - m_ammo_level;
  if (needed_ammo <= ammo) {
    ammo -= needed_ammo;
    m_ammo_level = m_max_ammo;
  }
  else {
    m_ammo_level = ammo;
    ammo = 0;
  }
}

std::string Aircrafts::get_type() {
  return aircraft_type;
}

int Aircrafts::get_damage() {
  return m_all_damage;
}

int Aircrafts::get_ammo_level() {
  return m_ammo_level;
}

int Aircrafts::get_max_ammmo() {
  return m_ammo_level;
}
std::string Aircrafts::to_string(int integer) {
  stringstream ss;
  ss << integer;
  return ss.str();
}

std::string Aircrafts::get_status() {
  return "Type: " + aircraft_type + ", Ammo: " + to_string(m_ammo_level) + ", Base Damage: " + to_string(m_base_damage) + ", All Damage: " + to_string(m_all_damage) + "\n";
}

Aircrafts::~Aircrafts() {

}