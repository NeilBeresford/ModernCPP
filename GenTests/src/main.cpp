/**
    @file       main.cpp
    @defgroup   ModernCppTests Modern C++ Tests
    @brief      Main file for running tests using the doctest framework.
    @copyright   Copyright (c) 2025, Neil Beresford
*/

//-----------------------------------------------------------------------------
// Libraries
// ----------------------------------------------------------------------------

#include <iostream>
#include "Test_Vectors.h"

//-----------------------------------------------------------------------------
//  External Functionality
// ----------------------------------------------------------------------------

/** @brief      Main function that runs the tests.
                This function serves as the entry point for the test suite.
                It initializes the test environment and runs all defined tests.
    @ingroup    ModernCppTests
    @param[in]  argc  The number of command line arguments.
    @param[in]  argv  The command line arguments.
    @return     Returns 0 on success, or a non-zero value on failure.
*/
int main( int argc, char** argv )
{
    // Print a message indicating that the tests are starting
    std::cout << "Running tests..." << std::endl;

    // Initialize the test environment for simple functionality check.
    // The main checking is done in TestGenTest using the doctest framework.
    Test_Vectors testVectors;

    // Run the test for random integers in vectors
    if ( !testVectors.testInts_RandomNumbers() )
    {
        std::cerr << "Test failed: testInts_RandomNumbers" << std::endl;
        return 1; // Return non-zero value to indicate failure
    }

    std::cout << "All tests passed!" << std::endl;

    return 0;
}

//-----------------------------------------------------------------------------
// End of main.cpp
// ----------------------------------------------------------------------------
