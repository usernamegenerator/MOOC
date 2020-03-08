
class Point{
private:
    int x;
    int y;
public:
    Point():x(0),y(0){}
    Point(int x,int y):x(x),y(y){}
    int getX() const;
    int getY() const;
    void setX(const int new_x);
    void setY(const int new_y);
};


class PointArray{
private:
    Point* pointer;
    int arraySize;
    void reSize(int n);
public:
    PointArray();
    PointArray(const Point points[], const int Size);
    PointArray(const PointArray& pv);
    ~PointArray();

    void Push_Back(const Point & p);
    void Insert(const int position, const Point & p);
    void Remove(const int pos);
    int getSize() const;
    void Clear();
    Point* get(const int pos);
    const Point* get(const int pos) const;
    void printAll();
};


class Polygon{
protected:
    static int numOfPolygons;
    PointArray points;
public:
    Polygon(Point arrOfPoints[], int length):points(arrOfPoints,length){
        numOfPolygons++;
    }
    Polygon(PointArray &new_pa):points(new_pa){
        numOfPolygons++;
    }
    ~Polygon() {--numOfPolygons;}

    virtual double area() = 0;

    int getNumPolygons() {return numOfPolygons;}

    int getNumSides(){return points.getSize();}

    const PointArray* pa() const {return &points;}
};


class Rectangle: public Polygon{
public:
    Rectangle(const Point &a,const Point &b);
    Rectangle(const int a,const  int b,const  int c ,const  int d);

    virtual double area();
};


class Triangle: public Polygon{
public:
    Triangle(const Point& a, const Point& b, const Point& c);
    virtual double area();
};
