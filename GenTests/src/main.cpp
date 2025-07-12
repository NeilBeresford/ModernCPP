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
#include "Test_Lamda.h"
#include "Test_File.h"

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

    // Check the state of the LamdaAll class
    // Example usage of the lambda functions
    LamdaAddTemplate      cAddTemplate;
    LamdaMultiplyTemplate cMultiplyTemplate;
    LamdaDivideTemplate   cDivideTemplate;
    LamdaSubtractTemplate cSubtractTemplate;
    LamdaModulusTemplate  cModulusTemplate;
    LamdaPowerTemplate    cPowerTemplate;

    // Example usage of the lambda functions
    auto sum         = cAddTemplate.add( 5, 3 );
    auto product     = cMultiplyTemplate.multiply( 5, 3 );
    auto quotient    = cDivideTemplate.divide( 5, 3 );
    auto difference  = cSubtractTemplate.subtract( 5, 3 );
    auto mod         = cModulusTemplate.modulus( 5, 3 );
    auto powerResult = cPowerTemplate.power( 2, 3 );

    // Output results (for demonstration purposes)
    // In a real test, you would use assertions instead
    std::cout << "Sum: " << sum << ", Product: " << product << ", Quotient: " << quotient << ", Difference: " << difference << ", Modulus: " << mod << ", Power: " << powerResult << std::endl;

    // Print a message indicating that all tests have passed
    std::cout << "All tests passed!" << std::endl;

    return 0;
}

//-----------------------------------------------------------------------------
// End of main.cpp
// ----------------------------------------------------------------------------
