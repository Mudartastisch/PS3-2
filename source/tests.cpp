#define CATCH_CONFIG_RUNNER
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rect.hpp"
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
	REQUIRE(vec_prove_one_zero.x == Approx(1.0f)); //Test 0+1=1
	REQUIRE(vec_prove_one_zero.y == 0.0f); //Test 0+0=0

	Vec2 vec_prove_two_one{1.0f,1.0f};
	vec_prove_two_one.operator+=(vec_one_zero);
	REQUIRE(vec_prove_two_one.x == Approx(2.0f)); //Test 1+1=2
	REQUIRE(vec_prove_two_one.y == Approx(1.0f)); //Test 1+0=1

	Vec2 vec_prove_two_two{};
	vec_prove_two_two.operator+=(vec_one_one);
	vec_prove_two_two.operator+=(vec_one_one);
	REQUIRE(vec_prove_two_two.x == Approx(2.0f)); //Test 0+1+1=2
	REQUIRE(vec_prove_two_two.y == Approx(2.0f)); //Test 0+1+1=2
}


TEST_CASE("test_vec_subtract_modify", "[vec2]"){
  Vec2 vec_prove_zero_zero{1.0f,1.0f};
	vec_prove_zero_zero.operator-=(vec_one_one);
	REQUIRE(vec_prove_zero_zero.x == Approx(0.0f)); //Test 1-1=0
	REQUIRE(vec_prove_zero_zero.y == Approx(0.0f)); //Test 1-1=0

	Vec2 vec_prove_nTwo_zero{ 5.0f,2.0f };
	vec_prove_nTwo_zero.operator-=(vec_seven_one);
	vec_prove_nTwo_zero.operator-=(vec_zero_one);
	REQUIRE(vec_prove_nTwo_zero.x == Approx(-2.0f)); //Test 5-7-0=-2
	REQUIRE(vec_prove_nTwo_zero.y == Approx(0.0f)); //Test 2-1-1=0

	Vec2 vec_prove_one_one{ 5.0f,2.0f };
	vec_prove_one_one.operator-=(vec_five_two);
	vec_prove_one_one.operator+=(vec_one_one);
	REQUIRE(vec_prove_one_one.x == Approx(1.0f)); //Test 5-5+1=1
	REQUIRE(vec_prove_one_one.y == Approx(1.0f)); //Test 2-2+1=1
}

TEST_CASE("test_vec_multiply_modify", "[vec2]"){
  Vec2 vec_prove_tenFive_threeFive{7.0f,2.0f};
	vec_prove_tenFive_threeFive.operator*=(1.5f);
	REQUIRE(vec_prove_tenFive_threeFive.x == Approx(10.5f)); //Test 7*1.5=10.5
	REQUIRE(vec_prove_tenFive_threeFive.y == Approx(3.0f)); //Test 2*1.5=3.0

	Vec2 vec_prove_nFive_nTwo{ 5.0f,2.0f };
	vec_prove_nFive_nTwo.operator*=(-1.0f);
	REQUIRE(vec_prove_nFive_nTwo.x == Approx(-5.0f)); //Test 5*-1=-5
	REQUIRE(vec_prove_nFive_nTwo.y == Approx(-2.0f)); //Test 2*-1=-2

	Vec2 vec_prove_fourOFive_sixSevenFive{ 3.0f,5.0f }; 
	vec_prove_fourOFive_sixSevenFive.operator*=(1.35f);
	REQUIRE(vec_prove_fourOFive_sixSevenFive.x == Approx(4.05f)); //Test 3*1.35=4.05
	REQUIRE(vec_prove_fourOFive_sixSevenFive.y == Approx(6.75f)); //Test 5*1.35=6.75
}

TEST_CASE("test_vec_divide_modify", "[vec2]"){
  Vec2 vec_prove_five_zeroSix{ 25.0f,3.0f };
	vec_prove_five_zeroSix.operator/=(5.0f);
	REQUIRE(vec_prove_five_zeroSix.x == Approx(5.0f)); //Test 25/5=5
	REQUIRE(vec_prove_five_zeroSix.y == Approx(0.6f)); //Test 3/5=0.6

	Vec2 vec_prove_nOne_nineSix{ 5.0f,48.0f };
	vec_prove_nOne_nineSix.operator/=(-0.2f);
	REQUIRE(vec_prove_nOne_nineSix.x == Approx(-25.0f)); //Test 5/-0.2=-25
	REQUIRE(vec_prove_nOne_nineSix.y == Approx(-240.0f)); //Test 48/-0.2=-240.0

	Vec2 vec_prove_error_divZero{ 1.0f,1.0f };
	vec_prove_error_divZero.operator/=(0);
	REQUIRE(vec_prove_error_divZero.x == Approx(1.0f));
	REQUIRE(vec_prove_error_divZero.y == Approx(1.0f));
}

