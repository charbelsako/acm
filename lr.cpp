#include <iostream>
#include <string>

using namespace std;

int get_longest_word(string paragraph);
string trim_text(string paragraph, int line_width);

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
    if (paragraph.length() > n)
    {
      break;
    }
    if (paragraph.empty())
    {
      paragraph += line;
    }
    else
    {
      paragraph += " " + line;
    }
  }

  paragraph.push_back('.');

  int longest_index = 0;
  int longest_length = 0;

  // the line width. minimum value is longest word in text
  int line_width = 10;

  // preprocess the input
  string copy = trim_text(paragraph, line_width);

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
  int temp_length;
  int temp_index;
  for (int i = 0; i < n; i++)
  {
    if (paragraph[i] == space)
    {
      int temp_index = i;
      //        nested for/while loop from current index and inc by line_width
      //            if a consecutive space is found inc temp_length by 1
      //    if temp length is greater than longest_length update longest length
    }
  }
  // cout << paragraph;
  return 0;
}

string trim_text(string paragraph, int line_width)
{
  int j = 0;
  for (int i = 0, n = paragraph.length(); i < n; i++)
  {
    if (paragraph.find(" ", i + 1) - i + j > line_width)
    {
      cout << endl;
      if (paragraph[i] == space)
      {
        paragraph.replace(i, 1, "");
      }
      j = 0;
    }
    if (j >= line_width)
    {
      cout << endl;
      if (paragraph[i] == space)
      {
        paragraph.replace(i, 1, "");
      }
      j = 0;
    }
    j++;
    cout << paragraph[i];
  }
}