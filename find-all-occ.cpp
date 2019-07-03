#include <iostream>
#include <istream>
#include <string>

using namespace std;

int main()
{
  string s;
  getline(cin, s);
  auto found = s.find("hello");
  while (found != -1)
  {
    cout << found << endl;
    found = s.find("hello", found + 1);
  }

  return 0;
}