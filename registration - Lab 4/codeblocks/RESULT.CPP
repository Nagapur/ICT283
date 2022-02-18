#include "RESULT.H"
#include "UNIT.H"
#include "DATE.H"
#include <sstream>
Result::Result()
{

    this->marks = 0;
    /*ID[0] = '\0';
    name[0] = '\0';*/

}

Result::Result(Unit &unit, float mark, Date &date)
{

    unitobj= unit;
    marks=mark;
    dateobj=date;

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
    //mark=marks;
    return marks;
}

void Result::SetMarks(float mark)
{
    marks=mark;
}

/*void Result::GetUnit(Unit &unit)
{
    unit = unitobj;
}*/

/*void*/ const Unit &Result::GetUnit() const
{
    return unitobj;
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
  //string inputMarks;

  input >>Re.unitobj>> Re.marks;


  /*getline(input,inputMarks, ',');

  stringstream container(inputMarks);
  int x;
  container >> x;
  Re.SetMarks(x);*/

  return input;
}

ostream & operator <<( ostream & os, const Result & Re )
{



    os << Re.unitobj <<"  Marks: " <<  Re.marks<< '\n'
        <<" Date: "<< Re.dateobj<<'\n';

    /* os  << "Unit ID:  " << Re.ID << '\n'
        << "Unit Name: " << Re.name << '\n'
        << "Credits: " << Re.credits << '\n'
        << "Marks: " << Re.marks << '\n';*/
  return os;
}
