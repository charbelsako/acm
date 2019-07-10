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
    if (paragraph.empty())
    {
      paragraph += line;
    }
    else
    {
      paragraph += " " + line;
    }
  }

  cout << endl
       << "The real paragraph:" << endl;
  cout << paragraph << endl;

  int longest_index = 0;
  int longest_length = 0;

  // the line width. minimum value is longest word in text
  int line_width = 10;

  // preprocess the input
  string copy = trim_text(paragraph, line_width);

  cout << copy;

  return 0;
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
  for (int i = 0, n = copy.length(); i < n; i++)
  {
    if (copy[i] == space)
    {
      int temp_index = i;
      //        nested for/while loop from current index and inc by line_width
      for (int j = i; i < n; i += line_width)
      {
        if (copy[i] == space || copy[i - 1] == space || copy[i + 1] == space)
        {
          temp_length++;
          if (temp_length > longest_length)
          {
            longest_length = temp_length;
            longest_index = temp_index;
          }
        }
        else
        {
          break;
        }
      }
      //            if a consecutive space is found inc temp_length by 1
      //    if temp length is greater than longest_length update longest length
    }
  }

  cout << longest_index << endl;
  cout << longest_length << endl;

  return 0;
}

string trim_text(string paragraph, int line_width)
{
  bool new_line_space = false;
  string new_paragraph;
  int j = 0;
  for (int i = 0, n = paragraph.length(); i < n; i++)
  {
    size_t in = paragraph.find(" ", i + 1);
    if (in - i + j > line_width)
    {
      new_paragraph.append("n");
      if (paragraph[i] == space)
      {
        new_line_space = true;
      }
      j = 0;
    }
    if (j >= line_width)
    {
      new_paragraph.append("n");
      if (paragraph[i] == space)
      {
        new_line_space = true;
      }
      j = 0;
    }
    j++;
    if (!new_line_space)
    {
      new_paragraph.append(1, paragraph[i]);
    }
  }

  return new_paragraph;
}