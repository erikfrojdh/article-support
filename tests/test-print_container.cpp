#include "catch2/catch.hpp"

#include <array>
#include <cstdint>
#include <deque>
#include <list>
#include <sstream>
#include <vector>

#ifndef _MAIN
#define _MAIN
#endif

#include "src/print_container.cpp"

TEST_CASE("empty vector") {
    std::vector<int> vec;
    std::ostringstream os;
    os << vec;
    REQUIRE(os.str() == "[]");
}

TEST_CASE("vector with one value") {
    std::vector<int> vec{5};
    std::ostringstream os;
    os << vec;
    REQUIRE(os.str() == "[5]");
}

TEST_CASE("array with five values") {
    std::array<uint64_t, 5> arr{1, 2, 3, 4, 5};
    std::ostringstream os;
    os << arr;
    REQUIRE(os.str() == "[1, 2, 3, 4, 5]");
}

TEST_CASE("list with three values") {
    std::list<double> lst{8.3, 5.4};
    std::ostringstream os;
    os << lst;
    REQUIRE(os.str() == "[8.3, 5.4]");
}

TEST_CASE("deque  with four values") {
    std::deque<int> deq{5, 8, 123, 9};
    std::ostringstream os;
    os << deq;
    REQUIRE(os.str() == "[5, 8, 123, 9]");
}