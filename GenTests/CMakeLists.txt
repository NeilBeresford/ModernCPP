# ----------------------------------------------------------------------------------
# Cmake - instructions for general testing of modern C++
# Generates both the executable and the library used for testing
# Note - will do documentation later
# ----------------------------------------------------------------------------------

# project names
project(ModernCppTests VERSION 1.0.0 LANGUAGES CXX)
project(ModernCppTestsLib)

# Add files
file(GLOB_RECURSE SOURCES "src/*.cpp" "inc/*.h" "src/modules/*.cpp" "inc/modules/*.h")
file(GLOB_RECURSE LIBSOURCES "inc/*.h" "src/modules/*.cpp" "inc/modules/*.h")

# Add the executable
add_executable(ModernCppTests ${SOURCES})
add_library(ModernCppTestsLib ${LIBSOURCES})

# targets for the executable
target_include_directories(ModernCppTests PRIVATE "inc" "inc/Modules" )

# Doxgen for documentation generation
find_package(Doxygen REQUIRED)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    add_custom_target(DocModernCppTests ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
else()
    message(WARNING "Doxygen not found, documentation will not be generated.")
endif()

# End of the CMakeLists.txt file
