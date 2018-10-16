/*----------------------------------------------------------------------------------
Practice 2 Class Persona
persona.cc
This is the file where are the implementation of some methods (the ones that are
not inline) from the class 'Persona'
----------------------------------------------------------------------------------*/

#include <string>
#include "persona.h"
using std::string;

Persona::Persona (const string &dni, const string &name, const string &surnames,
const int age, const string &address, const string &locality,
const string &province, const string &country) {
  setDNI(dni);
  setNombre(name);
  setApellidos(surnames);
  setEdad(age);
  setDireccion(address);
  setLocalidad(locality);
  setProvincia(province);
  setPais(country);
}

string Persona::getApellidosyNombre() const {
  string full_name;
  full_name = surnames_ + ", " + name_;
  return full_name;
}

bool Persona::setEdad(int age) {
  if (age < 0 || age > 140) return false;
  else {
    age_ = age;
    return true;
  }
}

bool Persona::mayor() const {
  if (age_ >= 18) return true;
  else return false;
}