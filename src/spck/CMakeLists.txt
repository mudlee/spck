file(GLOB_RECURSE SOURCE_FILES LIST_DIRECTORIES true
    spck/**.cpp
)

add_library(spck ${SOURCE_FILES})
target_link_libraries(spck PUBLIC CONAN_PKG::spdlog CONAN_PKG::glfw CONAN_PKG::glad)
target_include_directories(spck PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
