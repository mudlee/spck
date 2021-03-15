#include <catch2/catch.hpp>
#include <iostream>
#include <spck/utils/noncopyable.hpp>

namespace fixture {
class donotcopyme : public spck::noncopyable {};

class copyme {};
}

TEST_CASE("classes extended from noncopyable cannot be copied", "[noncopyable]" ) {
    REQUIRE(std::is_copy_assignable_v<fixture::copyme>);
    REQUIRE(std::is_copy_constructible_v<fixture::copyme>);
    REQUIRE(std::is_copy_constructible<fixture::copyme>::value);

    REQUIRE_FALSE(std::is_copy_assignable_v<fixture::donotcopyme>);
    REQUIRE_FALSE(std::is_copy_constructible_v<fixture::donotcopyme>);
    REQUIRE_FALSE(std::is_copy_constructible<fixture::donotcopyme>::value);
}