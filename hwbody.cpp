#include<iostream>
using namespace std;

class Body 
{
   friend ostream& operator<<(ostream& out, Body& bd);
   private: 
   string name;
   long x,y,z;
   long mass;
   long radius;

   public:
   Body(string, long, int, int, int, long);
   
};


Body::Body(string name, long mass, int x, int y, int z, long radius)
{
	this->name = name;
	this->mass = mass;
        this->x = x;
	this->y = y;
	this->z = z;
	this->radius = radius;
}

ostream& operator<<(ostream& out, Body& bd)
{
   out<<bd.name<<" "<<bd.mass<<" "<<bd.x<<" "<<bd.y<<" "<<bd.z<<" "<<bd.radius;

}

int main() 
{
	//         name      mass(kg) x y z  radius (m)
	Body earth("earth", 5.972e24, 0,0,0, 6.371e6);
	Body moon("moon",   7.34767309e22, 384.400e6,0,0,  1.737e6);
	cout << earth << '\n';
	cout << moon << '\n';
}
