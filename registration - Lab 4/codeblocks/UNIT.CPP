#include "UNIT.H"
#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>

Unit::Unit()
{
  unitName[0] = '\0'; // it is a char * string, not a C++ string object.
}

Unit::Unit( string nam, string xID,
                unsigned cred )
{
  nam=unitName;
  xID = unitID;
  credits = cred;
}


void Unit::GetUnitName(string & Name) const
{
  Name=unitName;
}

void Unit::SetUnitName(const string & Name)
{
  unitName=Name;
}

void Unit::GetUnitID(string &xID) const
{
    xID=unitID;
}

void Unit::SetUnitID(const string &xID)
{
    unitID=xID;
}

istream & operator >>( istream & input, Unit & C )
{
  //input >> C.unitName >> C.unitID >> C.credits;

  string SaveInput;
  getline(input,SaveInput, ',');
  C.SetUnitName(SaveInput);

  getline(input,SaveInput, ',');
  C.SetUnitID(SaveInput);

  getline(input,SaveInput, ',');
  //C.SetCredits(stoi(SaveInput));
  stringstream container (SaveInput);
  int x;
  container >> x;
  C.SetCredits(x);

  return input;
}

ostream & operator <<( ostream & os, const Unit & C )
{
    string unitName;
    string unitID;
    C.GetUnitName(unitName);
    C.GetUnitID(unitID);

  os << "  Unit:  " << unitName << '\n'
     << "  Unit ID: " << unitID << '\n'
     << "  Credits: " << C.GetCredits()<< '\n';
  return os;
}




