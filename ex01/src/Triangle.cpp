#include "Triangle.h"
#include "Rectangle.h"
#include "Vertex.h"
#include <cmath>
#include <iostream>


Triangle::Triangle(const Vertex vertices[3])
	:m_v0(vertices[0].m_col, vertices[0].m_row),
	m_v1(vertices[1].m_col, vertices[1].m_row),
	m_v2(vertices[2].m_col, vertices[2].m_row)
{
	if (!validateCoordinates(m_v0, m_v1, m_v2))
		buildDefaultRectangle();
}

Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height):
	m_v0(v0),
	m_v1(v1)
{
	if (!checkParallelX(v0, v1) || m_v0.m_col - m_v1.m_col < EPSILON)
	{
		buildDefaultRectangle();
		return;
	}

	const auto baseLength = calcDistance(v0, v1);
	
	m_v2.m_col = (baseLength / 2) + v0.m_col;
	m_v2.m_row = v0.m_row + height;

	if (calcDistance(m_v0, m_v2) - calcDistance(m_v1, m_v2) > EPSILON)
		buildDefaultRectangle();
}

bool Triangle::validateCoordinates(const Vertex v0, const Vertex v1, const Vertex v2) const
{
	if (!v0.isValid() || !v1.isValid() || !v2.isValid())
		return false;

	if (calcDistance(v0, v2) - calcDistance(v1, v2) > EPSILON)
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
	return m_v2.m_row - m_v0.m_row;
}

void Triangle::draw(Board& board) const
{
	board.drawLine(m_v0, m_v1);
	board.drawLine(m_v1, m_v2);
	board.drawLine(m_v0, m_v2);
}

Rectangle Triangle::getBoundingRectangle() const
{
	//in case of default coordinates triangle
	if (!checkParallelX(m_v0, m_v1))
	{
		Vertex topRight;
		topRight.m_col = m_v2.m_col;
		topRight.m_row = m_v1.m_row;
		
		return Rectangle(m_v0, topRight);
	}
	
	const auto heigt = getHeigt();
	
	Vertex topRight;
	Vertex bottomLeft;

	bottomLeft.m_col = std::min(m_v0.m_col, m_v1.m_col);
	bottomLeft.m_row = heigt > 0 ? m_v0.m_row : m_v2.m_row;

	topRight.m_col = std::max(m_v0.m_col, m_v1.m_col);
	topRight.m_row = heigt < 0 ? m_v0.m_row : m_v2.m_row;

	return Rectangle(bottomLeft, topRight);
}

double Triangle::getArea() const
{
	double base = calcDistance(m_v0, m_v2);
	double height = getHeigt();

	return (base * height) / 2;
}

double Triangle::getPerimeter() const
{
	return calcDistance(m_v0, m_v1) +
		calcDistance(m_v1, m_v2) +
		calcDistance(m_v0, m_v2);
}

Vertex Triangle::getCenter() const
{
	return getBoundingRectangle().getCenter();
}

bool Triangle::scale(double factor)
{
	if (factor <= 0)
		return false;

	const auto center = getCenter();

	if (m_v0.scaleFromVertex(factor, center) &&
		m_v1.scaleFromVertex(factor, center) &&
		m_v2.scaleFromVertex(factor, center))
		return true;
	
	return false;
}

bool Triangle::checkParallelX(const Vertex v0, const Vertex v1) const
{
	return abs(v0.m_row - v1.m_row) <= EPSILON;
}

double Triangle::calcDistance(const Vertex v0, const Vertex v1) const
{
	return sqrt(pow(v0.m_col - v1.m_col, 2) + pow(v0.m_row - v1.m_row, 2));
}

void Triangle::buildDefaultRectangle()
{
	std::cout << "building default triangle" << std::endl;
	
	m_v0.m_col = DEFAULT_V0_COL;
	m_v0.m_row = DEFAULT_V0_ROW;
	m_v1.m_col = DEFAULT_V1_COL;
	m_v1.m_row = DEFAULT_V1_ROW;
	m_v2.m_col = DEFAULT_V2_COL;
	m_v2.m_row = DEFAULT_V2_ROW;
}
