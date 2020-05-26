#define CATCH_CONFIG_RUNNER
#include "vec2.hpp"
#include <catch.hpp>



TEST_CASE("test_vec_init", "[vec2]")
{
  Vec2 a{};
  REQUIRE(a.x == Approx(0.0f));
  REQUIRE(a.y == Approx(0.0f));
  Vec2 b {5.1f, -9.3f};
  REQUIRE(b.x == Approx(5.1f));
  REQUIRE(b.y == Approx(-9.3f));

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
