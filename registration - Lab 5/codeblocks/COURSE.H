// COURSE.H - Course class definition
// author KRI
// modified smr

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string.h>  // C string library

using namespace std;

const unsigned CourseNameSize = 10;

class Course {
public:
  Course();
  Course( const char * nam, char sect, unsigned cred );
  // Construct a course from a name, section letter,
  // and number of credits.

  unsigned GetCredits() const;
  // Get the number of credits.

  void SetCredits( unsigned cred );
  // Set the number of credits.

  // These operators have been made friends. They have
  // privileged access to class internals.
  // Very useful for debugging the class, but not very good for class design.
  // We will keep using it for now but you will have a chance in a later lab
  // to redesign this class.
  friend ostream & operator <<( ostream & os, const Course & C );
  friend istream & operator >>( istream & input, Course & C );

private:
  char name[CourseNameSize];  // course name, C style string. not a C++ string object
  char section;   // section (letter) can be enrolment mode
  int  credits;   // number of credits
};


inline unsigned Course::GetCredits() const
{
  return credits;
}

inline void Course::SetCredits( unsigned cred )
{
  credits = cred;
}

#endif
