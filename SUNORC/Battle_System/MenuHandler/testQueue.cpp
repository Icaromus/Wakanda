#include <iostream>
#include <string>
using namespace std;
#include "PriorityQueue.h"



class inty
{
private:
    int val;
public:
    inty(int v)
	:val(v)
    {}
    inty()
    {}

    bool lessThan(inty i)
    {
	return val < i.val;
    }

    friend ostream & operator << (ostream & out, const inty & i)
    {
	out << i.val << endl;
	return out;
    }
};
int main()
{
    PriorityQueue<inty> q(5);
    inty i1(1);
    inty i2(2);
    inty i3(3);
    inty i4(4);
    inty i5(5);
    q.insert(i4);
    q.insert(i5);
    q.insert(i2);
    q.insert(i1);
    q.insert(i3); 
    cout << q << endl;
    return 0;
}










