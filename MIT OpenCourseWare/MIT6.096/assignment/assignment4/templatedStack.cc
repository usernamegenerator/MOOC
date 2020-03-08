#include <iostream>
#include <vector>

template <typename T>
class Stack{
private:
    std::vector<T> items;
public:
    bool isEmpty() const {return items.empty();}
    void push(const T &item) {items.push_back(item);}
    T pop()
    {
        if(isEmpty())
            return NULL;
        T last = items.back();
        items.pop_back();
        return last;
    }
    void print()
    {
        for(typename std::vector<T>::iterator it = items.begin(); it!=items.end(); it++)
        {
            std::cout << *it;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();
    s.print();
}
