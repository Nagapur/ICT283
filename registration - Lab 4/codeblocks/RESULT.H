#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED
#include "UNIT.H"
#include "DATE.H"
#include <iostream>
#include <string.h>

using namespace std;
const unsigned resultsNameSize = 100;
const unsigned IDNameSize = 10;

class Result
{

public:
    /*Result();
    Result(const char * IDnumber, char * nam, unsigned cred, unsigned mark);
    string getunitinfo();
    int getallCredits();
    float getMarks();
    unsigned GetCredits() const;
    void setMarks( float &marks);*/
    Result();
    Result(Unit &unit, float mark, Date &date);
        /*Result(const char * IDnumber, char * nam, unsigned cred, unsigned mark);*/
        // Construct a result from a ID, name, credits and marks.

        unsigned GetCredits() const;
        //get the number of credit


        void SetCredits( unsigned cred);
        //Set the number of credits

        float GetMarks();
        //get the number of marks

        void SetMarks( float mark );
        //Set the number of Marks

        const Unit & GetUnit() const;
        void SetUnit(Unit &unit);



private:
Unit unitobj;
Date dateobj;
/*char ID[IDNameSize];
char name[resultsNameSize];*/
float marks;
int  m_credits;

friend istream & operator >>( istream & input,Result & Re );
friend ostream & operator <<( ostream & os, const  Result & Re );

};




inline unsigned Result::GetCredits() const
{
  return unitobj.GetCredits();
}

inline void Result::SetCredits( unsigned cred )
{
    m_credits = cred;
}



#endif // RESULT_H_INCLUDED
