#include <iostream>
#include <istream>
#include <string>

using namespace std;

int num_words(string str);
void add_commas(string str);
void get_words(int i, string str);
// adds a comma before or after (where) a give `word` in a `paragraph`
void add_commas_to(string &paragraph, string word, char where);

int main(void)
{
    string paragraph;
    // get a string (min-length: 2) from the user
    do
    {
        getline(cin, paragraph);
    } while (paragraph.length() < 2);

    // need to store a copy to manipulate it.
    string paragraph_copy = paragraph;

    // Number of words in the paragraph
    int len = num_words(paragraph);

    add_commas(paragraph);

    return 0;
}

int num_words(string str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' || (str[i] == '.' && str[i + 1] == ' '))
        {
            len++;
        }
    }

    return len;
}

void add_commas(string paragraph)
{
    for (int i = 0, n = paragraph.length(); i < n; i++)
    {
        if (paragraph[i] == ',')
        {
            // get the before and after words.
            get_words(i, paragraph);
        }
    }
}

void get_words(int i, string str)
{
    // or store results in global array with not duplicates.

    int j = i;
    while (str[j - 1] != ' ' && (j - 1) != -1)
    {
        j--;
    }
    // make a variable for it
    string prev;
    // get the previous word
    for (int k = j; k < i; k++)
    {
        prev.push_back(str[k]);
    }
    add_commas_to(str, prev, 'a');

    // store into global array;
    // TODO

    // get the next word
    int end = i + 1;
    while (str[end + 1] != ' ' && str[end + 1] != '.')
    {
        end++;
    }
    // next word variable
    string next;
    for (int k = i + 2; k < end + 1; k++)
    {
        next.push_back(str[k]);
    }
    add_commas_to(str, next, 'b');
    // store into global array;
    // TODO
    cout << str << endl;
}

void add_commas_to(string &paragraph, string word, char where)
{
    size_t found = paragraph.find(word);

    while (found != -1 && found < paragraph.length() - word.length())
    {
        // cout << "found " << word << " at: " << found << '\n';
        // cout << found + word.length() << " " << paragraph.length() << endl;
        if (where == 'b')
        {
            if (paragraph[found - 2] != ',' && paragraph[found - 2] != '.')
            {
                paragraph.insert(found - 1, ",");
                // cout << "inserting at " << found + word.length() << endl;
            }
        }
        else if (where == 'a')
        {
            if (paragraph[found + word.length()] != ',' && paragraph[found + word.length()] != '.')
            {
                paragraph.insert(found + word.length(), ",");
                // cout << "inserting at " << found + word.length() << endl;
            }
        }

        found = paragraph.find(word, found + word.length());
        // cout << paragraph << endl;
    }

    // cout << paragraph << endl;
    // return paragraph;
}