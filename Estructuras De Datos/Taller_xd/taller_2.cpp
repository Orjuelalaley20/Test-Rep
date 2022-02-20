#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int>Vec;
    vector<int>::iterator ptr;
    vector<int>::reverse_iterator rptr;
    deque<int>Dec;
    deque<int>::iterator ptrd;
    deque<int>::reverse_iterator rptrd;
    list<int>List;
    list<int>::iterator ptrl;
    list<int>::reverse_iterator rptrl;

    int a = 0;
    srand(time(NULL));
    for (int i = 0; i < 25; i++)
    {
        a = rand();
        Vec.push_back(a);
    }
    for (int i = 0; i < 30; i++)
    {
        a = rand();
        Dec.push_back(a);
        List.push_back(a);
    }

    // right order 

    cout << "The vector elements are : \n";
    for (ptr = Vec.begin(); ptr < Vec.end(); ptr++)
        cout << *ptr << " \n";

    cout << "The deque elements are : \n";
    for (ptrd = Dec.begin(); ptrd < Dec.end(); ptrd++)
        cout << *ptrd << " \n";

    cout << "The list elements are : \n";
    for (ptrl = List.begin(); ptrl != List.end(); ptrl++)
    {
        cout << *ptrl << " \n";
    }

    //reverse order

    cout << "Vector in reverse order : \n";
    for (rptr = Vec.rbegin(); rptr != Vec.rend(); rptr++)
    {
        cout << *rptr << " \n";
    }
    cout << "Deque in reverse order : \n";
    for (rptrd = Dec.rbegin(); rptrd != Dec.rend(); rptrd++)
    {
        cout << *rptrd << " \n";
    }
    cout << "List in reverse order : \n";
    for (rptrl = List.rbegin(); rptrl != List.rend(); rptrl++)
    {
        cout << *rptrl << " \n";
    }

    //insert a random number in the 18 position in the Vector
    a = rand();
    Vec.insert(Vec.begin()+17,a);
    //insert a random number in the 18 position in the Deque
    a = rand();
    Dec.insert(Dec.begin()+17,a);
    //insert a random number in the 18 position in the List
    ptrl = List.begin();
    advance(ptrl, 17);
    a = rand();
    List.insert(ptrl,a);

    //delete data at position 5 and 10 and print again the normal way at the vector
    Vec.erase(Vec.begin()+4);
    Vec.erase(Vec.begin()+9);
    cout << "The vector elements are : \n";
    for (ptr = Vec.begin(); ptr < Vec.end(); ptr++)
        cout << *ptr << " \n";
    //delete data at position 5 and 10 and print again the normal way at the Deque
    Dec.erase(Dec.begin()+4);
    Dec.erase(Dec.begin()+9);
    cout << "The deque elements are : \n";
    for (ptrd = Dec.begin(); ptrd < Dec.end(); ptrd++)
        cout << *ptrd << " \n";
    //delete data at position 5 and 10 and print again the normal way at the List
    ptrl = List.begin();
    advance(ptrl, 4);
    List.erase(ptrl);
    ptrl = List.begin();
    advance(ptrl, 9);
    List.erase(ptrl);
    cout << "The list elements are : \n";
    for (ptrl = List.begin(); ptrl != List.end(); ptrl++)
    {
        cout << *ptrl << " \n";
    }
    return 0;
}