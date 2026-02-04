
add_library(LoggerTarget STATIC ILogger.cpp NullLogger.cpp)
target_link_libraries(LoggerTarget)
target_include_directories(LoggerTarget PUBLIC ${DEPENDENCY_INCLUDE_DIRS})
target_compile_options(LoggerTarget PRIVATE ${EMULATOR_COMPILE_OPTIONS})
target_link_libraries(EmulatorTarget PUBLIC LoggerTarget)