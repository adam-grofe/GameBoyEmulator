include(GoogleTest)

add_executable(EmulatorTests
    Logger/test_null_logger.cpp
)

target_link_libraries(EmulatorTests 
    PRIVATE 
        GTest::GTest 
        GTest::Main
        LoggerTarget
)
target_include_directories( EmulatorTests PUBLIC ${CMAKE_SOURCE_DIR}/include)

gtest_discover_tests(EmulatorTests)