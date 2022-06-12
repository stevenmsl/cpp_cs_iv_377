#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol377;
using namespace std;

/*takeaways
- Use DP
  - we are actually looking for permutations here
    - (1,1,2) and (1,2,1) are considered different

  - dp[t] stores the number of permutations whose
    members will sum up to t

- start with target = 1
  - dp[1] = dp[1] + dp[0] = 0 + 1 = 1
    by default dp[i] is all initalized to 0,
    so that's why we set dp[0] to 1
  - {} -> {1}, there is ony one way

- next target = 2, scan the entire set to calculate dp[2].
  - There are two possibilities:
    - start from 0 and add a 2 {2}
    - start from 1 and add another 1 {1,1}
    - so dp[2] = dp[0] + dp[1] = 1 + 1 = 2
- next target = 3, scan the entire set to calculate dp[3].
  - start from 0 and add a 3  {} ->  {3}
  - start from 1 and add a 2   {1} -> {1,2}
  - start from 2 and add a 1
    from {1,1} -> {1,1,1}
    from {2} -> {2,1}
    - note that {1,2} and {2,1} are considered different
  - so dp[3] = dp[0] + dp[1] + dp[2] = 1 + 1 + 2  = 4
- ok onto the last one when target is 4
  - start from 0 won't work
    - you can come to 4 from 1 by adding a '3', from
      2 by adding a '2', and from '3' by adding a '1'.
    - since you only have {1,2,3} to choose from 
      so you can't start from a '0' 

  - start from 1 you can add a 3, so {1} -> {1,3}
  - start from 2 you can add a 2, so {2} -> {2,2} and {1,1} -> {1,1,2}
  - start from 3 you can add a 1
    - so {3} -> {3,1}, {1,2} -> {1,2,1}, {1,1,1} -> {1,1,1,1},
      and {2,1} to {2,1,1}
  - so dp[4] = dp[1] + dp[2] + dp[3] = 1 + 2 + 4 = 7
*/

int Solution::find(vector<int> &nums, int target)
{
  auto dp = vector<int>(target + 1, 0);
  /* an empty set is a legit combination */
  dp[0] = 1;
  /* build from the ground up */
  for (auto t = 1; t <= target; t++)
    for (auto num : nums)
      if (t - num >= 0)
        /* each combination that has its members summing up to t-num
           can be expended by adding "num" as its new member so
           the expended combination will have its members summing up to
           t
        */
        dp[t] += dp[t - num];

  return dp[target];
}