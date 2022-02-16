#include "RESULT.H"
#include "UNIT.H"

Result::Result()
{

    this->marks = 0;
    /*ID[0] = '\0';
    name[0] = '\0';*/

}

Result::Result(Unit &unit, float mark)
{

    unit = unitobj;
    mark=marks;

}

/*Result::Result(const char * IDNumber, char * nam, unsigned cred, unsigned mark)
{
    strncpy(ID, IDNumber, IDNameSize);
    strncpy(name,nam,resultsNameSize);
    credits = cred;
    marks = mark;
}*/

float Result::GetMarks()
{
    return marks;
}

void Result::SetMarks(float mark)
{
    mark=marks;
}

void Result::GetUnit(Unit &unit)
{
    unit = unitobj;
}

void Result::SetUnit(Unit &unit)
{
    unitobj = unit;
}

/*string Result::getunitinfo()
{
    return unitobj.getUnitID();
}

int Result::getallCredits()
{
    return credits;
}*/

istream & operator >>( istream & input, Result & Re)
{
  input >>Re.unitobj>> Re.marks;

  //input >> Re.ID >> Re.name >> Re.credits >> Re.marks;
  return input;
}

ostream & operator <<( ostream & os, const Result & Re )
{


    os << Re.unitobj <<"  Marks: " << Re.marks << '\n';

    /* os  << "Unit ID:  " << Re.ID << '\n'
        << "Unit Name: " << Re.name << '\n'
        << "Credits: " << Re.credits << '\n'
        << "Marks: " << Re.marks << '\n';*/
  return os;
}
