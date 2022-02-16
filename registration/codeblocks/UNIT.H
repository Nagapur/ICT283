#ifndef UNIT_H_INCLUDED
#define UNIT_H_INCLUDED
#include <iostream>
#include <string.h>


using namespace std;

const unsigned UnitNameSize = 20;
const unsigned UnitIDSize = 10;

class Unit {
public:
  Unit();
  Unit( const char * nam, char * unitID, unsigned cred );
  // Construct a course from a name, section letter,
  // and number of credits.


  unsigned GetCredits() const;
  // Get the number of credits.

  void SetCredits( unsigned xID );
  // Set the number of credits.

  void GetUnitName(char * Name);
  void SetUnitName( char * Name );
    string GetUnitID();
    void SetUnitID( string xID );
  // These operators have been made friends. They have
  // privileged access to class internals.
  // Very useful for debugging the class, but not very good for class design.
  // We will keep using it for now but you will have a chance in a later lab
  // to redesign this class.
  friend ostream & operator <<( ostream & os, const Unit & C );
  friend istream & operator >>( istream & input, Unit & C );

private:
  char unitName[UnitNameSize];  // course name, C style string. not a C++ string object
  char unitID[UnitIDSize];   // section (letter) can be enrolment mode
  int  credits;   // number of credits

};


inline unsigned Unit::GetCredits() const
{
  return credits;
}

inline void Unit::SetCredits( unsigned cred )
{
  credits = cred;
}





#endif // UNIT_H_INCLUDED
