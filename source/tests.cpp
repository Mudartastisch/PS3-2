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

  //test vectors
  Vec2 vec_zero_zero{};
	Vec2 vec_zero_one{ 0.0,1.0 };
	Vec2 vec_one_zero{ 1.0,0.0 };
	Vec2 vec_one_one{ 1.0,1.0 };
	Vec2 vec_nThree_five{ -3.0,5.0 };
	Vec2 vec_nFour_nFour{ -4.0,-4.0 };
	Vec2 vec_five_two{ 5.0,2.0 };
	Vec2 vec_seven_one{ 7.0,1.0 };



TEST_CASE("test_vec_add", "[vec2]"){
  Vec2 vec_prove_one_zero{};
	vec_prove_one_zero.operator+=(vec_one_zero);
	REQUIRE(vec_prove_one_zero.x == 1.0f); //Test 0+1=1
	REQUIRE(vec_prove_one_zero.y == 0.0f); //Test 0+0=0

	Vec2 vec_prove_two_one{1.0f,1.0f};
	vec_prove_two_one.operator+=(vec_one_zero);
	REQUIRE(vec_prove_two_one.x == 2.0f); //Test 1+1=2
	REQUIRE(vec_prove_two_one.y == 1.0f); //Test 1+0=1

	Vec2 vec_prove_two_two{};
	vec_prove_two_two.operator+=(vec_one_one);
	vec_prove_two_two.operator+=(vec_one_one);
	REQUIRE(vec_prove_two_two.x == 2.0f); //Test 0+1+1=2
	REQUIRE(vec_prove_two_two.y == 2.0f); //Test 0+1+1=2
}


TEST_CASE("test_vec_subtract", "[vec2]"){
  Vec2 vec_prove_zero_zero{1.0f,1.0f};
	vec_prove_zero_zero.operator-=(vec_one_one);
	REQUIRE(vec_prove_zero_zero.x == 0.0f); //Test 1-1=0
	REQUIRE(vec_prove_zero_zero.y == 0.0f); //Test 1-1=0

	Vec2 vec_prove_nTwo_zero{ 5.0f,2.0f };
	vec_prove_nTwo_zero.operator-=(vec_seven_one);
	vec_prove_nTwo_zero.operator-=(vec_zero_one);
	REQUIRE(vec_prove_nTwo_zero.x == -2.0f); //Test 5-7-0=-2
	REQUIRE(vec_prove_nTwo_zero.y == 0.0f); //Test 2-1-1=0

	Vec2 vec_prove_one_one{ 5.0f,2.0f };
	vec_prove_one_one.operator-=(vec_five_two);
	vec_prove_one_one.operator+=(vec_one_one);
	REQUIRE(vec_prove_one_one.x == 1.0f); //Test 5-5+1=1
	REQUIRE(vec_prove_one_one.y == 1.0f); //Test 2-2+1=1
}

TEST_CASE("test_vec_multiply", "[vec2]"){
  Vec2 vec_prove_tenFive_threeFive{7.0f,2.0f};
	vec_prove_tenFive_threeFive.operator*=(1.5f);
	REQUIRE(vec_prove_tenFive_threeFive.x == 10.5f); //Test 7*1.5=10.5
	REQUIRE(vec_prove_tenFive_threeFive.y == 3.0f); //Test 2*1.5=3.0

	Vec2 vec_prove_nFive_nTwo{ 5.0f,2.0f };
	vec_prove_nFive_nTwo.operator*=(-1.0f);
	REQUIRE(vec_prove_nFive_nTwo.x == -5.0f); //Test 5*-1=-5
	REQUIRE(vec_prove_nFive_nTwo.y == -2.0f); //Test 2*-1=-2

	Vec2 vec_prove_fourOFive_sixSevenFive{ 3.0f,5.0f }; 
	vec_prove_fourOFive_sixSevenFive.operator*=(1.35f);
	REQUIRE(vec_prove_fourOFive_sixSevenFive.x == 4.05f); //Test 3*1.35=4.05
	REQUIRE(vec_prove_fourOFive_sixSevenFive.y == 6.75f); //Test 5*1.35=6.75
}

TEST_CASE("test_vec_divide", "[vec2]"){
  Vec2 vec_prove_five_zeroSix{ 25.0f,3.0f };
	vec_prove_five_zeroSix.operator/=(5.0f);
	REQUIRE(vec_prove_five_zeroSix.x == 5.0f); //Test 25/5=5
	REQUIRE(vec_prove_five_zeroSix.y == 0.6f); //Test 3/5=0.6

	Vec2 vec_prove_nOne_nineSix{ 5.0f,48.0f };
	vec_prove_nOne_nineSix.operator/=(-0.2f);
	REQUIRE(vec_prove_nOne_nineSix.x == -25.0f); //Test 5/-0.2=-25
	REQUIRE(vec_prove_nOne_nineSix.y == -240.0f); //Test 48/-0.2=-240.0

	Vec2 vec_prove_error_divZero{ 1.0f,1.0f };
	vec_prove_error_divZero.operator/=(0);
	REQUIRE(vec_prove_error_divZero.x == 1.0f);
	REQUIRE(vec_prove_error_divZero.y == 1.0f);
}




int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
