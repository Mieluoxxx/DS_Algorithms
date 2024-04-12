#include <iostream>
using namespace std;

int dfs(int n) {
  int res;
  if (n == 1) {
    res = 1;
  }
  else{
    res = dfs(n-1)+3;
  }
  return res;
}

int main() {
  int sum = dfs(6);
  printf("%d\n", sum);
  return 0;
}
