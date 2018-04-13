#include <catch.hpp>
#include <sstream>

#include "vector.hpp"

TEST_CASE("Creat")
{
	queue_t<int> My_queue;
	REQUIRE( My_queue.head == nullptr );
	REQUIRE( My_queue.tail == nullptr );
	
}

TEST_CASE("pop and push")
{
	queue_t<int> My_queue;
	My_queue.push(8);
	My_queue.push(3);
	My_queue.push(9);
	REQUIRE( My_queue.pop() == 8);
	REQUIRE( My_queue.pop() == 3);
	REQUIRE( My_queue.pop() == 9);
}

TEST_CASE("pop and push")
{
	queue_t<double> My_queue;
	My_queue.push(8.3);
	My_queue.push(3.4);
	My_queue.push(9.2);
	REQUIRE( My_queue.pop() == 8.3);
	REQUIRE( My_queue.pop() == 3.4);
	REQUIRE( My_queue.pop() == 9.2);
}

TEST_CASE("Error pop")
{
	queue_t<int> My_queue;
	REQUIRE_THROWS_AS( My_queue.pop() , Error);
	
}

TEST_CASE("Cop")
{
	queue_t<int> My_queue_1;
	My_queue_1.push(6);
	My_queue_1.push(1);
	queue_t<int> My_queue_2;
	My_queue_2.push(7);
	My_queue_2.push(9);
	My_queue_2=My_queue_1;
	REQUIRE( My_queue_2.pop() == 6);
	REQUIRE( My_queue_2.pop() == 1);
	
}
