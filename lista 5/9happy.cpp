#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

class Point {
    public:
    int x;
    int y;

    Point(int a, int b){
        x = a;
        y = b;
    }
    Point(){}

    bool operator==(Point other) {
        return (x == other.x && y == other.y);
    }

    void print(){
        cout << x << " " << y << "\n";
    }
};

class Pointvector{
    public:
    Point* vec;
    int size;
    int maxsize;

    Pointvector(){
        vec = new Point[1];
        size = 0;
        maxsize = 1;
    }

    void push(Point item){
        if (size==maxsize){
            Point* arr = new Point[2*size];
            for (int i=0; i<size; i++){
                arr[i] = vec[i];
            }
            maxsize *= 2;
            vec = arr;
        }
        vec[size] = item;
        size++;
    }
    void push(Point item, int index){
        if (index>=maxsize){
            Point* arr = new Point[2*index];
            for (int i=0; i<size; i++){
                arr[i] = vec[i];
            }
            maxsize = 2*index;
            vec = arr;
        }
        vec[index] = item;
        
    }
    Point access(int i){
        return vec[i];
    }
    void swap(int i, int j){
        Point temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }
    Point& operator[](int a) {
        return vec[a];
    }
    void pop(){
        size--;
    }
    void print(){
        for (int i=0; i<size; i++){
            vec[i].print();
        }
    }
};

int clockwise(Point a, Point b, Point c){
     int area = ( (b.x - a.x) * (c.y - b.y) ) -
                ( (b.y - a.y) * (c.x - b.x) );

     if (area<0) return (+1);
     if (area>0) return (-1);

     return (0);
}

int sqdist(Point a, Point b){
    return (a.x - b.x) * (a.x - b.x) +
           (a.y - b.y) * (a.y - b.y);
}

Point comparison(Point a, Point b, Point c){
    int temp = clockwise(a, b, c); 
    if (temp== +1){
        return c;
    }
    if (temp== -1){
        return b;
    }
    else {
        if ( sqdist(a, b) > sqdist(a, c) ) 
                return b;            
        else return c;
    }
}

Point lowestpoint(Pointvector pts){
    
    Point pt = pts[0];
    for (int i = 1; i< pts.size; i++){
        if (pt.y > pts[i].y) 
            pt = pts[i];
        
        if (pt.y == pts[i].y)
            if (pt.x > pts[i].x) 
                pt = pts[i];   
    }
    return pt;
}

Pointvector jarvis(Pointvector pts){
    Pointvector hull;

    hull.push(lowestpoint(pts));
    
    int i = 1;
    while (1){
            hull.push(pts[i-1]);
        for (int j=0; j<pts.size; j++){
            hull[i] = comparison(hull[i-1], hull[i], pts[j]);
        }
        if (hull[0]==hull[i]) {
            hull.pop();
            break;
        }
        i++;
    }
    return hull;
}

int main(){
    while (true){
        int x[5], y[5];

        for (int i = 0; i < 5; i++)
            cin >> x[i] >> y[i];
        
        if (x[0]==y[0] && x[1]==y[1] && x[0]==x[1] )
            break;

        for (int i = 0; i < 5; i++){
            for (int k = 0; k<5; k++){
                if (i==k) continue;

            }
        }
    }
    return 0;
}