/*
 * make_account2.cpp
 *
 *  Created on: Nov 2, 2014
 *      Author: lifebalance
 */

#include <igloo/igloo.h>
using namespace igloo;

#include <iostream>
using namespace std;

#include <vector>

int make_amount(int amount, vector<int>& denominations)
{
	if (amount == 0)
  	  return 1;
    if (amount < 0)
	  return 0;
	if (denominations.size() == 0)
		return 0;

	int current_coin = denominations[0];
	vector<int> rest_of_coins (denominations.begin()+1, denominations.end());

	int count = 0;
	while (amount >= 0)
	{
		count = make_amount(amount, rest_of_coins);
		amount = amount - current_coin;
	}

	return count;
}

int make_amount(int amount, int denominations[], int size)
{
	vector<int> v_d(denominations, denominations+size);
	return make_amount(amount, v_d);

}

Context(AAmountConverter)
{
	Spec(ShouldOutput1For0)
	{
	  int d[1] = {1};
	  Assert::That(make_amount(0, d, 1), Equals(1));
	}
	Spec(ShouldOutput0ForNegative1)
	{
	  int d[1] = {1};
	  Assert::That(make_amount(-1, d, 1), Equals(0));
	}

	Spec(ShouldOutput0For1AndNull)
	{
	  Assert::That(make_amount(1, {}, 0), Equals(0));
	}
	Spec(ShouldOutput1For1And1)
	{
	  int d[1] = {1};
	  Assert::That(make_amount(1, d, 1), Equals(1));
	}

};


