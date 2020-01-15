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

#include "Exception.hpp"

Exception::Exception( std::string file, int line, std::string message )
{
    init( file, line, message );
}

Exception::Exception( std::string file, int line )
{
    init( file, line, "" );
}

Exception::Exception( std::string message )
{
    init( "", -1, message );
}

Exception::Exception()
{
    init( "", -1, "" );
}

void Exception::init( std::string file, int line, std::string message )
{
    setFile( file );
    setLine( line );
    setMessage( message );
}

void Exception::setMessage( std::string message )
{
    this->message = message;
}

std::string Exception::getMessage()
{
    return message;
}

void Exception::setFile( std::string file )
{
    this->file = file;
}

std::string Exception::getFile()
{
    return file;
}

void Exception::setLine( int line )
{
    this->line = line;
}

int Exception::getLine()
{
    return line;
}

std::string Exception::getFileInfo()
{
    std::string file = getFile();
    int line = getLine();
    std::string fileInfo = "";

    if ( !file.empty() )
    {
        fileInfo += "File: " + getFile();
    }

    if ( line < 0 )
    {
        fileInfo += ", (No line given)";
    }
    else
    {
        fileInfo += ", Line: " + std::to_string( getLine() );   
    }

    return fileInfo;
}

std::string Exception::what() throw()
{
    std::string fileInfo = getFileInfo();
    
    if ( fileInfo.empty() )
    {
        return "Message: " + getMessage();
    }
    else
    {
        return "" + getFileInfo() + ", Message: " + getMessage();
    }
}
