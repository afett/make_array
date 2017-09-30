#include <cassert>

#include "make_array.h"

#define TEST_ASSERT_STATIC(expr) \
	static_assert(expr);

int main()
{
	constexpr auto a = make_array(1, 2, 3, 4);
	TEST_ASSERT_STATIC((std::is_same<const std::array<int, 4>, decltype(a)>::value));
	TEST_ASSERT_STATIC((1 == std::get<0>(a)));
	TEST_ASSERT_STATIC((2 == std::get<1>(a)));
	TEST_ASSERT_STATIC((3 == std::get<2>(a)));
	TEST_ASSERT_STATIC((4 == std::get<3>(a)));

	constexpr auto b = make_array("foo", "bar", "baz");
	TEST_ASSERT_STATIC((std::is_same<const std::array<const char*, 3>, decltype(b)>::value));

	auto c = make_array(std::string("foo"), std::string("bar"), std::string("baz"));
	TEST_ASSERT_STATIC((std::is_same<std::array<std::string, 3>, decltype(c)>::value));
}
