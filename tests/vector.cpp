#include <catch.hpp>
#include <sstream>

#include "vector.hpp"

TEST_CASE("Creat")
{
	queue_t<int> My_queue;
	REQUIRE( My_queue.head() == nullptr );
	REQUIRE( My_queue.tail() == nullptr );
	
}

TEST_CASE("pop and push")
{
	queue_t<int> My_queue;
	My_queue.push(1);
	My_queue.push(2);
	int sum = My_queue.pop();
	sum = sum + My_queue.pop();
	REQUIRE( sum == 3 );
	
}

TEST_CASE("throw")
{
	queue_t<int> My_queue;
	REQUIRE_THROWS_AS( My_queue.pop() , Error);
	
}

TEST_CASE("copy")
{
	queue_t<int> My_queue_1;
	My_queue_1.push(1);
	My_queue_1.push(2);
	queue_t<int> My_queue_2(My_queue_1);
	int sum = My_queue_2.pop();
	sum = sum + My_queue_2.pop();
	REQUIRE( sum == 3 );
	
}
