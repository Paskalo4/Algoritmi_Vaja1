#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/sorting.hpp"

TEST_CASE("Test Counting Sort", "[sorting]") {
    std::vector<int> input = {5, 2, 8, 1, 9};
    std::vector<int> expected = {1, 2, 5, 8, 9};
    Counting_Sort(input);
    REQUIRE(input == expected);
}

TEST_CASE("Test Roman Sort", "[sorting]") {
    std::vector<int> input = {5, 2, 8, 1, 9};
    std::vector<int> expected = {1, 2, 5, 8, 9};
    Roman_Sort(input);
    REQUIRE(input == expected);
}

TEST_CASE("Test Reading Numbers", "[io]") {
    std::vector<int> vec;
    const char* filename = "../tests/input.txt";  // Popravljena pot
    REQUIRE(Branje_Stevil(vec, filename) == true);
    REQUIRE(vec == std::vector<int>({4, 2, 7, 1}));
}
