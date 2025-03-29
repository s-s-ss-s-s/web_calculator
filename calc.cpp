#include "app_calc.h"
//#include "crow_all.h"
//#include <asio.hpp>
double calc(double a, double b, const std::string& operation) {
    if (operation == "add") return a + b;
    else if (operation == "subtract") return a - b;
    else if (operation == "multiply") return a * b;
    else if (operation == "divide") {
        if (b != 0) return a / b;
        throw std::runtime_error("Division by zero");
    }
    throw std::invalid_argument("Unknown operation");
}
