#include "Hourglass.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Vertex.h"

//why this ctor requires a default ctor for Triangle?
Hourglass::Hourglass(const Triangle& upper, const Triangle& lower):
	m_upper(upper),
	m_lower(lower)
{
}

Hourglass::Hourglass(const Triangle& lower):
	m_lower(lower),
	m_upper(lower)
{
	//recalculate upper vertexes
	m_upper = Triangle(m_lower.getVertex(0), m_lower.getVertex(1), -m_lower.getHeigt());
}

double Hourglass::getLength() const
{
	return 1;
}
double Hourglass::getHeight() const
{
	//both triangles are equal than the height of the hourglass
	//is two times the height of one of the triangles
	return m_upper.getHeigt() * 2;
}

void Hourglass::draw(Board& board) const
{
	m_lower.draw(board);
	m_upper.draw(board);
}

Rectangle Hourglass::getBoundingRectangle() const
{
	return Rectangle(1, 1, 2, 2);
}

double Hourglass::getArea() const
{
	return m_upper.getArea() * 2;
}

double Hourglass::getPerimeter() const
{
	return m_upper.getPerimeter() * 2;
}

Vertex Hourglass::getCenter() const
{
	return m_upper.getVertex(2);
}

bool Hourglass::scale(double factor)
{
	return true;
}