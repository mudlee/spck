add_executable(spck-test main.cpp basic_test.cpp)
target_link_libraries(spck-test spck CONAN_PKG::catch2)