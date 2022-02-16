// REGIST.CPP - Registration class implementation.

#include "regist.h"


Registration::Registration()
{
  count = 0;
}

unsigned Registration::GetCredits() const
{
  unsigned sum = 0;
  for(unsigned i = 0; i < count; i++)
    sum += units[i].GetCredits();

  return sum;
}

istream & operator >>( istream & input, Registration & R )
{
  input >> R.studentId >> R.semester >> R.count;

  for(unsigned i = 0; i < R.count; i++)
    input >> R.units[i];  // track down which >> operator is called. Hint: look at what is being input.

  return input;
}

ostream & operator <<( ostream & os, const Registration & R )
{
  os << "Student ID: " << R.studentId << '\n'
     << "Semester:   " << R.semester << '\n';

  for(unsigned i = 0; i < R.count; i++)
    os << R.units[i] << '\n';

  return os;
}
