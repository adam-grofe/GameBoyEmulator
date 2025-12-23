
#include "Logger/ILogger.hpp"
#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

namespace GBEmulator
{

class Rom
{
  public:
    using DataType = std::byte;
    using DataArray = std::vector<DataType>;

    Rom(std::string_view romPath, std::shared_ptr<Logger::ILogger> loggerPtr);
    std::string_view Path() const
    {
        return _path;
    };

    const DataType& At(size_t index) const;

  private:
    std::string _path;
    std::shared_ptr<Logger::ILogger> _logger;
    DataArray _data;
};
} // namespace GBEmulator