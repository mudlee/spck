#include <catch2/catch.hpp>

// FIXME: eventually remove this, when we have real tests, this is 
// just for presentation purposes
TEST_CASE("A trivial test", "[basic]" ) {
    constexpr bool always_true = true;
    REQUIRE(always_true == true);
    // Uncomment it to make the test fail
    // REQUIRE(always_true == false);
}