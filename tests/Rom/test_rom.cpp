
#include "Logger/NullLogger.hpp"
#include <Rom/Rom.hpp>
#include <gtest/gtest.h>
#include <memory>

namespace RomTests
{

class RomTests : public testing::Test
{
  protected:
    std::string romPath()
    {
        return "./tests/Rom/red.gb";
    }
    GBEmulator::Rom getRom()
    {
        std::string path = romPath();
        auto logger = std::make_shared<Logger::NullLoggerImpl>();

        return GBEmulator::Rom{path, logger};
    }
};

TEST_F(RomTests, LoadRomFromString_PathIsTheSame)
{
    // Arrange
    auto rom = getRom();

    // Act
    auto result = rom.Path();

    // Assert
    EXPECT_EQ(rom.Path(), romPath());
}

TEST_F(RomTests, LoadRomFromString_ReadsDataFromValidFile)
{

    // Arrange
    auto rom = getRom();

    // Act
    auto value = rom.At(size_t{0});

    // Assert
    EXPECT_EQ(value, GBEmulator::Rom::DataType{0});
}

} // namespace RomTests
