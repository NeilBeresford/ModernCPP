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

//-----------------------------------------------------------------------------
// External funcinality
// ----------------------------------------------------------------------------

/**
    @brief      Test function sets up vector with random integers and checks
    @ingroup    ModernCppTests
    @return     Returns true if the test passed.

 */
bool Test_Vectors::testInts_RandonNumbers() {
  // clear and setup the vector with random integers
  Test_Vectors::testVectorInts.clear();
  for (int i = 0; i < 100; ++i) {
    Test_Vectors::testVectorInts.push_back(
        rand() % 100); // Random numbers between 0 and 99
  }

  // Example test function that checks if the vector is empty
  return !Test_Vectors::testVectorInts.empty();
}

//-----------------------------------------------------------------------------
// End of file Test_Vectors.cpp
// ----------------------------------------------------------------------------
