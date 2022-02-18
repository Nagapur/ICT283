// MAIN.CPP - Case Study, Student Registration

// Count the number of courses taken by the student, calculate total credits
// author KRI
//

#include <iostream>
#include <fstream>
#include "unit.h"  // Course class declaration
#include "regist.h"  // Registration class declaration

using namespace std;

// Main program:
// Open an input file stream, read a Registration object,
// including its list of courses. Redisplay all information,
// and calculate the total credits taken. Write the results
// to a file stream.

int main()
{
  ifstream infile( "inputanddate.txt" );
  if( !infile ) return -1;

  Registration R;
  infile >> R;

  ofstream ofile( "rdate.txt" );

// Use a debugger and track down the calls made "behind the scene"
  ofile << R
    << "Number of courses = " << R.GetCount() << '\n'
    << "Total credits     = " << R.GetCredits() << '\n';

  // Declare and initialize a Course, and modify
  // its credits.

  Unit aUnit( "principal", "gtg", 2 );
  aUnit.SetCredits( 5 );
  cout << aUnit << endl; // the operator << for Course is called

  return 0;
}

