// Configure.h

#pragma once

#include <string> 
#include <vector> 

class Configure
{
private:
	std::vector<std::string> vItems;

public:
	int addItem(std::string str);
	std::string getItem(int index);
	int getSize();
};

// Configure.cpp
#include "Configure.h" 
#include <algorithm> 

/**
* @brief Add an item to configuration store. Duplicate item will be ignored
* @param str item to be stored
* @return the index of added configuration item
*/
int Configure::addItem(std::string str)
{
	std::vector<std::string>::const_iterator vi = std::find(vItems.begin(), vItems.end(), str);
	if (vi != vItems.end())
		return vi - vItems.begin();

	vItems.push_back(str);
	return vItems.size() - 1;
}

/**
* @brief Return the configure item at specified index.
* If the index is out of range, "" will be returned
* @param index the index of item
* @return the item at specified index
*/
std::string Configure::getItem(int index)
{
	if (index >= vItems.size())
		return "";
	else
		return vItems.at(index);
}

/// Retrieve the information about how many configuration items we have had 
int Configure::getSize()
{
	return vItems.size();
}

// ConfigureTest.cpp
#include <gtest/gtest.h> 
#include "Configure.h" 

// Test function
TEST(ConfigureTest, addItem)
{
	// do some initialization 
	Configure* pc = new Configure();

	// validate the pointer is not null 
	ASSERT_TRUE(pc != NULL);

	// call the method we want to test 
	pc->addItem("A");
	pc->addItem("B");
	pc->addItem("A");

	// validate the result after operation 
	EXPECT_EQ(pc->getSize(), 2);
	EXPECT_STREQ(pc->getItem(0).c_str(), "A");
	EXPECT_STREQ(pc->getItem(1).c_str(), "B");
	EXPECT_STREQ(pc->getItem(10).c_str(), "");

	delete pc;
}

// Program entry
int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::cin.get();

	return 0;
}
