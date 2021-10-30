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
	m_upper(lower),
	m_lower(lower)
{
	//recalculate upper vertexes
	Vertex upperVertices[3];
	upperVertices[2] = lower.getVertex(2);

	const auto lowerHeight = lower.getHeigt();
	upperVertices[0] = Vertex(lower.getVertex(0).m_col,
		lower.getVertex(0).m_row + 2 * lowerHeight);

	upperVertices[1] = Vertex(lower.getVertex(1).m_col,
		lower.getVertex(0).m_row + 2 * lowerHeight);
	
	m_upper = Triangle(upperVertices);
}

double Hourglass::getLength() const
{
	return m_lower.getLength();
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
	const auto bottomLeft = m_lower.getVertex(1).isToTheRightOf(m_lower.getVertex(0)) ?
									m_lower.getVertex(0) :
									m_lower.getVertex(1);
	const auto topRight = m_upper.getVertex(1).isToTheRightOf(m_lower.getVertex(0)) ?
									m_upper.getVertex(1) :
									m_upper.getVertex(0);
	
	return Rectangle(bottomLeft, topRight);
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
	if (factor <= 0)
		return false;

	const auto center = m_lower.getVertex(2);

	//new vertexes for lower triangle
	Vertex lower[3];
	lower[0] = m_lower.getVertex(0);
	lower[1] = m_lower.getVertex(1);
	lower[2] = center;
	
	if (!lower[0].scaleFromVertex(factor, center) ||
		!lower[1].scaleFromVertex(factor, center))
		return false;
	
	//new vertexes for upper triangle
	Vertex upper[3];
	upper[0] = m_upper.getVertex(0);
	upper[1] = m_upper.getVertex(1);
	upper[2] = center;
	
	if (!upper[0].scaleFromVertex(factor, center) ||
		!upper[1].scaleFromVertex(factor, center))
		return false;

	m_lower = Triangle(lower);
	m_upper = Triangle(upper);
	
	return true;
}