# Author: Younguk Kim (bluekyu)
# Date  : 2017-05-09

cmake_minimum_required(VERSION 3.6)
project(bluekyulib_test)

# === configure ====================================================================================
set_property(GLOBAL PROPERTY USE_FOLDERS ON)    # Project Grouping

# === project specific packages ===
# =================================

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
# ==================================================================================================

# === sources ======================================================================================
# set input files
set(sources_files
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
)
# ==================================================================================================

# === target =======================================================================================
add_executable(${PROJECT_NAME} ${sources_files})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_auto_type)
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /MP /wd4251)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
endif()

target_include_directories(${PROJECT_NAME}
    PRIVATE "${PROJECT_BINARY_DIR}"
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE $<$<NOT:$<BOOL:${Boost_USE_STATIC_LIBS}>>:Boost::dynamic_linking>
    bluekyulib
)
# ==================================================================================================

# === install ======================================================================================
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION "bin"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib")
# ==================================================================================================
