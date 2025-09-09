add_library(SGE_Utils STATIC
  src/utils.cpp
)

target_include_directories(SGE_Utils
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(SGE_Utils PUBLIC SimpleGE::InternalConfig)

add_library(SimpleGE::Utils ALIAS SGE_Utils)
install(TARGETS SGE_Utils
  EXPORT   SimpleGETargets
  ARCHIVE  DESTINATION lib
  LIBRARY  DESTINATION lib
  RUNTIME  DESTINATION bin
  INCLUDES DESTINATION include
)
install(DIRECTORY include/ DESTINATION include)

add_subdirectory(tests)
