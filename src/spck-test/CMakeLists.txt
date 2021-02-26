add_executable(spck-test main.cpp basic_test.cpp)
add_test(NAME spck-test COMMAND spck-test)
target_link_libraries(spck-test spck CONAN_PKG::catch2)
