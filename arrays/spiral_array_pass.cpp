#include <iostream>
#include <vector>

/**
  1  2  3  4  5  6  7
  8  9  10 11 12 13 14             1  2  3  4  5  6
  15 16 17 18 19 20 21             7  8  9  10 11 12
  22 23 24 25 26 27 28             13 14 15 16 17 18
  29 30 31 32 33 34 35             19 20 21 22 23 24
  36 37 38 39 40 41 42             25 26 27 28 29 30
  43 44 45 46 47 48 49             31 32 33 34 35 36

  input:
  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49
  output:
  25 26 33 32 31 24 17 18 19 20 27 34 41 40 39 38 37 30 23 16 9 10 11 12 13 14 21 28 35 42 49 48 47 46 45 44 43 36 29 22 15 8 1 2 3 4 5 6 7
**/
std::vector<int> fillArray(int n) {
  std::vector<int> v;
  v.reserve(n * n);
  for (int i = 1; i <= n * n; ++i) v.push_back(i);
  return v;
}

std::vector<int> solve(const std::vector<int>& v, int m) {
  std::vector<int> s;
  size_t size = v.size();
  s.reserve(size);
  int c = 2;  // index correction
  int i = m / 2 + 1;
  int j = m / 2 + 1;
  int mid = size / 2;
  int p = m + 1;

  while (p > 0) {
    int d = i*m - m + j - c;
    s.push_back(v[d]);
    --p;

++j
++i
--j
--j
--i
++j
++j
  }
  return s;
}

std::vector<int> brute(const std::vector<int>& v, int m) {
  std::vector<int> s;
  size_t size = v.size();
  s.reserve(size);
  int i = size / 2;
  {
    s.push_back(v[i]);
    s.push_back(v[i + 1]);
    s.push_back(v[i + 1 + m]);
    s.push_back(v[i + m]);
    s.push_back(v[i - 1 + m]);
    s.push_back(v[i - 1]);
    s.push_back(v[i - 1 - m]);
    s.push_back(v[i - m]);
    s.push_back(v[i - m + 1]);

    s.push_back(v[i - m + 2]);
    s.push_back(v[i + 2]);
    s.push_back(v[i + m + 2]);
    s.push_back(v[i + 2*m + 2]);
    s.push_back(v[i + 2*m + 1]);
    s.push_back(v[i + 2*m]);
    s.push_back(v[i + 2*m - 1]);
    s.push_back(v[i + 2*m - 2]);
    s.push_back(v[i + m - 2]);
    s.push_back(v[i - 2]);
    s.push_back(v[i - m - 2]);
    s.push_back(v[i - 2*m - 2]);
    s.push_back(v[i - 2*m - 1]);
    s.push_back(v[i - 2*m]);
    s.push_back(v[i - 2*m + 1]);
    s.push_back(v[i - 2*m + 2]);

    s.push_back(v[i - 2*m + 3]);
    s.push_back(v[i - m + 3]);
    s.push_back(v[i + 3]);
    s.push_back(v[i + m + 3]);
    s.push_back(v[i + 2*m + 3]);
    s.push_back(v[i + 3*m + 3]);
    s.push_back(v[i + 3*m + 2]);
    s.push_back(v[i + 3*m + 1]);
    s.push_back(v[i + 3*m]);
    s.push_back(v[i + 3*m - 1]);
    s.push_back(v[i + 3*m - 2]);
    s.push_back(v[i + 3*m - 3]);
    s.push_back(v[i + 2*m - 3]);
    s.push_back(v[i + m - 3]);
    s.push_back(v[i - 3]);
    s.push_back(v[i - m - 3]);
    s.push_back(v[i - 2*m - 3]);
    s.push_back(v[i - 3*m - 3]);
    s.push_back(v[i - 3*m - 2]);
    s.push_back(v[i - 3*m - 1]);
    s.push_back(v[i - 3*m]);
    s.push_back(v[i - 3*m + 1]);
    s.push_back(v[i - 3*m + 2]);
    s.push_back(v[i - 3*m + 3]);
  }
  return s;
}

void print(const std::vector<int>& s) {
  for (auto it = s.begin(); it != s.end(); ++it) std::cout << *it << ' ';
  std::cout << std::endl;
}

int main() {
  auto v = fillArray(7);
  auto s = solve(v, 7);
  std::vector<int> e = {25, 26, 33, 32, 31, 24, 17, 18, 19, 20, 27, 34, 41, 40, 39, 38, 37, 30, 23, 16, 9, 10, 11, 12, 13, 14, 21, 28, 35, 42, 49, 48, 47, 46, 45, 44, 43, 36, 29, 22, 15, 8, 1, 2, 3, 4, 5, 6, 7};
  if (e == s) {
    std::cout << "SUCCESS\n";
  } else {
    std::cout << "ERROR\n" << std::endl;
    print(s);
  }
  return 0;
}

