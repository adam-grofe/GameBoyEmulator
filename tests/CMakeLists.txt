include(GoogleTest)

add_executable(EmulatorTests
    Rom/test_rom.cpp
    Logger/test_null_logger.cpp
)

target_link_libraries(EmulatorTests 
    PRIVATE 
        GTest::gtest 
        GTest::gtest_main 
        GTest::gmock 
        GTest::gmock_main
        LoggerTarget
        RomTarget
)
target_include_directories( EmulatorTests PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_test(AllTestsInMain main)