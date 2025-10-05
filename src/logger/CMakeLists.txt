
add_library(LoggerTarget STATIC ILogger.cpp QtLogger.cpp NullLogger.cpp)
target_link_libraries(LoggerTarget PRIVATE Qt6::Quick)
target_include_directories(LoggerTarget PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(EmulatorTarget PUBLIC LoggerTarget)