cmake_minimum_required(VERSION 3.24)

project(GameBoyEmulator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include(GNUInstallDirs)
include(InstallRequiredSystemLibraries) # MSVC runtime DLLs

find_package(GTest REQUIRED)

add_executable(EmulatorTarget ${CMAKE_SOURCE_DIR}/src/main.cpp)

# Install the app and copy its non-system runtime DLLs next to the exe
install(TARGETS EmulatorTarget
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include(CPack)

add_subdirectory(src)

enable_testing()
find_package(GTest REQUIRED)
add_subdirectory(tests)
