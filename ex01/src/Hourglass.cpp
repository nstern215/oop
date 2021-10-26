#include "Hourglass.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Vertex.h"

//why this ctor requires a default ctor for Triangle?
Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
{
	
}
Hourglass::Hourglass(const Triangle& lower)
{
	
}

double Hourglass::getLength() const
{
	return 1;
}
double Hourglass::getHeight() const
{
	return 1;
}

void Hourglass::draw(Board& board) const
{
	
}

Rectangle Hourglass::getBoundingRectangle() const
{
	return Rectangle(1, 1, 2, 2);
}

double Hourglass::getArea() const
{
	return 8;
}

double Hourglass::getPerimeter() const
{
	return 8;
}

Vertex Hourglass::getCenter() const
{
	Vertex v;
	v.m_row = 1;
	v.m_col = 1;

	return v;
}

bool Hourglass::scale(double factor)
{
	return true;
}