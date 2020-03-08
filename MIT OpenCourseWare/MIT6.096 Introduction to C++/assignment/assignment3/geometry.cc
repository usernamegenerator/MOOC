#include <iostream>
#include <cstdlib>
#include <cmath>
#include "geometry.h"

using namespace std;

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(const int new_x)
{
    x = new_x;
}


void Point::setY(const int new_y)
{
    y = new_y;
}


PointArray::PointArray()
{
    arraySize = 0;
    pointer = new Point[0];
}
PointArray::PointArray(const Point points[], const int Size)
{
    arraySize = Size;
    pointer = new Point[arraySize];
    for(int i = 0; i < arraySize; i++)
    {
        pointer[i] = points[i];
    }
}
PointArray::PointArray(const PointArray& pv)
{
    arraySize = pv.arraySize;
    pointer = new Point[arraySize];
    for(int i = 0; i < arraySize; i++)
    {
        pointer[i] = pv.pointer[i];
    }
}

PointArray::~PointArray()
{
    delete[] pointer;
}

void PointArray::reSize(int n)
{
    Point *tempP = new Point[n];
    int minSize = (n > arraySize) ? arraySize : n;
    for(int i = 0; i < minSize ; i++)
    {
        tempP[i] = pointer[i];
    }

    delete[] pointer;

    arraySize = n;
    pointer = tempP;
}

void PointArray::Push_Back(const Point & p)
{
    reSize(arraySize+1);
    pointer[arraySize-1] = p;
    cout << "<Push_Back> " <<  "(" << pointer[arraySize-1].getX() << "," << pointer[arraySize-1].getY() << ")"<< endl;
}


//position is the natural count start from 1
//so index of the array = position - 1
void PointArray::Insert(const int position, const Point & p)
{
    if(position > arraySize + 1 || position < 1)
    {
        cout << "invalid insert" << endl;
        return;
    }

    reSize(arraySize+1);

    for(int i = arraySize-1; i >= position ;i--)
    {
        pointer[i] = pointer[i-1];
    }

    pointer[position-1] = p;
    cout << "<Insert> position "  <<  position <<  ": (" << pointer[position-1].getX() << "," << pointer[position-1].getY() << ")"<< endl;

}

//position is the natural count start from 1
//so index of the array = position - 1
void PointArray::Remove(const int pos)
{
    if(pos>arraySize)
    {
        cout << "no such pos" << endl;
        return;
    }
    cout << "<Remove> " <<  "(" << pointer[pos-1].getX() << "," << pointer[pos-1].getY() << ")"<< endl;
    for(int i = pos-1; i<arraySize-1;i++)
    {
        pointer[i] = pointer[i+1];
    }
    reSize(arraySize-1);
}
int PointArray::getSize() const
{
    return arraySize;
}
void PointArray::Clear()
{
    cout << "<Clear>" << endl;
    reSize(0);
}
Point* PointArray::get(const int pos)
{
    if(pos>0 && pos<=arraySize)
        return &pointer[pos-1];
    else
    {
        cout << "no such pos1" << endl;
        return NULL;
    }


}
const Point* PointArray::get(const int pos) const
{
    if(pos>0 && pos<=arraySize)
        return &pointer[pos-1];
    else
    {
        cout << "no such pos2" << endl;
        return NULL;
    }

}

void PointArray::printAll()
{
    cout << "<printAll> ";
    if(arraySize==0)
    {
        cout << "empty" << endl;
        return;
    }
    cout << "size=" << arraySize << ": ";
    for(int i = 0; i< arraySize ;i++)
    {
        cout << "(" << pointer[i].getX() << "," << pointer[i].getY() <<  ")";
    }

    cout << endl;
}


Point constuctorPoints[4];

Point *updateConstructorPoints(const Point& p1, const Point& p2, const Point& p3, const Point& p4 = Point(0,0) ){
    constuctorPoints[0] = p1;
    constuctorPoints[1] = p2;
    constuctorPoints[2] = p3;
    constuctorPoints[3] = p4;
    return constuctorPoints;
}

int Polygon::numOfPolygons = 0 ;
Rectangle::Rectangle(const Point &a,const Point &b): Polygon(updateConstructorPoints(Point(b.getX(),a.getY()),b,a,Point(a.getX(),b.getY())),4){}
//a = x of left, b = x of right
//c= y of upper, d = y of lower
Rectangle::Rectangle(const int a,const int b,const  int c ,const  int d):Polygon(updateConstructorPoints(Point(a,c),Point(b,c),Point(a,d),Point(d,d)),4){}

