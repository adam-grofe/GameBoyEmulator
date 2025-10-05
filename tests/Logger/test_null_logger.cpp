#include "Logger/NullLogger.hpp"
#include <gtest/gtest.h>

using namespace Logger;

class NullLoggerTests : public testing::Test
{
  protected:
    void runMessages(NullLogger& log)
    {
        log.Debug("Debug");
        log.Info("Info");
        log.Warn("Warn");
        log.Error("Error");
    }
};

TEST_F(NullLoggerTests, DefaultLogger_StoresInfoAndBelow)
{
    // Arrange
    auto log = NullLogger();

    // Act
    runMessages(log);
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Info ]  Info");
    ASSERT_EQ(result[1], "[Warn ]  Warn");
    ASSERT_EQ(result[2], "[Error]  Error");
}

TEST_F(NullLoggerTests, DebugLogger_StoresAllMessages)
{
    // Arrange
    auto log = NullLogger(NullLogger::LogLevel::Debug);

    // Act
    runMessages(log);
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Debug]  Debug");
    ASSERT_EQ(result[1], "[Info ]  Info");
    ASSERT_EQ(result[2], "[Warn ]  Warn");
    ASSERT_EQ(result[3], "[Error]  Error");
}

TEST_F(NullLoggerTests, InfoLogger_StoresAllMessages)
{
    // Arrange
    auto log = NullLogger(NullLogger::LogLevel::Info);

    // Act
    runMessages(log);
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Info ]  Info");
    ASSERT_EQ(result[1], "[Warn ]  Warn");
    ASSERT_EQ(result[2], "[Error]  Error");
}

TEST_F(NullLoggerTests, WarnLogger_StoresWarnOrBelowMessages)
{
    // Arrange
    auto log = NullLogger(NullLogger::LogLevel::Warn);

    // Act
    runMessages(log);
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Warn ]  Warn");
    ASSERT_EQ(result[1], "[Error]  Error");
}

TEST_F(NullLoggerTests, ErrorLogger_StoresErrorMessages)
{
    // Arrange
    auto log = NullLogger(NullLogger::LogLevel::Error);

    // Act
    runMessages(log);
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Error]  Error");
}

TEST_F(NullLoggerTests, WarnLogger2Messages_StoresTwoMessages)
{
    // Arrange
    auto log = NullLogger(NullLogger::LogLevel::Debug, 2);

    // Act
    runMessages(log);
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Warn ]  Warn");
    ASSERT_EQ(result[1], "[Error]  Error");
}