
add_library(LoggerTarget STATIC ILogger.cpp QtLogger.cpp)
target_link_libraries(LoggerTarget PRIVATE Qt6::Quick)
target_include_directories(LoggerTarget PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(EmulatorTarget PUBLIC LoggerTarget)