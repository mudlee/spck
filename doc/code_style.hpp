// use this instead of header guards
#pragma once

// our headers
#include <spck/something/else.hpp>

// try to avoid this:
#include "yet/another.hpp"

// STL headers
#include <string>

// namespaces:
//  - lowercase
//  - keep it short (one word or abbreviation)
//  - avoid deeply nested namespaces
//  - the first level namespace is always spck for our stuff
namespace spck {

class some_base_class {};
class another_base_class {};

// no indentation after namespace

// classes:

//  - snake_case: stick to STL or Boost naming conventions (e.g. my_class,
//  my_member_function, my_field)
//  - no hungarian notation
//  - fields are snake_case
//  - '_' before pirvate data members (only use it when really needed)
class sample_class : public some_base_class, public another_base_class {
    // no indentation before visibility specifiers
public:
    // constructor
    sample_class()
        : field("inital_value"),
          field2("foobar") // use initializer list wherever possible
    {}

    ~sample_class() = default; // use = default whenever makes sense

    // disable copying when it's not intended for the class to be copyable
    sample_class(const sample_class &) = delete;
    sample_class &operator=(const sample_class &) = delete;

    std::string get_field() const { return field; }

    void set_field(const std::string &value) { field = value; }

private:
    std::string field;
    std::string field2;
}; // class sample_class

// template arguments: snake_case
template <typename type_parameter, int value_param> class some_template {
    // just as for normal classes
public:
private:
};

} // namespace spck