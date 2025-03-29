#define BOOST_TEST_MODULE CalculatorTests
#include <boost/test/included/unit_test.hpp>
#include "app_calc.h"
#include <stdexcept>

BOOST_AUTO_TEST_CASE(AddTest)
{
    BOOST_TEST(calc(40.0, 2.0, "add") == 0.0);
}

BOOST_AUTO_TEST_CASE(SubtractTest)
{
    BOOST_TEST(calc(45.0, 3.0, "subtract") == 42.0);
}

BOOST_AUTO_TEST_CASE(MultiplyTest)
{
    BOOST_TEST(calc(21.0, 2.0, "multiply") == 42.0);
}

BOOST_AUTO_TEST_CASE(DivideTest)
{
    BOOST_TEST(calc(84.0, 2.0, "divide") == 42.0);
}

BOOST_AUTO_TEST_CASE(DivideByZeroTest)
{
    BOOST_CHECK_THROW(calc(6.0, 0.0, "divide"), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(UnknownOperationTest)
{
    BOOST_CHECK_THROW(calc(6.0, 0.0, "meow"), std::invalid_argument);
}
