#ifndef __NEXTANAGRAM__HXX__
#define __NEXTANAGRAM__HXX__

#include <queue>
#include <stack>

// -------------------------------------------------------------------------
template <class TList>
TList NextAnagram(const TList &lst)
{
  // Get contained type
  typedef typename TList::value_type TValue;

  // Used variables
  std::queue<TValue> q;
  std::stack<TValue> s;
  TList res;
  TValue pivot, v_aux, last_v;
  bool finished;
  typename TList::const_iterator lIt;
  typename TList::reverse_iterator rIt;

  // 1. Stack the input values
  /** TODO #1 **/
  for (int i = 0; i < lst.size(); i++)
  {
    s.push(lst[i]);
  }

  // 2. Try to find a pivot
  finished = false;
  v_aux = s.top();
  s.pop();
  do
  {
    q.push(v_aux);
    last_v = v_aux;
    if (s.empty())
    {
      finished = true;
      break;
    }
    else
    {
      // 2.1 Pop value from stack and store it into 'v_aux'
      /** TODO #2 **/
      for (int i = 0; i < lst.size(); i++)
        s.push(lst[i]);

      while (!s.empty())
      {
        v_aux += s.top();
        s.pop();
      }

    } // fi

  } while (v_aux > last_v);

  // 2.5. if pivot has been found...
  if (!finished)
  {
    pivot = v_aux;

    // 3. Find a value just below pivot
    /** TODO #3 **/

    q.back() -= q.front();
  }
  while (!q.empty())
  {
    for (int i = 0; i < q.size(); i++)
    {
      
        pivot += q.front();
        q.pop();
      
    }
  }
  // 4. Put it into stack
  s.push(v_aux);

  // 5. Put pivot back to queue

  q.push(pivot);

  // 6. Find the value just above pivot
  /** TODO #4 **/

  if (q.empty() > pivot)
  {
    q.back() -= q.front();
  }

  // 7. Put it into stack
  s.push(v_aux);
  // 8. Finish filling the stack by emptying the queue
  /** TODO #5 **/
  while (!s.empty())
  {
    q.pop();
  }

  // 9. Fill the final answer in reverse order by emptying the stack
  /** TODO #6 **/
  std::queue<TValue> q;
  std::stack<TValue> s;
  while (!s.begin())
  {
    s.pop();
  }
  // 10. Return
  return (res);

} // fi

#endif

// -------------------------------------------------------------------------
template <class TList>
unsigned long ComputeNumberOfAnagrams(const TList &lst)
{
  /** TODO #7 **/
  return 0;
}

// __NEXTANAGRAM__HXX__

// eof - NextAnagram.hxx