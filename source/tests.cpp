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



TEST_CASE("test_vec_add_modify", "[vec2]"){
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


TEST_CASE("test_vec_subtract_modify", "[vec2]"){
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

TEST_CASE("test_vec_multiply_modify", "[vec2]"){
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

TEST_CASE("test_vec_divide_modify", "[vec2]"){
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

TEST_CASE("test_vec_add", "[vec2]"){
  Vec2 vec_prove_add_two_two{operator+(vec_one_one, vec_one_one) };
	REQUIRE(vec_prove_add_two_two.x == 2.0f); //1+1=2
	REQUIRE(vec_prove_add_two_two.y == 2.0f); //1+1=2

	Vec2 vec_prove_add_nSeven_one{ operator+(vec_nFour_nFour,vec_nThree_five) };
	REQUIRE(vec_prove_add_nSeven_one.x == -7.0f); //-4+-3=-7
	REQUIRE(vec_prove_add_nSeven_one.y == 1.0f); //-4+5=1

	Vec2 vec_prove_add_seven_one{ operator+(vec_seven_one,vec_zero_zero) };
	REQUIRE(vec_prove_add_seven_one.x == 7.0f); //7+0=7
	REQUIRE(vec_prove_add_seven_one.y == 1.0f); //1+0=1
}
TEST_CASE("test_vec_subtract", "[vec2]"){
  Vec2 vec_prove_sub_zero_zero{ operator-(vec_one_one,vec_one_one) };
	REQUIRE(vec_prove_sub_zero_zero.x == 0.0f); //1-1=0
	REQUIRE(vec_prove_sub_zero_zero.y == 0.0f); //1-1=0

	Vec2 vec_prove_sub_two_nOne{ operator-(vec_seven_one,vec_five_two) };
	REQUIRE(vec_prove_sub_two_nOne.x == 2.0f); //7-5=2
	REQUIRE(vec_prove_sub_two_nOne.y == -1.0f); //1-2=-1

	Vec2 vec_prove_sub_nOne_nNine{ operator-(vec_nFour_nFour,vec_nThree_five) };
	REQUIRE(vec_prove_sub_nOne_nNine.x == -1.0f); //-4--3=-1
	REQUIRE(vec_prove_sub_nOne_nNine.y == -9.0f); //-4-5=-9
}
TEST_CASE("test_vec_multiply", "[vec2]"){
  Vec2 vec_prove_mul_two_two{ operator*(vec_one_one,2.0) };
	REQUIRE(vec_prove_mul_two_two.x == 2.0f); //1*2=2
	REQUIRE(vec_prove_mul_two_two.y == 2.0f); //1*2=2

	Vec2 vec_prove_mul_one_zeroFour{ operator*(vec_five_two,0.2f) };
	REQUIRE(vec_prove_mul_one_zeroFour.x == 1.0f); //5*0.2=1
	REQUIRE(vec_prove_mul_one_zeroFour.y == 0.4f); //2*0.2=0.4

	Vec2 vec_prove_mul_twoFourFive_zeroThreeFive{ operator*(0.35f,vec_seven_one) };
	REQUIRE(vec_prove_mul_twoFourFive_zeroThreeFive.x == 2.45f); //7*0.35=2.45
	REQUIRE(vec_prove_mul_twoFourFive_zeroThreeFive.y == 0.35f); //1*0.35
}
TEST_CASE("test_vec_divide", "[vec2]"){
  Vec2 vec_prove_div_threeFive_zeroFive{ operator/(vec_seven_one,2.0f) };
	REQUIRE(vec_prove_div_threeFive_zeroFive.x == 3.5f); //7/2=3.5
	REQUIRE(vec_prove_div_threeFive_zeroFive.y == 0.5f); //1/2=0.5

	Vec2 vec_prove_div_ten_four{ operator/(vec_five_two, 0.5f) };
	REQUIRE(vec_prove_div_ten_four.x == 10.0f); //5/0.5=10
	REQUIRE(vec_prove_div_ten_four.y == 4.0f); //2/0.5=4

	Vec2 vec_prove_div_nOneFive_woFive{ operator/(vec_nThree_five,2.0f) };
	REQUIRE(vec_prove_div_nOneFive_woFive.x == -1.5f); //5/0.5=10
	REQUIRE(vec_prove_div_nOneFive_woFive.y == 2.5f); //2/0.5=4
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
