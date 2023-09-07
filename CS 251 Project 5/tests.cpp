/// @file tests.cpp
/// @date March 17, 2023

/// 
/// TODO

/// Provided testing file to implement framework based tests in. The examples
/// below demonstrates a basic empty test in each framework with a single
/// assertion. The version uses the supplied catch.hpp file in starter code.
///
/// Assignment details and provided code are created and
/// owned by Adam T Koehler, PhD - Copyright 2023.
/// University of Illinois Chicago - CS 251 Spring 2023

// TODO:
// Choose which framework to keep and delete the other.
//
//-------------------------------------
// Name: Esat Duman
// Course: Data Structures CS 251 
// UIN:662726641
// Project #5: Priority Queue
//-------------------------------------

// Catch 1.0 Framework Testing
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "priorityqueue.h"

using namespace std;

TEST_CASE("(0) no tests") 
{
    REQUIRE(true);
}

TEST_CASE("Default Constructor")
{
priorityqueue<int> pq1;
assert(pq1.Size() == 0);
}
// Test Case 2
// Test enqueue() and size()
TEST_CASE("enqueue TESTING") {
priorityqueue<int> pq2;
pq2.enqueue(10, 1);
pq2.enqueue(20, 2);
pq2.enqueue(30, 3);
assert(pq2.Size() == 3);
}
// Test Case 3
// Test front() with non-empty queue
TEST_CASE("TEST CASE 3") {
 // Test Case 3
// Test dequeue() with non-empty queue
priorityqueue<int> pq5;
pq5.enqueue(10, 1);
pq5.enqueue(20, 2);
pq5.enqueue(30, 3);
int top_element = pq5.dequeue();  // remove top element
pq5.enqueue(top_element, 2);  // reinsert top element with correct priority
assert(pq5.dequeue() == 20);  // check that new top element is correct
}

TEST_CASE("toString returns expected result for empty queue") {
    priorityqueue<int> pq;
    REQUIRE(pq.toString() == "");
}

TEST_CASE("toString returns the correct string representation of the priority queue") {
    priorityqueue<int> pq;
    pq.enqueue(15, 1);
    pq.enqueue(16, 2);
    pq.enqueue(2, 3);
    pq.enqueue(1, 3);
    pq.enqueue(9, 2);
    pq.enqueue(8, 2);
    pq.enqueue(7, 2);
    pq.enqueue(6, 2);
    pq.enqueue(17, 3);
    std::string expected = "1 value: 15\n"
                           "2 value: 16\n"
                           "3 value: 2\n"
                           "3 value: 1\n"
                           "2 value: 9\n"
                           "3 value: 8\n"
                           "4 value: 7\n"
                           "5 value: 6\n"
                           "3 value: 17\n";
    REQUIRE(pq.toString() == expected);
}



TEST_CASE("(1) enqueue and size") 
{
    priorityqueue<int> pq;
    REQUIRE(pq.Size() == 0);

    pq.enqueue(1, 1);
    REQUIRE(pq.Size() == 1);

    pq.enqueue(2, 1);
    REQUIRE(pq.Size() == 2);

    pq.enqueue(3, 2);
    REQUIRE(pq.Size() == 3);

    pq.enqueue(4, 3);
    REQUIRE(pq.Size() == 4);
}


TEST_CASE("(2) toString") 
{
    priorityqueue<int> pq;
    pq.enqueue(1, 1);
    pq.enqueue(2, 1);
    pq.enqueue(3, 2);
    pq.enqueue(4, 3);

    string expected = "1 value: 1\n"
                      "1 value: 2\n"
                      "2 value: 3\n"
                      "3 value: 4\n";
    REQUIRE(pq.toString() == expected);
}

TEST_CASE("(3) clear") 
{
    priorityqueue<int> pq;
    pq.enqueue(1, 1);
    pq.enqueue(2, 1);
    pq.enqueue(3, 2);
    pq.enqueue(4, 3);

    REQUIRE(pq.Size() == 4);
    pq.clear();
    REQUIRE(pq.Size() == 0);
}

TEST_CASE("(4) copy constructor") 
{
    priorityqueue<int> pq1;
    pq1.enqueue(1, 1);
    pq1.enqueue(2, 1);
    pq1.enqueue(3, 2);
    pq1.enqueue(4, 3);

    priorityqueue<int> pq2 = pq1;

    REQUIRE(pq2.Size() == 4);
    REQUIRE(pq2.toString() == pq1.toString());
}

TEST_CASE(" assignment operator") 
{
    priorityqueue<int> pq1;
    pq1.enqueue(1, 1);
    pq1.enqueue(2, 1);
    pq1.enqueue(3, 2);
    pq1.enqueue(4, 3);

    priorityqueue<int> pq2;
    pq2 = pq1;

    REQUIRE(pq2.Size() == 4);
    REQUIRE(pq2.toString() == pq1.toString());
}

TEST_CASE("Test case for enqueueing elements with same priority") {

    priorityqueue<int> pq1;
    pq1.enqueue(10, 2);
    pq1.enqueue(20, 2);
    pq1.enqueue(30, 2);
    assert(pq1.Size() == 3);
    assert(pq1.dequeue() == 10);
    assert(pq1.dequeue() == 20);
    assert(pq1.dequeue() == 30);
}

