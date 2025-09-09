add_library(SGE_InternalConfig INTERFACE)

target_include_directories(SGE_InternalConfig
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

set(CONFIG_MODE "" CACHE STRING "Mode for which to generate config.h")
set_property(CACHE CONFIG_MODE PROPERTY STRINGS "" debug release test)

if(CONFIG_MODE)
  string(TOLOWER "${CONFIG_MODE}" config_lower)
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG_MODE}/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
    @ONLY
  )
  target_include_directories(SGE_InternalConfig INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  )
endif()

add_library(SimpleGE::InternalConfig ALIAS SGE_InternalConfig)

install(TARGETS SGE_InternalConfig
  EXPORT   SimpleGETargets
  INCLUDES DESTINATION include
)
