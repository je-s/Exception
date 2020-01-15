/*
    Copyright 2019 Jan-Eric Schober

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

// Standard Libraries
#include <string>
#include <iostream>

class Exception
{
private:
    // Variables
    std::string file;
    int line;
    std::string message;

    // Methods
    void init( std::string file, int line, std::string message );
    
public:
    // Constructors
    Exception( std::string file, int line, std::string message );
    Exception( std::string file, int line );
    Exception( std::string message );
    Exception();

    // Methods
    void setFile( std::string file );
    std::string getFile();
    void setLine( int line );
    int getLine();
    std::string getFileInfo();
    void setMessage( std::string message );
    std::string getMessage();
    virtual std::string what() throw();
};

#endif // EXCEPTION_HPP