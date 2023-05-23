#include "../include/CUnit.h"
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {

  std::vector<int> v1 = {1, 2, 3};
  std::vector<int> v2 = {4, 5, 6};

  std::set<int> s1 = {1, 2, 3, 1, 2, 3};
  std::set<int> s2 = {4, 5, 6, 4};

  std::map<int, std::string> m1 = {{1, "1"}, {2, "2"}, {3, "3"}};
  std::map<int, std::string> m2 = {{2, "2"}, {3, "3"}, {4, "4"}};

  //  ASSERT_EQUAL(v1, v2);
  //  ASSERT_EQUAL(s1, s2);
  ASSERT_EQUAL(m1, m2);

  return 0;
}