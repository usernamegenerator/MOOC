#include <iostream>

class Base1{
public:
    Base1(){ std::cout << "Base1()\n";}
    ~Base1(){ std::cout << "~Base1()\n";}
};

class Derived1: public Base1{
public:
	Derived1(){std::cout << "Derived1()\n";}
	~Derived1(){std::cout << "~Derived1()\n";}
};


/*
when you refer to a derived class object using a pointer
or a reference to the base class, you can call a virtual function
for that object and execute the derived class's version of the function
*/
class Base2{
public:
    Base2(){std::cout << "Base2()\n";}
	virtual ~Base2(){std::cout << "~Base2()\n";}
};

class Derived2: public Base2{
public:
	Derived2(){std::cout << "Derived2()\n";}
	~Derived2(){std::cout << "~Derived2()\n";}
};

int main()
{
	Base1* bp = new Derived1;
	delete bp;

	Base2* b2p = new Derived2;
	delete b2p;
}


/*
output:

Base1()
Derived1()
~Base1()
Base2()
Derived2()
~Derived2()
~Base2()


*/
