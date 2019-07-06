#include <iostream>
#include <string>

using namespace std;

const char space = ' ';

int main()
{
  string paragraph;
  string line;

  //get the input
  // the number of words
  int n;
  cin >> n;

  // the text
  while (getline(cin, line))
  {
    paragraph += line;
  }

  int longest_index = 0;
  int longest_length = 0;

  // the line width
  int line_width = 10;

  // determine the longest river.
  // loop over the text.
  // find a space
  // store the index
  //    repeat until it is not a space.
  //        move by line_width, line_width+1, line_width-1
  //        check if that is a space
  //        if it is inc length by 1
  // then continue on with rest of the paragraph

  // temp variables for longest_length / index
  // for loop
  //    if to find a space
  //        set temp_index = cur_index
  //        nested for/while loop from current index and inc by line_width
  //            if a consecutive space is found inc temp_length by 1
  //    if temp length is greater than longest_length update longest length

  cout << paragraph;
  return 0;
}