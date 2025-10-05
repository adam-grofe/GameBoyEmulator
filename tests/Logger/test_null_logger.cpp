#include "logger/NullLogger.hpp"
#include <gtest/gtest.h>

using namespace Logger;

TEST(NullLogger, DefaultLogger_StoresInfoAndBelow)
{
    // Arrange
    auto log = NullLogger();

    // Act
    log.Debug("Debug");
    log.Info("Info");
    log.Warn("Warn");
    log.Error("Error");
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Info ]  Info");
    ASSERT_EQ(result[1], "[Warn ]  Warn");
    ASSERT_EQ(result[2], "[Error]  Error");
}

TEST(NullLogger, DebugLogger_StoresAllMessages)
{
    // Arrange
    auto log = NullLogger(NullLogger::LogLevel::Debug);

    // Act
    log.Debug("Debug");
    log.Info("Info");
    log.Warn("Warn");
    log.Error("Error");
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Debug]  Debug");
    ASSERT_EQ(result[1], "[Info ]  Info");
    ASSERT_EQ(result[2], "[Warn ]  Warn");
    ASSERT_EQ(result[3], "[Error]  Error");
}

TEST(NullLogger, InfoLogger_StoresAllMessages)
{
    // Arrange
    auto log = NullLogger(NullLogger::LogLevel::Info);

    // Act
    log.Debug("Debug");
    log.Info("Info");
    log.Warn("Warn");
    log.Error("Error");
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Info ]  Info");
    ASSERT_EQ(result[1], "[Warn ]  Warn");
    ASSERT_EQ(result[2], "[Error]  Error");
}

TEST(NullLogger, WarnLogger_StoresWarnOrBelowMessages)
{
    // Arrange
    auto log = NullLogger(NullLogger::LogLevel::Warn);

    // Act
    log.Debug("Debug");
    log.Info("Info");
    log.Warn("Warn");
    log.Error("Error");
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Warn ]  Warn");
    ASSERT_EQ(result[1], "[Error]  Error");
}

TEST(NullLogger, ErrorLogger_StoresErrorMessages)
{
    // Arrange
    auto log = NullLogger(NullLogger::LogLevel::Error);

    // Act
    log.Debug("Debug");
    log.Info("Info");
    log.Warn("Warn");
    log.Error("Error");
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Error]  Error");
}

TEST(NullLogger, WarnLogger2Messages_StoresTwoMessages)
{
    // Arrange
    auto log = NullLogger(NullLogger::LogLevel::Debug, 2);

    // Act
    log.Debug("Debug");
    log.Info("Info");
    log.Warn("Warn");
    log.Error("Error");
    auto result = log.Messages();

    // Assert
    ASSERT_EQ(result[0], "[Warn ]  Warn");
    ASSERT_EQ(result[1], "[Error]  Error");
}