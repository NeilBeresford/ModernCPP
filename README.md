# ModernCPP Modern C++ learning

## Why this?
I am what you describe as a Classic C++ developer. My training in the language was in prior to the addition of templates (that was a blank chapter).

I have developed a project that allows my learning of modern c++ (C11 onwards) and added unit testing with generated Doxygen documentation.  

## Dependences for the project

### DOCTEST - Unit testing sub module

This testing harness adds a simple to add unit testing, building an separate application that allows custom testing via the command line. 

### Doxygen - Class and function document generator

Important that Doxygen is installed, and added to the system path.

Within the build application directory you will find a Doc<APPLICATION NAME> directory. This holds the HTML directory - please use index.html for viewing the generated documentation for that application.

GenTests includes the modules as source and this should be referenced for the library. [TODO] I will create a separate library build.

## Applications
### GenTests - Builder for the library source.

Builds and does simple test for the source.

### DocGenTests - Unit test for source

Runs through the unit tests.
