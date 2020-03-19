// This file includes 2 different ways of finding occurences of a single word

#include <iostream>
#include <string>

using namespace std;

int main()
{
  // string s;
  // getline(cin, s);
  // auto found = s.find("hello");
  // while (found != -1)
  // {
  //   cout << found << endl;
  //   found = s.find("hello", found + 1);
  // }

  string input;
  int i = 0;
  int cat_occ = 0;

  cout << "Please enter a line of text: ";
  getline(cin, input, '\n');

  for (int i = input.find("cat", 0); i != string::npos; i = input.find("cat", i)) {
    cat_occ++;
    i++;
  }

  cout << "The word cat appears " << cat_occ << " in the string " << endl << '"' << input << '"' << endl;

  return 0;
}