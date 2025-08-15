cmake_minimum_required(VERSION 3.24)

project(GameBoyEmulator)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

enable_testing()

include(GNUInstallDirs)
include(InstallRequiredSystemLibraries) # MSVC runtime DLLs

find_package(GTest REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Quick Qml)

qt_standard_project_setup(REQUIRES 6.5)
qt_add_executable(EmulatorTarget src/main.cpp)
qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)
qt_add_qml_module(EmulatorTarget 
    URI app
    VERSION 1.0
    RESOURCE_PREFIX "/qt/qml"
    QML_FILES 
        src/main.qml
)

set_target_properties(EmulatorTarget PROPERTIES
    WIN32_EXECUTABLE FALSE
)

target_link_libraries(EmulatorTarget PUBLIC Qt6::Quick)

qt_import_qml_plugins(EmulatorTarget)

# Where to search for dependent DLLs when copying them
set(_runtime_dep_dirs "")
if(DEFINED VCPKG_INSTALLED_DIR AND DEFINED VCPKG_TARGET_TRIPLET)
    list(APPEND _runtime_dep_dirs
        "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/bin"
        "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/lib")
endif()

# Install the app and copy its non-system runtime DLLs next to the exe
install(TARGETS EmulatorTarget
    BUNDLE  DESTINATION AppBundleDir
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install the MSVC runtime (if available)
if(CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS)
    install(PROGRAMS ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS}
        DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

qt_generate_deploy_qml_app_script(
    TARGET  EmulatorTarget
    OUTPUT_SCRIPT deploy_script
)
install(SCRIPT ${deploy_script})

include(CPack)

#add_subdirectory(src)
#add_subdirectory(tests)
