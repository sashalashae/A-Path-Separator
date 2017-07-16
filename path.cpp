//Author: Sasha Morgan, sasha97

//Project Title: P0
//Purpose:  The purpose of this project was to refresh our memories of c++

//using namespace std;
#include "path.h"
#include <string>
#include <iostream>
using namespace std;



string ps;
//The default constructor
Path::Path() :root("/"), separator("/"), ps(root){

}

// construction of a path with given root and path separator and the path initialized to the root path
//Path::Path(std::string root, std::string sep)
Path::Path(std::string root, std::string sep) :root(root), separator(sep), ps(root)
{

}


// construction with a provided path with given root and path separator
Path::Path(std::string pathstring, std::string root, std::string sep) :root(root), separator(sep), ps(pathstring)
{

}

/*
This method determines if the path is valid.  It checkes to see if the path is nonempty and have printable
range characters.
The default boolean value for the method is false.
*/
bool Path::isValid(){

	bool input = true; //default setting
	int count = ps.length(); //the size of the pathstring
	if (ps.empty())
	{ //Checks the size of the string to determine if the path is empty
		input = false;
	}
	//while (a < count-1) //loop to run through the size of the filepath
	for (int i = 0; i < count; i++)
	{
		//if ((int)char(ps[a]) < 32 || (int)char(ps[a]) > 127) //checks if the ascii value
		if ((int)(ps[i]) < 32 || (int)(ps[i])>127)
		{
			input = false; //marks the value as valid
		}
		cout << count;
	}
	return input;
	
}



// a method to determine if a path is absolute, that it is valid and it begins with a valid root
// The default boolean value for the function is false.
bool Path::isAbsolute()
{
	bool check = true; //boolean declaration
	int p = root.length(); //size of the root

	if (isValid() == true) //determines if the path is valid
	{
		if (ps.substr(0, p) != root){ //checks for the root
			check = false;
		}
		
	}
	return check;
}

// a method to determine if a path is relative, that it is valid but does not begin with a valid root
bool Path::isRelative()
{
	bool checker = false;
	if (isAbsolute() == false) //determines is the path is valid and doesn't begin with a valid root
	{
		checker = true;
	}	
	return checker;
}

// a method to determine if a path is a directory, that is it ends with a path separator
bool Path::isDir()
{
	bool pathsepcheck = true; // the default setting for the boolean cariable
	int t = ps.size(); //finds the size of the path
	int k = separator.length(); //finds the size of the separator
	string str = ps.substr(t - k);  //determines the substring
	if (str != separator) //condition where the substring
	{
		pathsepcheck = false;
	}         
	return pathsepcheck;
}
// a method to return the path as a string
std::string Path::asString()
{
	return ps; //returns the string
}

// a method to return the basename of the path. The basename is the portion of the filename with any extension removed. 
// Returns the empty string if there is no filename in the path.
std::string Path::basename()
{
	int size = ps.length(); //returns the size of the string
	string bn = ""; // creates an empty string
	if (size == 0){ //checks for an empty string
		bn = "";
	}
	else{
		int endsep = ps.find_last_of(separator); //finds the last occurance of the separator
		int pstart = ps.find_first_of("."); //finds the last occurance of the period
		int size = (pstart - endsep); // determines the size of the substring
		bn = ps.substr(endsep + 1, size - 1); //creates the basename
	}

	return bn;

}

// a method to return the extension of the path. The extension is the portion of the filename after, but not including, the extension separator '.'.
// Returns the empty string of no filename in the path or of the file does not have an extension.
std::string Path::extension()
{
	string k = "";
	if (string::npos == ps.find_last_of(".")) //finds the last instance of a dot
	{
		return k;
	}
	else{
		int last = ps.find_last_of("."); //finds the last instance of a dot
		int esp = ps.length(); //finds the size of the string
		k = ps.substr(last + 1, esp - last); //creates a substring that will be the extension
	}
	return k;
}

// a method to return the directory portion of the path, minus the trailing separator
std::string Path::dirname()
{
	int g = ps.length();
	string dr = "";
	int total = ps.find_last_of(separator);
	if (g != 0)
	{
		dr = ps.substr(0, total);
	}
	return dr;

}

// a method to append a filename to a path if the path is a directory. returns true on success and false on failure.
bool Path::appendFilename(std::string name)
{
	bool me = false;

	if (isDir() == true) //determines is the path is a directory
	{
		string ps = ps + name; //adds the path to the directory
		me = true;
	}
	return me;
}

// a method to append a directory name to a path if the path is a directory. returns true on success and false on failure.
bool Path::appendDirname(std::string name)
{
	bool me = false;
	if (isDir() == true) //determines if the path is a directory
	{
		string ps = ps + name + separator; //adds the path to the directory
		me = true;
	}

	return me;
}
