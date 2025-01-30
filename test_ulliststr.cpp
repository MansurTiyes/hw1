#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

// test case 3 push_back
// 1) Populate ll head node with 10 elements and push 11th item
int main(int argc, char* argv[])
{
    ULListStr ll;
    
    for (int i = 0; i < 10; i++)
    {
        ll.push_back(to_string(i));
        cout <<ll.get(i) << endl;
    }
    ll.push_back("10");
    ll.pop_back();
    
    
    // ll.push_front("-1");
    // cout << ll.get(0) << endl;
    // cout << ll.get(10) << endl;
    // for (int i = 10; i < 20; i++)
    // {
    //     ll.push_back(to_string(i));
    //     cout <<ll.get(i) << endl;
    // }
    // ll.push_back("20");
    // cout << ll.get(20) << endl;
}
