//Author: Sasha Morgan, sasha97

//Project Title: P0
//Purpose:  The purpose of this project was to refresh our memories of c++


#include <cxxtest/TestSuite.h>

#include "path.h"

// TODO Implement tests of your path class here

class PathTests : public CxxTest::TestSuite {
public:
	
  void test_example(void) {
    Path p("C:\\", "\\");

    TS_ASSERT_EQUALS(p.root, "C:\\");
    TS_ASSERT_EQUALS(p.separator, "\\");
  }
  
  //This set of tests will test the isvalid boolean method
  //Checks to see if the path is empty, if the path is empty it will return false
  void test_isvalid(){
	  Path p("", "C:\\", "'\'");
	  TS_ASSERT_EQUALS(p.isValid(), false);
  }
  //Check to see if the path has ascii values within 32 and 127
  void test_isvalidnonempty(){
  
	  Path p("C:\\users\\sasha\\documents\\h.txt", "C:\\", "'\'");
	  TS_ASSERT_EQUALS(p.isValid(), true);	  
  }
  

  
  // Checks the isAbsolute method

  void test_isAbsolute(){
	  Path p("C:\\", "D:\\", "'\'");
	  TS_ASSERT_EQUALS(p.isAbsolute(), false);
  }
  //Check to see if the path has ascii values within 32 and 127
  void test_isAbsolutenonempty(){

	  Path p("C:\\User\sasha", "C:\\", "'\'");
	  TS_ASSERT_EQUALS(p.isAbsolute(), true);
  }

  // Checks the isRelative method
  void test_isRel(){

	  Path p("C:\\", "\\");
	  TS_ASSERT_EQUALS(p.isRelative(), false);
  }
  void test_isRelative(){

	  Path p("", "");
	  TS_ASSERT_EQUALS(p.isRelative(), false);
  }

  // a method to determine if a path is a directory, that is it ends with a path separator
  //Tests the isDir method
  void test_isDir(){
	  Path p("C://users/sasha/documents//", "C://", "//");
	  TS_ASSERT_EQUALS(p.isDir(), true);
  }

  void test_isDir2(){
	  Path p("C:usersksashak", "C://", "/");
	  TS_ASSERT_EQUALS(p.isDir(), false);
  }

  // a method to return the path as a string
  void test_asString(){
	  Path p("C://User//sasha//", "C://", "/");
	  TS_ASSERT_EQUALS(p.asString(), "C://User//sasha//");
  }

  // a method to return the basename of the path. The basename is the portion of the filename with any extension removed. 
  // Returns the empty string if there is no filename in the path.
  void test_basename13(){
	  Path p("C://User/sasha/documents/rachel.doc", "C://", "/");
	  TS_ASSERT_EQUALS(p.basename(), "rachel");
  }

  //checks for the empty string
  void test_nobasename1()
  {
	  Path p("", "C://");
	  TS_ASSERT_EQUALS(p.basename(), "");
  }

  //Tests the extension method
  //Tests a path with an extension
  void test_extension1(){
	  Path p("C://User/sasha/documents/rachel.doc", "C://", "'/'");
	  TS_ASSERT_EQUALS(p.extension(), "doc");
  }
  //Tests a path without an extension
  void test_extension2(){
	  Path p("C://User/sasha/documents/rachel/", "C://", "'/'");
	  TS_ASSERT_EQUALS(p.extension(), "");
  }

  //Tests the dirname() method
  void test_dirname(){
	  Path p("C://User/sasha/documents/rachel/", "C://", "'/'");
	  TS_ASSERT_EQUALS(p.dirname(), "C://User/sasha/documents/rachel");
  }

 
};
