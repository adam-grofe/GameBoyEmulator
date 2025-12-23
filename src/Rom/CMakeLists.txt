
add_library(RomTarget STATIC Rom.cpp)
target_include_directories(RomTarget PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(EmulatorTarget PUBLIC RomTarget)