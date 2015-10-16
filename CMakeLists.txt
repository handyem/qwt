set(LIBRARY_NAME "Qwt")

file(GLOB_RECURSE SOURCES_LIST src/*.cpp)
file(GLOB_RECURSE HEADERS_LIST src/*.h)

file(GLOB_RECURSE REMOVE_LIST
  src/Debug/*.*
  src/GeneratedFiles/*.*
  src/Release/*.*)

list(REMOVE_ITEM SOURCES_LIST ${REMOVE_LIST})
list(REMOVE_ITEM HEADERS_LIST ${REMOVE_LIST})

add_library(${LIBRARY_NAME} SHARED
    ${SOURCES_LIST}
    ${HEADERS_LIST})

# Generate export header file in ${CMAKE_CURRENT_BINARY_DIR}
include(GenerateExportHeader)
generate_export_header(${LIBRARY_NAME}
  EXPORT_MACRO_NAME "LIBRARY_EXPORT"
  EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}Export.h"
)

# Add the folder where export header is generated to public includes.
target_include_directories(${LIBRARY_NAME}
    PUBLIC "${CMAKE_CURRENT_BINARY_DIR}"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(${LIBRARY_NAME}
    Qt5::Core
    Qt5::Widgets
    Qt5::Concurrent
    Qt5::Gui
    Qt5::OpenGL
    Qt5::Svg
    Qt5::PrintSupport)

install (TARGETS ${LIBRARY_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION bin)

target_compile_definitions(${LIBRARY_NAME}
  PRIVATE QWT_MAKEDLL
  PUBLIC QWT_DLL)

