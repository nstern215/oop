#include "Triangle.h"
#include "Rectangle.h"
#include "Vertex.h"
#include "macros.h"

#include <cmath>

Triangle::Triangle(const Vertex vertices[3])
	:m_v0(vertices[0].m_col, vertices[0].m_row),
	m_v1(vertices[1].m_col, vertices[1].m_row),
	m_v2(vertices[2].m_col, vertices[2].m_row)
{
	if(!validateCoordinates(m_v0, m_v1, m_v2))
	{
		m_v0.m_col = vertices[0].m_col;
		m_v0.m_row = vertices[0].m_row;
		m_v1.m_col = vertices[1].m_col;
		m_v1.m_row = vertices[1].m_row;
		m_v2.m_col = vertices[2].m_col;
		m_v2.m_row = vertices[2].m_row;
	}
}

Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
{
	Vertex vertices[3];
	double baseLength = calcDistance(v0, v1);
	Vertex v2;
	v2.m_col = (baseLength / 2) + v0.m_col;
	v2.m_row = v0.m_row + height;

	vertices[0] = v0;
	vertices[1] = v1;
	vertices[2] = v2;
	
	//Triangle(vertices);
}

//??
//Triangle::Triangle()
//{
//	
//}


bool Triangle::validateCoordinates(const Vertex v0, const Vertex v1, const Vertex v2) const
{
	if (!v0.isValid() || !v1.isValid() || !v2.isValid())
		return false;

	if (calcDistance(v0, v1) - calcDistance(v1, v2) > EPSILON)
		return false;

	return checkParallelX(v0, v1);
}

Vertex Triangle::getVertex(int index) const
{
	switch (index)
	{
	case 0:
		return m_v0;
	case 1:
		return m_v1;
	case 2:
		return m_v2;
	default:
		return m_v0;
	}
}

double Triangle::getLength() const
{
	return calcDistance(m_v0, m_v2);
}

double Triangle::getHeigt() const
{
	return m_v1.m_row - m_v0.m_row;
}

void Triangle::draw(Board& board)
{
	board.drawLine(m_v0, m_v1);
	board.drawLine(m_v1, m_v2);
	board.drawLine(m_v0, m_v2);
}

Rectangle Triangle::getBoundingRectangle()
{
	Vertex topRight;
	topRight.m_row = m_v1.m_row;
	topRight.m_col = m_v2.m_col;

	Rectangle bounding(m_v0, topRight);

	return bounding;
}

double Triangle::getArea()
{
	double base = calcDistance(m_v0, m_v2);
	double height = getHeigt();

	return (base * height) / 2;
}

double Triangle::getPerimeter()
{
	return calcDistance(m_v0, m_v1) +
		calcDistance(m_v1, m_v2) +
		calcDistance(m_v0, m_v2);
}

Vertex Triangle::getCenter()
{
	return getBoundingRectangle().getCenter();
}

bool Triangle::scale(double factor)
{
	return true;
}

bool Triangle::checkParallelX(const Vertex v0, const Vertex v1) const
{
	return v0.m_row - v1.m_row <= EPSILON;
}

double Triangle::calcDistance(const Vertex v0, const Vertex v1) const
{
	return sqrt(pow(abs(v0.m_col - v1.m_col), 2) + pow(abs(v0.m_row - v1.m_row), 2));
}