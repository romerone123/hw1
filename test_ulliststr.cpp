#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.cpp"
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
	
	ULListStr test;
	test.push_front("1");
	test.push_back("2");
	test.push_back("3");
	test.push_back("4");
	test.push_back("5");
	test.push_back("6");
	test.push_back("7");
	test.push_back("8");
	test.push_back("9");
	test.push_back("10");
	test.push_back("11");
	test.push_back("12");
	test.push_back("13");
	test.push_front("-1");
	test.push_front("-2");
	/*test.pop_front();
	test.pop_front();
	test.pop_front();
	test.pop_front();
	test.pop_front();
	test.pop_front();
	test.pop_front();
	test.pop_front();
	test.pop_front();
	test.pop_front();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();

	for(int i = 14; i < 65; i++)
	{
		std::string s = std::to_string(i);
		test.push_back(s);
	}
	for(int i = 0; i < 50; i++)
	{
		test.pop_back();
	}
*/


	if(test.empty() == true)
	{
		std::cout << "empty" << std::endl;
	}
	else
	{
		std::cout << "not empty" << std::endl;
	}
	std::cout << test.size() << std::endl;
	std::cout << test.front() << std::endl;
	std::cout << test.back() << std::endl;
	std::string teststring = test.get(2);
	std::cout << teststring << std::endl;
}
