#ifndef __NEXTANAGRAM__HXX__
#define __NEXTANAGRAM__HXX__

#include <queue>
#include <stack>
#include <iostream>

using namespace std;
// -------------------------------------------------------------------------
template <class TList>
TList NextAnagram(int lst)
{
  // Get contained type
  typedef typename TList::value_type TValue;

  // Used variables
  queue<TValue> q;
  stack<TValue> s;
  TList res;
  TValue pivot, v_aux, last_v;
  bool finished;
  typename TList::const_iterator lIt;
  typename TList::reverse_iterator rIt;

  // 1. Stack the input values
  /** TODO #1 **/

  cout <<lst;

  // 10. Return
  return (res);
}

// -------------------------------------------------------------------------
template <class TList>
unsigned long ComputeNumberOfAnagrams(const TList &lst)
{
  /** TODO #7 **/
  return 0;
}

#endif // __NEXTANAGRAM__HXX__

// eof - NextAnagram.hxx
