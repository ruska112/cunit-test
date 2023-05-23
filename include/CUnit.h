#ifndef CUNIT_CUNIT_H_
#define CUNIT_CUNIT_H_

#include <cstddef>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (v.empty()) {
    os << "TRYING TO OUTPUT EMPTY VECTOR";
  } else {
    os << "[";
    for (auto i = v.cbegin(); i != v.cend();) {
      os << *i;
      if (++i != v.cend()) {
        os << ", ";
      }
    }
    os << "]";
  }
  return os;
}

template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
  if (s.empty()) {
    os << "TRYING TO OUTPUT EMPTY SET";
  } else {
    os << "{";
    for (auto i = s.cbegin(); i != s.cend();) {
      os << *i;
      if (++i != s.cend()) {
        os << ", ";
      }
    }
    os << "}";
  }
  return os;
}

template <typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V>& m) {
  if (m.empty()) {
    os << "TRYING TO OUTPUT EMPTY MAP";
  } else {
    os << "{";
    for (auto i = m.cbegin(); i != m.cend();) {
      os << "(";
      os << i->first << ": ";
      os << i->second;
      os << ")";
      if (++i != m.cend()) {
        os << ", ";
      }
    }
    os << "}";
  }
  return os;
}

template <typename T, typename U>
void AssertEqualImpl(const T& t, const U& u, const string& t_str,
                     const string& u_str, const string& file,
                     const string& func, unsigned line, const string& hint) {
  if (t != u) {
    cout << boolalpha;
    cout << file << "(" << line << "): " << func << ": ";
    cout << "ASSERT_EQUAL(" << t_str << ", " << u_str << ") failed: ";
    cout << t << " != " << u << ".";
    if (!hint.empty()) {
      cout << " Hint: " << hint;
    }
    cout << endl;
    abort();
  }
}

#define ASSERT_EQUAL(a, b) \
  AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, "")

#define ASSERT_EQUAL_HINT(a, b, hint) \
  AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, (hint))

#endif  //  CUNIT_CUNIT_H_
