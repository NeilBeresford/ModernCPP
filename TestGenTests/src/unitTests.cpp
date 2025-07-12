/**
    @file       unitTests.cpp
    @defgroup   ModernCppTests Modern C++ Tests
    @brief      Main file for running unittests for GenTests.
    @copyright  Copyright (c) 2025, Neil Beresford
*/

//-----------------------------------------------------------------------------
// Libraries
// ----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

// doctest unit testing framework setup
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <algorithm> // For std::sort
#include "../../GenTests/inc/Modules/Test_Vectors.h"
#include "../../GenTests/inc/Modules/Test_Lamda.h"
#include "../../GenTests/inc/Modules/Test_File.h"
#include "../../doctest/doctest/doctest.h"

//-----------------------------------------------------------------------------
// Namespace access
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Unit Tests
//-----------------------------------------------------------------------------

TEST_SUITE( "Test - ModernCPP" )
{
    //-----------------------------------------------------------------------------
    TEST_CASE( "Testing Vectors" )
    //-----------------------------------------------------------------------------
    {
        SUBCASE( "Testing RandomInts()" )
        {
            Test_Vectors testVectors;

            CHECK( testVectors.testInts_RandomNumbers() != 0 );
            CHECK( testVectors.testInts_GetTotalCount() == 100 );
            CHECK( testVectors.testInts_DeleteAll() == true );
            CHECK( testVectors.testInts_GetTotalCount() == 0 );
            CHECK( testVectors.testInts_RandomNumbers( 1000 ) == true );
            CHECK( testVectors.testInts_GetTotalCount() == 1000 );
            CHECK( testVectors.testInts_GetValue( 0 ) >= 0 );
            CHECK( testVectors.testInts_GetValue( 999 ) >= 0 );
            CHECK( testVectors.testInts_GetValue( 1000 ) == -1 ); // Out of bounds check
            CHECK( testVectors.testInts_SetValue( 0, 42 ) == true );
            CHECK( testVectors.testInts_GetValue( 0 ) == 42 );
            CHECK( testVectors.testInts_SetValue( 1000, 42 ) == false ); // Out of bounds check
            CHECK( testVectors.testInts_Delete( 0 ) == true );
            CHECK( testVectors.testInts_GetTotalCount() == 999 );
            CHECK( testVectors.testInts_Delete( 999 - 1 ) == true );
            CHECK( testVectors.testInts_GetTotalCount() == 998 );
            CHECK( testVectors.testInts_Delete( 1000 ) == false ); // Out of bounds check
            CHECK( testVectors.testInts_DeleteAll() == true );
            CHECK( testVectors.testInts_GetTotalCount() == 0 );
            CHECK( testVectors.testInts_RandomNumbers( 1000 ) == true );
            CHECK( testVectors.testInts_GetTotalCount() == 1000 );
            CHECK( testVectors.testInts_SortHighToLow() == true );
            CHECK( testVectors.testInts_GetValue( 0 ) >= testVectors.testInts_GetValue( 1 ) ); // Check first two values
            CHECK( testVectors.testInts_SortLowToHigh() == true );
            CHECK( testVectors.testInts_GetValue( 0 ) <= testVectors.testInts_GetValue( 1 ) ); // Check first two values
            CHECK( testVectors.testInts_DeleteRange( 0, 100 - 1 ) == true );                   // Delete range from 0 to 99
            CHECK( testVectors.testInts_GetTotalCount() == 900 );                              // Check total count after
            CHECK( testVectors.testInts_DeleteRange( 800 - 1, 900 - 1 ) == true );             // Delete range from 799 to 899
            CHECK( testVectors.testInts_GetTotalCount() == 799 );                              // Check total count after
            CHECK( testVectors.testInts_DeleteRange( 0, 799 - 1 ) == true );                   // Delete all remaining values
            CHECK( testVectors.testInts_GetTotalCount() == 0 );                                // Check total count after
            CHECK( testVectors.testInts_DeleteRange( 0, 100 ) == false );                      // Out of bounds check
        }
    }
    //-----------------------------------------------------------------------------
    TEST_CASE( "Testing Lamda Functions" )
    {
        SUBCASE( "Testing Lamda Functions" )
        {
            // Example usage of the lambda functions
            LamdaAddTemplate      cAddTemplate;
            LamdaMultiplyTemplate cMultiplyTemplate;
            LamdaDivideTemplate   cDivideTemplate;
            LamdaSubtractTemplate cSubtractTemplate;

            LamdaModulusTemplate  cModulusTemplate;
            LamdaPowerTemplate    cPowerTemplate;

            // Basic maths using ints
            auto sum         = cAddTemplate.add( 5, 3 );
            auto product     = cMultiplyTemplate.multiply( 5, 3 );
            auto quotient    = cDivideTemplate.divide( 5, 3 );
            auto difference  = cSubtractTemplate.subtract( 5, 3 );
            auto mod         = cModulusTemplate.modulus( 5, 3 );
            auto powerResult = cPowerTemplate.power( 2, 3 );

            CHECK( sum == 8 );
            CHECK( product == 15 );
            CHECK( quotient == 1 ); // Allowing for floating point precision
            CHECK( difference == 2 );
            CHECK( mod == 2 );
            CHECK( powerResult == 8 );

            // Basic maths using doubles
            auto sumDouble         = cAddTemplate.add( 5.5, 3.5 );
            auto productDouble     = cMultiplyTemplate.multiply( 5.5, 3.5 );
            auto quotientDouble    = cDivideTemplate.divide( 5.5, 3.5 );
            auto differenceDouble  = cSubtractTemplate.subtract( 5.5, 3.5 );
            auto powerResultDouble = cPowerTemplate.power( 2.0, 3.0 );
            CHECK( sumDouble == 9.0 );
            CHECK( productDouble == 19.25 );
            CHECK( quotientDouble == doctest::Approx( 1.57143 ).epsilon( 0.00001 ) ); // Allowing for floating point precision
            CHECK( differenceDouble == 2.0 );
            CHECK( powerResultDouble == 8.0 );

        } // End of Lamda Functions test
    } // End of Lamda Functions test
    //-----------------------------------------------------------------------------
    TEST_CASE( "Testing File Operations" )
    {
        SUBCASE( "Testing text file operations" )
        {
            TextFile textFile;

            CHECK( textFile.open( "test.txt" ) == true );
            CHECK( textFile.write( "Hello, World!" ) == true );
            std::string content;
            CHECK( textFile.read( content ) == true );
            CHECK( content == "Hello, World!" );
            textFile.close();
        } // End of Text File Operations test
        SUBCASE( "Testing Binary File Operations" )
        {
            BinaryFile binaryFile;

            CHECK( binaryFile.open( "test.bin" ) == true );
            CHECK( binaryFile.write( "Hello, World!", 13 ) == true );
            binaryFile.close();
            CHECK( binaryFile.open( "test.bin" ) == true );
            char buffer[ 14 ] = { 0 }; // Buffer to read 13 bytes +
            CHECK( binaryFile.read( buffer, 13 ) == true );
            CHECK( std::string( buffer ) == "Hello, World!" );
            binaryFile.close();
        } // End of Binary File Operations test
    } // End of File Operations test
    //-----------------------------------------------------------------------------
    //-----------------------------------------------------------------------------
} // Test - ModernCPP

//-----------------------------------------------------------------------------
// End of file: unitTests.cpp
//-----------------------------------------------------------------------------
