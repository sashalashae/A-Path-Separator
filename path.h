//Author: Sasha Morgan, sasha97

//Project Title: P0
//Purpose:  The purpose of this project was to refresh our memories of c++
#ifndef _PATH_H_
#define _PATH_H_

#include <string>
#include <iostream>

// TODO Comment

class Path {

public:
	const std::string root;
	const std::string separator;
	const std::string ps;

	// default construction of a path that assumes a Unix system with the path initialized to the root path
	Path();

	// construction of a path with given root and path separator and the path initialized to the root path
	Path(std::string root, std::string sep);

	// construction with a provided path with given root and path separator
	Path(std::string pathstring, std::string root, std::string sep);

	// a method to determine if a path is valid. A path is valid if it is nonempty 
	// and only uses ASCII characters in the printable range (32-127)
	bool isValid();

	// a method to determine if a path is absolute, that it is valid and it begins with a valid root
	bool isAbsolute();

	// a method to determine if a path is relative, that it is valid but does not begin with a valid root
	bool isRelative();

	// a method to determine if a path is a directory, that is it ends with a path separator
	bool isDir();

	// a method to return the path as a string
	std::string asString();

	// a method to return the basename of the path. The basename is the portion of the filename with any extension removed. 
	// Returns the empty string if there is no filename in the path.
	std::string basename();

	// a method to return the extension of the path. The extension is the portion of the filename after, but not including, 
	//the extension separator '.'.
	// Returns the empty string of no filename in the path or of the file does not have an extension.
	std::string extension();

	// a method to return the directory portion of the path, minus the trailing separator
	std::string dirname();

	// a method to append a filename to a path if the path is a directory. returns true on success and false on failure.
	bool appendFilename(std::string name);

	// a method to append a directory name to a path if the path is a directory. returns true on success and false on failure.
	bool appendDirname(std::string name);

	//private:

};

#endif // _PATH_H_
