# Target library
add_library(${SRC_NAME} SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/${SRC_NAME}.c
    ${CMAKE_CURRENT_SOURCE_DIR}/${SRC_NAME}.h
)

# Setup the target properties
set_target_properties(${SRC_NAME} PROPERTIES
    LIBRARY_OUTPUT_NAME ${SRC_NAME}
    VERSION ${PROJECT_VERSION}
)

# Setup the headers dependencies
include_directories(
    ${GSTLIBS_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Set GStreamer libraries as dynamic dependencies
target_link_libraries(${SRC_NAME}
    PUBLIC "${GSTLIBS_LIBRARIES}"
    PRIVATE
)

# Set the compile options
target_compile_options (${SRC_NAME} PUBLIC "$<$<CONFIG:DEBUG>:${C_WARNINGS}>")
target_compile_features (${SRC_NAME} PRIVATE ${CMAKE_C_FLAGS})

include(GNUInstallDirs)

# Create the pkgconfig file from a template
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${SRC_NAME}.pc.in ${SRC_NAME}.pc @ONLY)

# Install libraries and headers
install(TARGETS ${SRC_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Install pkgconfig file
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${SRC_NAME}.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig
)
