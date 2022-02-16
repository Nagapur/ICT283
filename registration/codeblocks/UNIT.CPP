#include "UNIT.H"
#include <iostream>
#include <string.h>
#include <cstring>

Unit::Unit()
{
  unitName[0] = '\0'; // it is a char * string, not a C++ string object.
}

Unit::Unit( const char * nam, char * xID,
                unsigned cred )
{
  strncpy( unitName, nam, UnitNameSize );
  strncpy( unitID, xID, UnitIDSize );
  credits = cred;
}


void Unit::GetUnitName(char * Name)
{
  Name=unitName;
}

void Unit::SetUnitName(char * Name)
{
  std::strncpy(this->unitName, Name, UnitNameSize);
}

string Unit::GetUnitID()
{
    return unitID;
}

void Unit::SetUnitID(string xID)
{
    xID=unitID;
}

istream & operator >>( istream & input, Unit & C )
{
  input >> C.unitName >> C.unitID >> C.credits;
  return input;
}

ostream & operator <<( ostream & os, const Unit & C )
{
  os << "  Unit:  " << C.unitName << '\n'
     << "  Unit ID: " << C.unitID << '\n'
     << "  Credits: " << C.credits << '\n';
  return os;
}




