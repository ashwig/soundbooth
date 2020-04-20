#include "../include/catch2/catch.hpp"
#include "./include/test_helpers.hh"
#include <sstream>
#include <string>

SCENARIO("The obscure function is successful", "[functions]") {
  GIVEN("The desired output's input string") {
    WHEN("We attempt to obscure a string") {
      std::string inputData = "Jane Smith 222-33-4444 S12345 password";
      std::string targetString = "Jane Smith xxx-xx-xxxx S12345 xxxxxxxx";

      THEN("The information should be obscured") {
        REQUIRE(obscureData(inputData) == targetString);
      }
    }

    WHEN("We attempt to obscure a string") {
      std::string inputData = "Ashton Hellwig 111-11-1111 S02075840 password";
      std::string targetString =
          "Ashton Hellwig xxx-xx-xxxx S02075840 xxxxxxxx";

      THEN("The information should be obscured") {
        REQUIRE(obscureData(inputData) == targetString);
      }
    }
  }
}