double Rectangle::area()
{
     return (abs(points.get(2)->getY() - points.get(1)->getY()) * abs(points.get(3)->getX()-points.get(1)->getX()));
}


Triangle::Triangle(const Point& a, const Point& b, const Point& c): Polygon(updateConstructorPoints(a,b,c),3){};

double Triangle::area()
{
    double deltaX01 = points.get(1)->getX() - points.get(2)->getX();
    double deltaX02 = points.get(1)->getX() - points.get(3)->getX();
    double deltaX12 = points.get(2)->getX() - points.get(3)->getX();

    double deltaY01 = points.get(1)->getY() - points.get(2)->getY();
    double deltaY02 = points.get(1)->getY() - points.get(3)->getY();
    double deltaY12 = points.get(2)->getY() - points.get(3)->getY();

    double a = sqrt(deltaX01*deltaX01 + deltaY01*deltaY01);
    double b = sqrt(deltaX02*deltaX02 + deltaY02*deltaY02);
    double c = sqrt(deltaX12*deltaX12 + deltaY12*deltaY12);

    double s = (a+b+c)/2;

    return (sqrt(s*(s-a)*(s-b)*(s-c)));
}




void testPointArray()
{

    //test Point
    Point p;
    //cout << p.getX() << endl;
    Point q(1,2);
    //cout << q.getX() << endl;

    //test PointArray
    Point pa[5] = {p,q,Point(2,3),Point(3,4),Point(4,5)};
    PointArray *pa1 = new PointArray(pa,5);
    pa1->printAll();
    pa1->Clear();
    pa1->printAll();
    pa1->Push_Back(Point(5,6));
    pa1->printAll();
    pa1->Push_Back(Point(6,7));
    pa1->printAll();
    pa1->Push_Back(Point(7,8));
    pa1->printAll();
    pa1->Insert(pa1->getSize()+1,Point(9,10));
    pa1->printAll();
    pa1->Insert(pa1->getSize()+1,Point(10,11));
    pa1->printAll();
    pa1->Insert(pa1->getSize() + 2 , Point(99,99));
    pa1->printAll();
    pa1->Insert(1,p);
    pa1->printAll();
    pa1->Insert(3,p);
    pa1->printAll();
    pa1->Remove(3);
    pa1->printAll();
    pa1->Remove(1);
    pa1->printAll();
    pa1->Remove(pa1->getSize());
    pa1->printAll();
    pa1->Remove(pa1->getSize()+1);
    pa1->printAll();
    cout << pa1->get(pa1->getSize())->getX() << "," << pa1->get(pa1->getSize())->getY() << endl;
    cout << pa1->get(1)->getX() << "," << pa1->get(1)->getY() << endl;
    cout << pa1->get(8)->getX() << "," << pa1->get(8)->getY() << endl;

}


void printAttribute(Polygon * polygon)
{
    cout << "area: " << polygon->area() << endl;
    int numOfPoints = polygon->getNumSides();
    cout << numOfPoints << endl;
    for(int i = 1; i <= numOfPoints; i++)
    {
        cout << "(" << polygon->pa()->get(i)->getX() << "," << polygon->pa()->get(i)->getY() << ")" << endl;
    }

}

int main()
{
    //testPointArray();
    int lowerleftRectangleX;
    int lowerleftRectangleY;
    int upperrightRectangleX;
    int upperrightRectangleY;
    int point1TriangleX;
    int point2TriangleX;
    int point3TriangleX;
    int point1TriangleY;
    int point2TriangleY;
    int point3TriangleY;

    cout << "input lower left for Rectangle" << endl;
    cin >> lowerleftRectangleX;
    cin >> lowerleftRectangleY;

    cout << "input upper right for Rectangle" << endl;
    cin >> upperrightRectangleX;
    cin >> upperrightRectangleY;

    cout << "input point 1 x and y for triangle" << endl;
    cin >> point1TriangleX;
    cin >> point1TriangleY;

    cout << "input point 2 x and y for triangle" << endl;
    cin >> point2TriangleX;
    cin >> point2TriangleY ;

    cout << "input point 3 x and y for triangle" << endl;
    cin >> point3TriangleX;
    cin >> point3TriangleY;

    Polygon * newRectangle = new Rectangle(Point(lowerleftRectangleX,lowerleftRectangleY),Point(upperrightRectangleX,upperrightRectangleY));
    Polygon * newTriangle = new Triangle(Point(point1TriangleX,point1TriangleY),Point(point2TriangleX,point2TriangleY),Point(point3TriangleX,point3TriangleY));
    printAttribute(newRectangle);
    printAttribute(newTriangle);




    return 0;
}
