#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> v1 = {1, 6, 80, 10, 5};
    cout << "Vector v1 : " << v1.at(1) << endl;

    vector<int> v;
    cout << "Vector v capacity : " << v.capacity() << endl;

    v.push_back(10);
    v.push_back(15);
    v.push_back(5);
    cout << "Vector v capacity after 3 push back : " << v.capacity() << endl;
    cout << "Vector v size after 3 push back : " << v.size() << endl;

    v.pop_back();
    cout << "Vector v capacity after 1 pop back : " << v.capacity() << endl;
    cout << "Vector v size after 1 pop back : " << v.size() << endl;

    cout << "Vector v front : " << v.front() << endl;
    cout << "Vector v back : " << v.back() << endl;

    v.clear();
    cout << "Vector v after clear capacity : " << v.capacity() << endl;
    cout << "Vector v after clear size : " << v.size() << endl;

    cout << "Vector v1 : ";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    v.push_back(100);
    v.push_back(150);
    v.push_back(50);
    cout << "Vector v : ";
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    // v2(size, to be initialize with)
    vector<int> v2(5, 10);
    cout << "Vector v2 : ";
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;

    // Copying the vector v1 in a new vector copyVector
    vector<int> copyVector(v1);
    cout << "Vector copyvector : ";
    for (int i = 0; i < copyVector.size(); i++)
    {
        cout << copyVector[i] << " ";
    }
    cout << endl;
}