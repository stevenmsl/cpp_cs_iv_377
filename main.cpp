#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol377;

/*
nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Therefore the output is 7.
*/

tuple<vector<int>, int, int>
testFixture1()
{
  auto input = vector<int>{1, 2, 3};
  return make_tuple(input, 4, 7);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << to_string(get<2>(f)) << endl;
  Solution sol;
  cout << to_string(sol.find(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  return 0;
}