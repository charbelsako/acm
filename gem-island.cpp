#include <iostream>
#include <string>

using namespace std;

int ctoi(char c);

int main()
{
  int n, d, r;
  // get the input as a single line
  string input;
  getline(cin, input);

  cout << input << endl;
  n = ctoi(input[0]);
  d = ctoi(input[2]);
  r = ctoi(input[4]);

  return 0;
}

int ctoi(char c)
{
  return (int)c - 48;
}