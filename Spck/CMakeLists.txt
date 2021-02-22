file(GLOB_RECURSE SOURCE_FILES LIST_DIRECTORIES true
    src/Spck/**.cpp
)

add_library(Spck ${SOURCE_FILES})
target_link_libraries(Spck PUBLIC CONAN_PKG::spdlog CONAN_PKG::glfw CONAN_PKG::glad)
target_include_directories(Spck PUBLIC src)
