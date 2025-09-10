add_library(SGE_ThreadManagement STATIC
  src/thread_pool.cpp
)

target_include_directories(SGE_ThreadManagement
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(SGE_ThreadManagement PUBLIC SimpleGE::InternalConfig)

add_library(SimpleGE::ThreadManagement ALIAS SGE_ThreadManagement)
install(TARGETS SGE_ThreadManagement
  EXPORT   SimpleGETargets
  ARCHIVE  DESTINATION lib
  LIBRARY  DESTINATION lib
  RUNTIME  DESTINATION bin
  INCLUDES DESTINATION include
)
install(DIRECTORY include/ DESTINATION include)

add_subdirectory(tests)