TEST_CASE("Test case for enqueueing elements with different priorities:")
{

    priorityqueue<int> pq2;
    pq2.enqueue(10, 3);
    pq2.enqueue(20, 1);
    pq2.enqueue(30, 2);
    assert(pq2.Size() == 3);
    assert(pq2.dequeue() == 20);
    assert(pq2.dequeue() == 30);
    assert(pq2.dequeue() == 10);

}

TEST_CASE("Test case for enqueueing and dequeueing elements of type string") {
    priorityqueue<string> pq5;
    pq5.enqueue("apple", 2);
    pq5.enqueue("banana", 3);
    pq5.enqueue("carrot", 1);
    assert(pq5.Size() == 3);
    assert(pq5.dequeue() == "carrot");
    assert(pq5.dequeue() == "apple");
    assert(pq5.dequeue() == "banana");
}

TEST_CASE("test for int  enqueue"){

    priorityqueue<int> pq1;
    pq1.enqueue(10, 1);
    pq1.enqueue(20, 1);
    pq1.enqueue(30, 2);
    assert(pq1.Size() == 3);

}

TEST_CASE("test for string enqueue") {

priorityqueue<string> pq2;
pq2.enqueue("hello", 1);
pq2.enqueue("world", 2);
pq2.enqueue("foo", 3);
assert(pq2.Size() == 3);

}

TEST_CASE("Multiple Elements test") {
    priorityqueue<int> pq;
    pq.enqueue(10, 1);
    pq.enqueue(20, 2);
    pq.enqueue(30, 3);
    assert(pq.dequeue() == 30);
    assert(pq.dequeue() == 20);
    assert(pq.dequeue() == 10);
    assert(pq.Size() == 0);
}

TEST_CASE("Duplicate elements") {
    priorityqueue<int> pq;
    pq.enqueue(10, 1);
    pq.enqueue(20, 1);
    pq.enqueue(30, 2);
    pq.enqueue(40, 2);
    assert(pq.dequeue() == 30);
    assert(pq.dequeue() == 40);
    assert(pq.dequeue() == 10);
    assert(pq.dequeue() == 20);
    assert(pq.Size() == 0);
}
TEST_CASE("Copy constructor and copy assignment operator") {
    priorityqueue<int> pq1;
    pq1.enqueue(1, 1);
    pq1.enqueue(2, 2);
    pq1.enqueue(3, 3);

    SECTION("Copy constructor") {
        priorityqueue<int> pq2(pq1);
        REQUIRE(pq1 == pq2);
        REQUIRE(pq1.Size() == pq2.Size());
    }

    SECTION("Copy assignment operator") {
        priorityqueue<int> pq3;
        pq3 = pq1;
        REQUIRE(pq1 == pq3);
        REQUIRE(pq1.Size() == pq3.Size());
    
    }


    
}

// The test cases below are borrowed from a classmate named: mshai9 Muhammad Shaikh
  TEST_CASE("Example test case from the document") {
    std::map<int, std::vector<int>> expected_map;
    int n = 5;
    int vals[] = {10, 20, 30, 40, 50};
    int prs[] = {1, 2, 2, 3, 3};
    priorityqueue<int> pq;


    for (int i = 0; i < n; i++) {
        pq.enqueue(vals[i], prs[i]);
        expected_map[prs[i]].push_back(vals[i]);
    }

    REQUIRE(pq.Size() == n);

    // Build expected string from map
    stringstream expected_ss;
    for (const auto& e: expected_map) {
        int priority = e.first;
        vector<int> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            expected_ss << priority << " value: " << values[j] << std::endl;
        }
    }

    REQUIRE(pq.toString() == expected_ss.str());
}
TEST_CASE("Testing begin() with unique priorities") {

        priorityqueue<int> pq;
        pq.enqueue(15, 1);
        pq.enqueue(16, 2);
        pq.enqueue(17, 3);
        pq.enqueue(6, 4);
        pq.enqueue(7, 5);
        pq.enqueue(8, 6);
        pq.enqueue(9, 7);
        pq.enqueue(2, 8);
        pq.enqueue(1, 9);

        REQUIRE(pq.Size() == 9);

        std::stringstream ss;
         pq.begin();
        std::string first_element = ss.str();
        REQUIRE(first_element == "priority: 1 value: 15");
    }
TEST_CASE("Operator=") {
    priorityqueue<int> p1;
    p1.enqueue(1, 1);
    p1.enqueue(2, 2);
    p1.enqueue(3, 3);

    priorityqueue<int> p2;
    p2=p1;

    REQUIRE(p1.Size() == p2.Size());
    REQUIRE(p1.toString() == p2.toString());
}
//This from a freind //Kareem Mohsin kmohs2
TEST_CASE("Dequeue") {
    priorityqueue<int> q;
        q.enqueue(10, 3);
        q.enqueue(20, 1);
        q.enqueue(30, 5);
        q.enqueue(40, 3);
        REQUIRE(q.dequeue() == 20);
        REQUIRE(q.Size() == 3);

        REQUIRE(q.dequeue() == 10);
        REQUIRE(q.Size() == 2);

        REQUIRE(q.dequeue() == 40);
        REQUIRE(q.Size() == 1);

        REQUIRE(q.dequeue() == 30);
        REQUIRE(q.Size() == 0);
}  