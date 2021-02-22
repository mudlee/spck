file(GLOB SOURCE_FILES
    src/Spck/*.cpp
)

add_library(Spck ${SOURCE_FILES})
target_link_libraries(Spck PUBLIC CONAN_PKG::spdlog)
target_include_directories(Spck PUBLIC src)
