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
#include "../../GenTests/inc/Modules/Test_Vectors.h"
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
    //-----------------------------------------------------------------------------
} // Test - ModernCPP

//-----------------------------------------------------------------------------
// End of file: unitTests.cpp
//-----------------------------------------------------------------------------
