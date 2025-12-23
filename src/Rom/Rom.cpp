#include "Rom/Rom.hpp"

using namespace GBEmulator;

Rom::Rom(std::string_view romPath, std::shared_ptr<Logger::ILogger> loggerPtr)
{
    _path = romPath;
    _logger = loggerPtr;
    _data = std::vector<std::byte>(0x200000, std::byte{0x00});
}

const Rom::DataType& Rom::At(size_t index) const
{
    return _data.at(index);
}
