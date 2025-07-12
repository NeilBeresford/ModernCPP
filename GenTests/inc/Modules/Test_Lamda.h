/**
    @file       Test_Lambda.h
    @brief      This file contains unit tests for various lambda expressions used in the project.
    @defgroup   ModernCppTests Modern C++ Tests
    @copyright  Copyright (c) 2025, Neil Beresford
*/

//-----------------------------------------------------------------------------
// Libraries
// ----------------------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------------------
// Classes
// ----------------------------------------------------------------------------

/**
    @brief      Template class for calculating addition of two numbers using lambda expressions.
    @ingroup    ModernCppTests
*/
class LamdaAddTemplate
{
  public:
    LamdaAddTemplate() = default;

    /**
     * @brief      Adds two numbers.
     * @param[in]  a The first number.
     * @param[in]  b The second number.
     * @return     Returns the sum of a and b.
     */
    template <typename T> auto add( T a, T b )
    {
        return a + b;
    }
};

/**
    @brief      Template class for calculating multiplication of two numbers using lambda expressions.
    @ingroup    ModernCppTests
*/
class LamdaMultiplyTemplate
{
  public:
    LamdaMultiplyTemplate() = default;

    /**
     * @brief      Multiplies two numbers.
     * @param[in]  a The first number.
     * @param[in]  b The second number.
     * @return     Returns the product of a and b.
     */
    template <typename T> auto multiply( T a, T b )
    {
        return a * b;
    }
};

/**
    @brief      Template class for calculating division of two numbers using lambda expressions.
    @ingroup    ModernCppTests
*/
class LamdaDivideTemplate
{
  public:
    LamdaDivideTemplate() = default;

    /**
     * @brief      Divides two numbers.
     * @param[in]  a The numerator.
     * @param[in]  b The denominator.
     * @return     Returns the result of a divided by b, or 0 if b is zero.
     */
    template <typename T> auto divide( T a, T b )
    {
        return b != 0 ? a / b : 0;
    } // Avoid division by zero
};

/**
    @brief      Template class for calculating subtraction of two numbers using lambda expressions.
    @ingroup    ModernCppTests
*/
class LamdaSubtractTemplate
{
  public:
    LamdaSubtractTemplate() = default;

    /**
     * @brief      Subtracts two numbers.
     * @param[in]  a The first number.
     * @param[in]  b The second number.
     * @return     Returns the difference of a and b.
     */
    template <typename T> auto subtract( T a, T b )
    {
        return a - b;
    }
};

/**
    @brief      Template class for calculating modulus of two numbers using lambda expressions.
    @ingroup    ModernCppTests
*/
class LamdaModulusTemplate
{
  public:
    LamdaModulusTemplate() = default;

    /**
     * @brief      Calculates the modulus of two numbers.
     * @param[in]  a The first number.
     * @param[in]  b The second number.
     * @return     Returns the modulus of a and b, or 0 if b is zero.
     */
    template <typename T> auto modulus( T a, T b )
    {
        return b != 0 ? a % b : 0;
    } // Avoid division by zero
};

/**
    @brief      Template class for calculating power of a number using lambda expressions.
    @ingroup    ModernCppTests
*/
class LamdaPowerTemplate
{
  public:
    LamdaPowerTemplate() = default;

    /**
     * @brief      Calculates the power of a base raised to an exponent.
     * @param[in]  base     The base number.
     * @param[in]  exponent The exponent to raise the base to.
     * @return     Returns the result of base raised to the exponent.
     */
    template <typename T> auto power( T base, int exponent )
    {
        T result = 1;
        for ( int i = 0; i < exponent; ++i )
        {
            result *= base;
        }
        return result;
    }
};

//-----------------------------------------------------------------------------
// End of file Test_Lambda.h
//-----------------------------------------------------------------------------
