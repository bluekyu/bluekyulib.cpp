# Author: Younguk Kim (bluekyu)
# Date  : 2017-05-09

cmake_minimum_required(VERSION 3.6)
project(bluekyulib)

# === configure ====================================================================================
set_property(GLOBAL PROPERTY USE_FOLDERS ON)    # Project Grouping

# version
set(PROJECT_VERSION_MAJOR "0")
set(PROJECT_VERSION_MINOR "1")
set(PROJECT_VERSION_PATCH "0")
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# === project specific packages ===
# find boost
option(Boost_USE_STATIC_LIBS    "Boost uses static libraries" OFF)
option(Boost_USE_MULTITHREADED  "Boost uses multithreaded"  ON)
option(Boost_USE_STATIC_RUNTIME "Boost uses static runtime" OFF)

set(BOOST_ROOT "" CACHE PATH "Hint for finding boost root directory")
set(BOOST_INCLUDEDIR "" CACHE PATH "Hint for finding boost include directory")
set(BOOST_LIBRARYDIR "" CACHE PATH "Hint for finding boost library directory")
find_package(Boost 1.62.0 REQUIRED filesystem)
# =================================

add_subdirectory(test)

# platform specific configure
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    # build type
    if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE "Release" CACHE STRING
            "Choose the type of build, options are: None Debug RelWithDebInfo Release."
            FORCE)
    endif()
    message("${PROJECT_NAME} Build Type: ${CMAKE_BUILD_TYPE}")
endif()

# set input files
include("${PROJECT_SOURCE_DIR}/files.cmake")
# ==================================================================================================

# === target =======================================================================================
add_library(${PROJECT_NAME} INTERFACE)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_final)

target_include_directories(${PROJECT_NAME}
    INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME}
    INTERFACE Boost::filesystem
)

# configure package
set(PACKAGE_VERSION_CONFIG_FILE "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake")
set(PACKAGE_CONFIG_FILE "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake")
set(TARGET_EXPORT_NAME "${PROJECT_NAME}-targets")
set(PACKAGE_CMAKE_INSTALL_DIR "lib/${PROJECT_NAME}/cmake")

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${PACKAGE_VERSION_CONFIG_FILE}
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)
configure_package_config_file("${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}-config.cmake.in"
    ${PACKAGE_CONFIG_FILE}
    INSTALL_DESTINATION ${PACKAGE_CMAKE_INSTALL_DIR})
export(TARGETS ${PROJECT_NAME} FILE ${PROJECT_BINARY_DIR}/${TARGET_EXPORT_NAME}.cmake)
# ==================================================================================================

# === install ======================================================================================
install(TARGETS ${PROJECT_NAME}
    EXPORT ${TARGET_EXPORT_NAME}
    RUNTIME DESTINATION "bin"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/${PROJECT_NAME}" DESTINATION "include/")

install(FILES ${PACKAGE_CONFIG_FILE} ${PACKAGE_VERSION_CONFIG_FILE} DESTINATION ${PACKAGE_CMAKE_INSTALL_DIR})
install(EXPORT ${TARGET_EXPORT_NAME} DESTINATION "lib/${PROJECT_NAME}/cmake")

install(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.md"
    DESTINATION "share/${PROJECT_NAME}/")
# ==================================================================================================