TEST_CASE("test_vec_add", "[vec2]"){
  Vec2 vec_prove_add_two_two{operator+(vec_one_one, vec_one_one) };
	REQUIRE(vec_prove_add_two_two.x == Approx(2.0f)); //1+1=2
	REQUIRE(vec_prove_add_two_two.y == Approx(2.0f)); //1+1=2

	Vec2 vec_prove_add_nSeven_one{ operator+(vec_nFour_nFour,vec_nThree_five) };
	REQUIRE(vec_prove_add_nSeven_one.x == Approx(-7.0f)); //-4+-3=-7
	REQUIRE(vec_prove_add_nSeven_one.y == Approx(1.0f)); //-4+5=1

	Vec2 vec_prove_add_seven_one{ operator+(vec_seven_one,vec_zero_zero) };
	REQUIRE(vec_prove_add_seven_one.x == Approx(7.0f)); //7+0=7
	REQUIRE(vec_prove_add_seven_one.y == Approx(1.0f)); //1+0=1
}
TEST_CASE("test_vec_subtract", "[vec2]"){
  Vec2 vec_prove_sub_zero_zero{ operator-(vec_one_one,vec_one_one) };
	REQUIRE(vec_prove_sub_zero_zero.x == Approx(0.0f)); //1-1=0
	REQUIRE(vec_prove_sub_zero_zero.y == Approx(0.0f)); //1-1=0

	Vec2 vec_prove_sub_two_nOne{ operator-(vec_seven_one,vec_five_two) };
	REQUIRE(vec_prove_sub_two_nOne.x == Approx(2.0f)); //7-5=2
	REQUIRE(vec_prove_sub_two_nOne.y == Approx(-1.0f)); //1-2=-1

	Vec2 vec_prove_sub_nOne_nNine{ operator-(vec_nFour_nFour,vec_nThree_five) };
	REQUIRE(vec_prove_sub_nOne_nNine.x == Approx(-1.0f)); //-4--3=-1
	REQUIRE(vec_prove_sub_nOne_nNine.y == Approx(-9.0f)); //-4-5=-9
}
TEST_CASE("test_vec_multiply", "[vec2]"){
  Vec2 vec_prove_mul_two_two{ operator*(vec_one_one,2.0) };
	REQUIRE(vec_prove_mul_two_two.x == Approx(2.0f)); //1*2=2
	REQUIRE(vec_prove_mul_two_two.y == Approx(2.0f)); //1*2=2

	Vec2 vec_prove_mul_one_zeroFour{ operator*(vec_five_two,0.2f) };
	REQUIRE(vec_prove_mul_one_zeroFour.x == Approx(1.0f)); //5*0.2=1
	REQUIRE(vec_prove_mul_one_zeroFour.y == Approx(0.4f)); //2*0.2=0.4

	Vec2 vec_prove_mul_twoFourFive_zeroThreeFive{ operator*(0.35f,vec_seven_one) };
	REQUIRE(vec_prove_mul_twoFourFive_zeroThreeFive.x == Approx(2.45f)); //7*0.35=2.45
	REQUIRE(vec_prove_mul_twoFourFive_zeroThreeFive.y == Approx(0.35f)); //1*0.35
}
TEST_CASE("test_vec_divide", "[vec2]"){
  Vec2 vec_prove_div_threeFive_zeroFive{ operator/(vec_seven_one,2.0f) };
	REQUIRE(vec_prove_div_threeFive_zeroFive.x == Approx(3.5f)); //7/2=3.5
	REQUIRE(vec_prove_div_threeFive_zeroFive.y == Approx(0.5f)); //1/2=0.5

	Vec2 vec_prove_div_ten_four{ operator/(vec_five_two, 0.5f) };
	REQUIRE(vec_prove_div_ten_four.x == Approx(10.0f)); //5/0.5=10
	REQUIRE(vec_prove_div_ten_four.y == Approx(4.0f)); //2/0.5=4

	Vec2 vec_prove_div_nOneFive_woFive{ operator/(vec_nThree_five,2.0f) };
	REQUIRE(vec_prove_div_nOneFive_woFive.x == Approx(-1.5f)); //5/0.5=10
	REQUIRE(vec_prove_div_nOneFive_woFive.y == Approx(2.5f)); //2/0.5=4
}

TEST_CASE("test_mat", "[mat2"){
	Mat2 Mat_30_50_25_40{ 30,50,25,40 };
	Mat2 Mat_2_3_1_1{ 2,3,1,1 };
	Mat2 Mat_110_140_75_115{ operator*(Mat_30_50_25_40,Mat_2_3_1_1) };
	REQUIRE(Mat_110_140_75_115.e_00 == 110.0f);
	REQUIRE(Mat_110_140_75_115.e_01 == 140.0f);
	REQUIRE(Mat_110_140_75_115.e_10 == 75.0f);
	REQUIRE(Mat_110_140_75_115.e_11 == 115.0f);
}


TEST_CASE("test_circle_circ", "circle"){
  Circle circle{{0.0}, 5.0f,{0.0f,0.0f,0.0f}};
  REQUIRE(circle.circumference() == Approx(31.4159265359f));
}

TEST_CASE("test_rectangle_circ", "rect"){
  Rectangle rect{{0.0f,0.0f}, {2.0f, 4.0f}, {0.0f,0.0f,0.0f}};
  REQUIRE(rect.circumference() == Approx(12.0f));
}
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
