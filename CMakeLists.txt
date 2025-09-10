cmake_minimum_required(VERSION 3.23)
project(SimpleGE VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

include(FetchContent)

FetchContent_Declare(
  googletest
  DOWNLOAD_EXTRACT_TIMESTAMP OFF
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(config)

set(MODULE_DIRS
  modules/utils
  modules/thread_management
)
list(SORT MODULE_DIRS)

foreach(dir IN LISTS MODULE_DIRS)
  add_subdirectory(${dir})
endforeach()

enable_testing()

install(EXPORT SimpleGETargets
  FILE SimpleGETargets.cmake
  NAMESPACE SimpleGE::
  DESTINATION lib/cmake/SimpleGE
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/SimpleGEConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/SimpleGEConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/SimpleGEConfig.cmake"
  INSTALL_DESTINATION lib/cmake/SimpleGE
)

install(
  FILES
    "${CMAKE_CURRENT_BINARY_DIR}/SimpleGEConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/SimpleGEConfigVersion.cmake"
  DESTINATION lib/cmake/SimpleGE
)
