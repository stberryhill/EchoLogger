cmake_minimum_required(VERSION 3.12.0)
project(EchoLogger VERSION 0.3.0 LANGUAGES C)

# Set default visibility to hidden (only functions bearing ECHO_LOGGER_API will be exported)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

option(BUILD_SHARED_LIBS "Build shared library" ON)
include(GenerateExportHeader)
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# Set intall RPATH info for library.
if (NOT APPLE)
  set(CMAKE_INSTALL_RPATH $ORIGIN)
endif()

add_library(EchoLogger
  src/EchoLogger.c
  src/Internal.h
  )

# Allows to use EchoLogger as a subdirectory (and in examples)
add_library(EchoLogger::EchoLogger ALIAS EchoLogger)

generate_export_header(EchoLogger
  EXPORT_MACRO_NAME ECHO_LOGGER_API
  EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/include/EchoLoggerAPIMacro.h
  )

target_include_directories(EchoLogger
  PUBLIC
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    $<BUILD_INTERFACE:${CMAKE_BINARY_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
  PRIVATE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>
  )

# Make shared lib version follow project version.
set_target_properties(EchoLogger PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
  )

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/EchoLoggerConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/EchoLoggerConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/EchoLogger
  PATH_VARS
    CMAKE_INSTALL_LIBDIR
  )

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/EchoLoggerConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
  )

install(TARGETS EchoLogger
  EXPORT EchoLoggerTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    COMPONENT EchoLogger_Development
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    COMPONENT EchoLogger_Runtime
    NAMELINK_COMPONENT EchoLogger_Development
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT EchoLogger_Runtime
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

set(publicHeaders
  include/EchoLogger.h
  include/EchoLoggerAPIMacro.h
  )

install(FILES ${publicHeaders} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
  
install(EXPORT EchoLoggerTargets
  FILE EchoLoggerTargets.cmake
  COMPONENT EchoLogger_Development
  NAMESPACE EchoLogger::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/EchoLogger
  )

install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/EchoLoggerConfig.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/EchoLoggerConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/EchoLogger
  )
