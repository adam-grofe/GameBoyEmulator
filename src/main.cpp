
#include <iostream>

#include "Logger/ILogger.hpp"

int main(int argc, char* argv[])
{
    auto logger = Logger::logger_factory(Logger::NullLogger);
}
