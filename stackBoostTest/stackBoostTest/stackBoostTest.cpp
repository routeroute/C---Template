#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "stack1.hpp"
#include <boost/test/unit_test.hpp>
using namespace boost::unit_test_framework;

typedef struct Item {
	int pcode;		/* 商品コード */
	int scode;		/* 棚コード */
} ITEM, *LPITEM ;

// string test
BOOST_AUTO_TEST_CASE(string_test)
{
	Stack<std::string> stringStack;    // stack of strings
	
	// empty check
	BOOST_TEST_CHECKPOINT("empty check");
	BOOST_CHECK(stringStack.empty());
	
	// throw check
	BOOST_TEST_CHECKPOINT("throw check");
	//BOOST_CHECK_THROW(stringStack, std::exception);
	
	// push(), top(), pop() check
	std::string testString("hello");

	BOOST_TEST_CHECKPOINT("push testString");
    stringStack.push(testString);
	
	BOOST_TEST_CHECKPOINT("not empty check");
	BOOST_CHECK_EQUAL(stringStack.empty(), false);
	
	BOOST_TEST_CHECKPOINT("reference top, pop");
	std::string compStr;
	compStr += stringStack.top();
	stringStack.pop();
	BOOST_CHECK_EQUAL(compStr, testString);

	// empty check(pop all)
	BOOST_TEST_CHECKPOINT("empty check(pop all)");
	BOOST_CHECK(stringStack.empty());
}

// struct test
BOOST_AUTO_TEST_CASE(struct_test)
{
	Stack<ITEM> itemStack;

	// empty check
	BOOST_TEST_CHECKPOINT("empty check");
	BOOST_CHECK(itemStack.empty());
	
	// throw check
	BOOST_TEST_CHECKPOINT("throw check");
	//BOOST_CHECK_THROW(itemStack, std::exception);

	// push(), pop() check
	BOOST_TEST_CHECKPOINT("push testItem");
	ITEM testItem = {1, 2};
	itemStack.push(testItem);
	
	BOOST_TEST_CHECKPOINT("not empty check");
	BOOST_CHECK_EQUAL(itemStack.empty(), false);
	
	BOOST_TEST_CHECKPOINT("reference top, pop");
	BOOST_CHECK_EQUAL(itemStack.top().pcode, testItem.pcode);
	BOOST_CHECK_EQUAL(itemStack.top().scode, testItem.scode);
	itemStack.pop();
	
	// empty check(pop all) check
	BOOST_TEST_CHECKPOINT("empty check(pop all)");
	BOOST_CHECK(itemStack.empty());
}

// auto_test_case added & initialized
test_suite* init_unit_test_suite(int argc, char* argv[]) {
  test_suite* test = BOOST_TEST_SUITE("stack test");
  return test;
}
