#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>

#include "NextAnagram.h"

using namespace std;

#define MAX_ANAGRAMS 1000

// -------------------------------------------------------------------------
// Lists used in this code
typedef std::vector<char> TCharacterList;
typedef std::vector<std::string> TStringList;

// -------------------------------------------------------------------------
TCharacterList ReadAsCharacterList(istream &input);
TStringList ReadAsStringList(istream &input);

// -------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  // Get a valid input stream
  istream *input = &cin;
  if (argc > 1)
  {
    input = new ifstream(argv[1]);
  }

  if (!(*input))
  {
    cerr << "Error opening input stream." << endl;
    return (-1);

  } // fi

  // Loop over input
  unsigned int line_type;
  do
  {
    // Get complete text line
    string line;
    getline(*input, line);

    // Prepare a simple tokenizer
    stringstream line_stream(line);

    // Get type of data
    line_stream >> line_type;
    if (line_type == 0)
    {
      // String list
      TStringList stringList = ReadAsStringList(line_stream);

      // Compute number of anagrams
      unsigned long nAnagrams = ComputeNumberOfAnagrams(stringList);
      if (nAnagrams >= MAX_ANAGRAMS)
        nAnagrams = MAX_ANAGRAMS;

      // Print all (or at least MAX_ANAGRAMS) anagrams
      for (unsigned long i = 0; i < nAnagrams; ++i)
      {
        copy(stringList.begin(), stringList.end(),ostream_iterator<string>(cout, " : "));
        cout << endl;
        stringList = NextAnagram(stringList);

      } // rof
    }
    else if (line_type == 1)
    {
      // Char list
      TCharacterList charList = ReadAsCharacterList(line_stream);

      // Compute number of anagrams
      unsigned long nAnagrams = ComputeNumberOfAnagrams(charList);
      if (nAnagrams >= MAX_ANAGRAMS)
        nAnagrams = MAX_ANAGRAMS;

      // Print all (or at least MAX_ANAGRAMS) anagrams
      for (unsigned long i = 0; i < nAnagrams; ++i)
      {
        copy(charList.begin(), charList.end(),ostream_iterator<char>(cout, ""));
        cout <<endl;
        charList = NextAnagram(charList);

      } // rof

    } // fi

  } while (line_type != 2);

  // Close input stream, if needed (ie. it wasn't taken from std::cin)
  if (input != &cin)
  {
    dynamic_cast<ifstream *>(input)->close();
    delete input;

  } // fi

  return (0);
}

// -------------------------------------------------------------------------
TCharacterList ReadAsCharacterList(istream &input)
{
  // Prepare output
  TCharacterList lst;

  // Loop over a space separated stream (tokenizer)
  while (!input.eof())
  {
    string str;
    input >> str;

    for (string::const_iterator sIt = str.begin();sIt != str.end();++sIt)
      lst.push_back(*sIt);
  } // elihw

  return (lst);
}

// -------------------------------------------------------------------------
TStringList ReadAsStringList(std::istream &input)
{
  // Prepare output
  TStringList lst;

  // Loop over a space separated stream (tokenizer)
  while (!input.eof())
  {
    std::string str;
    input >> str;
    lst.push_back(str);

  } // elihw

  return (lst);
}

// eof - solve_anagram.cxx
