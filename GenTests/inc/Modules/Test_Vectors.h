/**
    @file       Test_Vectors.h
    @defgroup   ModernCppTests Modern C++ Tests
    @brief      Main file for running tests for Vectors.
    @copyright  Copyright (c) 2025, Neil Beresford
*/

//-----------------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------------

#include <vector>

//-----------------------------------------------------------------------------
// Class
// ----------------------------------------------------------------------------

class Test_Vectors
{
  private:
    std::vector<int> testVectorInts;

  public:
    // Functions
    bool    testInts_RandomNumbers( int32_t size = 100 );
    bool    testInts_Delete( int32_t index );
    int32_t testInts_GetTotalCount( void );
    int32_t testInts_GetValue( int32_t index );
    bool    testInts_SetValue( int32_t index, int32_t value );
    bool    testInts_SortHighToLow( void );
    bool    testInts_SortLowToHigh( void );
    bool    testInts_DeleteAll( void );
    bool    testInts_DeleteRange( int32_t start, int32_t end );
    bool    testInts_DeleteValueRange( int32_t start, int32_t end );
};

//-----------------------------------------------------------------------------
// End of file Test_Vectors.h
// ----------------------------------------------------------------------------
