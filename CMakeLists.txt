cmake_minimum_required(VERSION 3.24)

project(GameBoyEmulator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
  set(EMULATOR_COMPILE_OPTIONS /W4 /analyze)
else()
  set(EMULATOR_COMPILE_OPTIONS -Wall -Wextra -Wpedantic)
endif()

enable_testing()

include(GNUInstallDirs)
include(InstallRequiredSystemLibraries) # MSVC runtime DLLs

find_package(GTest REQUIRED)
find_path(SAFEINT_INCLUDE_DIRS "SafeInt.hpp")

set(DEPENDENCY_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/include ${SAFEINT_INCLUDE_DIRS})

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
