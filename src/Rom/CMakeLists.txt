
add_library(RomTarget STATIC Rom.cpp)
target_include_directories(RomTarget PUBLIC ${DEPENDENCY_INCLUDE_DIRS})
target_compile_options(RomTarget PRIVATE ${EMULATOR_COMPILE_OPTIONS})
target_link_libraries(EmulatorTarget PUBLIC RomTarget)