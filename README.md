# Exception
Exception is a very minimalistic exception base-class, which allows to use exceptions which contain a little bit more information and are a bit more user-friendly (supports Strings) than the standard `exception`-class.
It's intended to be used as a base class for other Exception-Types.

# Folder structure
* `src`  contains the source code (`Exception` class).

# Including and compiling Exception in a project
In order to use Exception, `<path>/Exception/src/Exception.hpp` needs to be included.
In order to compile Exception, following files need to be compiled and linked:
* `<path>/Exception/src/Exception.hpp`

# Usage
## Basic usage
1. Throw a new `Exception`-Object whilst using one of the following constructors:
```
Exception( std::string file, int line, std::string message );
Exception( std::string file, int line );
Exception( std::string message );
Exception();
```
2. Catch the exception, and (e.g.) print the Exception-Message with all information:
```
catch ( Exception & e )
{
    std::cerr << "Exception: " << e.what() << std::endl;
}
```

## Implementing new Exception-Types based on `Exception`
`Exception` can simply be used as a base class for other exceptions. In order to do this, `Exception` can be inherited. To also inherit all overloaded constructors `using Exception::Exception;` should be used in the header of a public-section.

Example for a new `Exception`-based class:
```
#include "../dependencies/Exception/src/Exception.hpp"

class SampleException : private Exception
{
public:
    using Exception::Exception; // This line is needed so we can simply inherit all overloaded constructors from the baseclass.

    std::string what() throw()
    {
        return "SampleException: " + getMsg();
    }
};

```