// app.cpp
#include "crow_all.h"
//#include <asio.hpp>
#include "app_calc.h"

double calculate(double a, double b, const std::string& operation) {
    if (operation == "add") return a + b;
    else if (operation == "subtract") return a - b;
    else if (operation == "multiply") return a * b;
    else if (operation == "divide") {
        if (b != 0) return a / b;
        throw std::runtime_error("Division by zero");
    }
    throw std::invalid_argument("Unknown operation");
}

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/calculate")
        ([](const crow::request& req) {
        auto x = req.url_params.get("x");
    auto y = req.url_params.get("y");
    auto op = req.url_params.get("op");

    if (x && y && op) {
        double a = std::stod(x);
        double b = std::stod(y);
        try {
            double result = calculate(a, b, op);
            return crow::response(std::to_string(result));
        }
        catch (const std::exception& e) {
            return crow::response(400, e.what());
        }
    }
    return crow::response(400, "Invalid parameters");
            });

    app.port(8080).multithreaded().run();
    return 0;
}
