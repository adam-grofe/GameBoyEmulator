
add_library(LoggerTarget STATIC ILogger.cpp NullLogger.cpp)
target_link_libraries(LoggerTarget)
target_include_directories(LoggerTarget PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(EmulatorTarget PUBLIC LoggerTarget)