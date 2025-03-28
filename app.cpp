#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <boost/make_shared.hpp>
#include <iostream>
#include <string>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

class Calculator {
public:
    static double calculate(double a, double b, const std::string& op) {
        if (op == "add") return a + b;
        else if (op == "subtract") return a - b;
        else if (op == "multiply") return a * b;
        else if (op == "divide") return a / b;
        throw std::invalid_argument("Unknown operation");
    }
};

void handle_request(http::request<http::string_body> req, tcp::socket& socket) {
    try {
        auto [a, b, op] = parse_query(req.target().to_string());
        double result = Calculator::calculate(a, b, op);

        http::response<http::string_body> res{ http::status::ok, req.version() };
        res.set(http::field::server, "CalculatorServer");
        res.set(http::field::content_type, "text/plain");
        res.body() = std::to_string(result);
        res.prepare_payload();
        http::write(socket, res);

    }
    catch (const std::exception& e) {
        http::response<http::string_body> res{ http::status::bad_request, req.version() };
        res.set(http::field::content_type, "text/plain");
        res.body() = e.what();
        res.prepare_payload();
        http::write(socket, res);
    }
}

std::tuple<double, double, std::string> parse_query(const std::string& query) {
    double a, b;
    std::string op;

    // Простейшая обработка строки запроса, например: /calculate?a=10&b=20&op=add
    std::string params = query.substr(query.find('?') + 1);
    std::istringstream iss(params);
    std::string token;

    while (std::getline(iss, token, '&')) {
        auto pos = token.find('=');
        if (pos != std::string::npos) {
            std::string key = token.substr(0, pos);
            std::string value = token.substr(pos + 1);
            if (key == "a") a = std::stod(value);
            else if (key == "b") b = std::stod(value);
            else if (key == "op") op = value;
        }
    }
    return { a, b, op };
}

void start_server(uint16_t port) {
    net::io_context io_context;
    tcp::acceptor acceptor(io_context, { tcp::v4(), port });

    for (;;) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        beast::flat_buffer buffer;

        http::request<http::string_body> req;
        http::read(socket, buffer, req);
        handle_request(req, socket);
    }
}

int main() {
    uint16_t port = 8080; // Порт для веб-сервера
    start_server(port);
    return 0;
}#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <boost/make_shared.hpp>
#include <iostream>
#include <string>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

class Calculator {
public:
    static double calculate(double a, double b, const std::string& op) {
        if (op == "add") return a + b;
        else if (op == "subtract") return a - b;
        else if (op == "multiply") return a * b;
        else if (op == "divide") return a / b;
        throw std::invalid_argument("Unknown operation");
    }
};

void handle_request(http::request<http::string_body> req, tcp::socket& socket) {
    try {
        auto [a, b, op] = parse_query(req.target().to_string());
        double result = Calculator::calculate(a, b, op);

        http::response<http::string_body> res{ http::status::ok, req.version() };
        res.set(http::field::server, "CalculatorServer");
        res.set(http::field::content_type, "text/plain");
        res.body() = std::to_string(result);
        res.prepare_payload();
        http::write(socket, res);

    }
    catch (const std::exception& e) {
        http::response<http::string_body> res{ http::status::bad_request, req.version() };
        res.set(http::field::content_type, "text/plain");
        res.body() = e.what();
        res.prepare_payload();
        http::write(socket, res);
    }
}

std::tuple<double, double, std::string> parse_query(const std::string& query) {
    double a, b;
    std::string op;

    // Простейшая обработка строки запроса, например: /calculate?a=10&b=20&op=add
    std::string params = query.substr(query.find('?') + 1);
    std::istringstream iss(params);
    std::string token;

    while (std::getline(iss, token, '&')) {
        auto pos = token.find('=');
        if (pos != std::string::npos) {
            std::string key = token.substr(0, pos);
            std::string value = token.substr(pos + 1);
            if (key == "a") a = std::stod(value);
            else if (key == "b") b = std::stod(value);
            else if (key == "op") op = value;
        }
    }
    return { a, b, op };
}

void start_server(uint16_t port) {
    net::io_context io_context;
    tcp::acceptor acceptor(io_context, { tcp::v4(), port });

    for (;;) {
        tcp::socket socket(io_context);
        acceptor.accept(socket);
        beast::flat_buffer buffer;

        http::request<http::string_body> req;
        http::read(socket, buffer, req);
        handle_request(req, socket);
    }
}

int main() {
    uint16_t port = 8080; // Порт для веб-сервера
    start_server(port);
    return 0;
}