#include "Prometheus.Engine.Core.Pointer.hpp"
#include <doctest/doctest.h>

TEST_CASE("Pointer empty")
{
	prometheus::core::pointer<int> ptr;
	SUBCASE("Pointer empty: ptr == nullptr")
	{
		CHECK(ptr == nullptr);
	}
	SUBCASE("Pointer empty: !ptr")
	{
		CHECK(!ptr);
	}
}

TEST_CASE("Pointer not empty")
{
	prometheus::core::pointer<int> ptr = new int();
	SUBCASE("Pointer not empty: ptr != nullptr")
	{
		CHECK(ptr != nullptr);
	}
	SUBCASE("Pointer not empty: ptr")
	{
		const bool not_empty = ptr;
		CHECK(not_empty);
	}
}