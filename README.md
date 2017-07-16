# A Path Separator

By Sasha Morgan
Class: ECE 2574

Time spent: 5 Hourse

## Project Description


The following **required** functionality is completed:

Default construction of a path that assumes a Unix system with the path initialized to the root path

Construction of a path with given root and path separator and the path initialized to the root path

Construction with a provided path with given root and path separator

A method to determine if a path is valid. A path is valid if it is nonempty and only uses ASCII characters in the printable range (32-127)

A method to determine if a path is absolute, that it is valid and it begins with a valid root

A method to determine if a path is relative, that it is valid but does not begin with a valid root

A method to determine if a path is a directory, that is it ends with a path separator
A method to return the path as a string

A method to return the basename of the path. The basename is the portion of the filename with any extension removed. Returns the empty string if there is no filename in the path.

A method to return the extension of the path. The extension is the portion of the filename after, but not including, the extension separator '.'. Returns the empty string of no filename in the path or of the file does not have an extension.

A method to return the directory portion of the path, minus the trailing separator

A method to append a filename to a path if the path is a directory. returns true on success and false on failure.

A method to append a directory name to a path if the path is a directory. returns true on success and false on failure.


## License

Copyright [2017] [Sasha Morgan]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
