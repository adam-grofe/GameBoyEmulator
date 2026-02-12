include(GoogleTest)

add_executable(EmulatorTests
    Rom/test_rom.cpp
    Logger/test_null_logger.cpp
)

target_link_libraries(EmulatorTests 
    PUBLIC 
        GTest::gtest 
        GTest::gtest_main 
        LoggerTarget
        RomTarget
)
target_include_directories( EmulatorTests PUBLIC ${CMAKE_SOURCE_DIR}/include)

gtest_discover_tests(EmulatorTests)
