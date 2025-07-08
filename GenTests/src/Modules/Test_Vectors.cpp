/**
    @file       Test_Vectors.cpp
    @defgroup   ModernCppTests Modern C++ Tests
    @brief      Main file for running tests for Vectors.
    @copyright  Copyright (c) 2025, Neil Beresford
*/

//-----------------------------------------------------------------------------
// Libraries
// ----------------------------------------------------------------------------

#include "../../inc/Modules/Test_Vectors.h" //!< Header file for Test_Vectors class
#include <stdlib.h>                         //!< Included for rand()
#include <algorithm>                        //!< Included for std::sort

//-----------------------------------------------------------------------------
// External funcinality
// ----------------------------------------------------------------------------

/**
    @brief      Test function sets up vector with random integers and checks
    @ingroup    ModernCppTests
    @param[in]  size  The number of random integers to generate.
    @return     Returns true if the test passed.
*/
bool Test_Vectors::testInts_RandomNumbers( int32_t size )
{
    // clear and setup the vector with random integers
    Test_Vectors::testVectorInts.clear();
    for ( int32_t i = 0; i < size; ++i )
    {
        Test_Vectors::testVectorInts.push_back( rand() % 100 ); // Random numbers between 0 and 99
    }

    // Example test function that checks if the vector is empty
    return !Test_Vectors::testVectorInts.empty();
}

/**
    @brief      Deletes an integer from the vector at the specified index.
    @ingroup    ModernCppTests
    @param[in]  index  The index of the integer to delete.
    @return     Returns true if the deletion was successful, false if the index is out of bounds.
*/
bool Test_Vectors::testInts_Delete( int32_t index )
{
    if ( index < 0 || index >= static_cast<int32_t>( Test_Vectors::testVectorInts.size() ) )
    {
        return false; // Index out of bounds
    }

    Test_Vectors::testVectorInts.erase( Test_Vectors::testVectorInts.begin() + index );
    return true; // Deletion successful
}

/**
    @brief      Gets the total count of integers in the vector.
    @ingroup    ModernCppTests
    @return     Returns the total count of integers in the vector.
*/
int32_t Test_Vectors::testInts_GetTotalCount( void )
{
    return static_cast<int32_t>( Test_Vectors::testVectorInts.size() );
}

/**
    @brief      Gets the value of an integer at the specified index.
    @ingroup    ModernCppTests
    @param[in]  index  The index of the integer to retrieve.
    @return     Returns the value at the specified index, or -1 if the index is out of bounds.
*/
int32_t Test_Vectors::testInts_GetValue( int32_t index )
{
    if ( index < 0 || index >= static_cast<int32_t>( Test_Vectors::testVectorInts.size() ) )
    {
        return -1; // Return -1 if index is out of bounds
    }

    return Test_Vectors::testVectorInts[ index ]; // Return the value at the specified index
}

/**
    @brief      Sets the value of an integer at the specified index.
    @ingroup    ModernCppTests
    @param[in]  index  The index of the integer to set.
    @param[in]  value  The value to set at the specified index.
    @return     Returns true if the value was set successfully, false if the index is out of bounds.
*/
bool Test_Vectors::testInts_SetValue( int32_t index, int32_t value )
{
    if ( index < 0 || index >= static_cast<int32_t>( Test_Vectors::testVectorInts.size() ) )
    {
        return false; // Index out of bounds
    }

    Test_Vectors::testVectorInts[ index ] = value; // Set the value at the specified index
    return true;                                   // Value set successfully
}

/**
    @brief      Sorts the integers in the vector from high to low.
    @ingroup    ModernCppTests
    @return     Returns true if the sorting was successful.
*/
bool Test_Vectors::testInts_SortHighToLow( void )
{
    std::sort( Test_Vectors::testVectorInts.begin(), Test_Vectors::testVectorInts.end(), std::greater<int>() );
    return true; // Sorting successful
}

/**
    @brief      Sorts the integers in the vector from low to high.
    @ingroup    ModernCppTests
    @return     Returns true if the sorting was successful.
*/
bool Test_Vectors::testInts_SortLowToHigh( void )
{
    std::sort( Test_Vectors::testVectorInts.begin(), Test_Vectors::testVectorInts.end() );
    return true; // Sorting successful
}

/**
    @brief      Deletes a range of integers from the vector.
    @ingroup    ModernCppTests
    @param[in]  start  The starting index of the range to delete.
    @param[in]  end    The ending index of the range to delete.
    @return     Returns true if the deletion was successful, false if the range is invalid.
*/
bool Test_Vectors::testInts_DeleteRange( int32_t start, int32_t end )
{
    if ( start < 0 || end >= static_cast<int32_t>( Test_Vectors::testVectorInts.size() ) || start > end )
    {
        return false; // Invalid range
    }

    Test_Vectors::testVectorInts.erase( Test_Vectors::testVectorInts.begin() + start, Test_Vectors::testVectorInts.begin() + end + 1 );
    return true; // Deletion successful
}

/**
    @brief      Deletes all integers from the vector.
    @ingroup    ModernCppTests
    @return     Returns true if the deletion was successful.
*/
bool Test_Vectors::testInts_DeleteAll( void )
{
    Test_Vectors::testVectorInts.clear(); // Clear the vector
    return true;                          // Deletion successful
}

/**
    @brief      Deletes all integers within a specified value range from the vector.
    @ingroup    ModernCppTests
    @param[in]  start  The starting value of the range to delete.
    @param[in]  end    The ending value of the range to delete.
    @return     Returns true if the deletion was successful, false if the range is invalid.
*/
bool Test_Vectors::testInts_DeleteValueRange( int32_t start, int32_t end )
{
    if ( start < 0 || end >= static_cast<int32_t>( Test_Vectors::testVectorInts.size() ) || start > end )
    {
        return false; // Invalid range
    }

    Test_Vectors::testVectorInts.erase(
        std::remove_if( Test_Vectors::testVectorInts.begin(), Test_Vectors::testVectorInts.end(), [ start, end ]( int value ) { return value >= start && value <= end; } ),
        Test_Vectors::testVectorInts.end() );

    return true; // Deletion successful
}

//-----------------------------------------------------------------------------
// End of file Test_Vectors.cpp
// ----------------------------------------------------------------------------
