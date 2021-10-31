#include "Rectangle.h"

Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight) :
	m_bottomLeft(bottomLeft),
	m_topRight(topRight)
{
	if (!bottomLeft.isValid() || !topRight.isValid() 
		|| !topRight.isHigherThan(bottomLeft) || !topRight.isToTheRightOf(bottomLeft))
		buildDefaultRectangle();
}

Rectangle::Rectangle(const Vertex vertices[2])
	: Rectangle(vertices[0], vertices[1])
{
}

Rectangle::Rectangle(double x0, double y0, double x1, double y1) :
	m_bottomLeft(x0, y0),
	m_topRight(x1, y1)
{
	if (!validateCordinates())
		buildDefaultRectangle();
}

Rectangle::Rectangle(const Vertex& start, double width, double height)
	:Rectangle(start.m_col,start.m_row, start.m_col + width, start.m_row + height)
{
}

void Rectangle::draw(Board& board) const
{
	Vertex v2, v4;
	auto v1 = m_bottomLeft;
	
	v2.m_col = m_bottomLeft.m_col;
	v2.m_row = m_topRight.m_row;

	auto v3 = m_topRight;

	v4.m_col = m_topRight.m_col;
	v4.m_row = m_bottomLeft.m_row;

	board.drawLine(v1, v2);
	board.drawLine(v2, v3);
	board.drawLine(v3, v4);
	board.drawLine(v4, v1);
}

Rectangle Rectangle::getBoundingRectangle() const
{
	return Rectangle(m_bottomLeft, m_topRight);
}

double Rectangle::getArea() const
{
	return getHeight() * getWidth();
}

double Rectangle::getPerimeter() const
{
	return getHeight() * 2 + getWidth() * 2;
}

Vertex Rectangle::getCenter() const
{
	const auto center_col = (m_bottomLeft.m_col + m_topRight.m_col) / 2;
	const auto center_row = (m_bottomLeft.m_row + m_topRight.m_row) / 2;

	Vertex center;
	center.m_col = center_col;
	center.m_row = center_row;

	return center;
}

bool Rectangle::scale(double factor)
{
	if (factor <= 0)
		return false;

	Vertex center = getCenter();

	if (m_bottomLeft.scaleFromVertex(factor, center) &&
		m_topRight.scaleFromVertex(factor, center))
		return true;
	
	return false;
}

Vertex Rectangle::getBottomLeft() const
{
	return m_bottomLeft;
}

Vertex Rectangle::getTopRight() const
{
	return m_topRight;
}

double Rectangle::getWidth() const
{
	return m_topRight.m_col - m_bottomLeft.m_col;
}

double Rectangle::getHeight() const
{
	return m_topRight.m_row - m_bottomLeft.m_row;
}

void Rectangle::buildDefaultRectangle()
{
	m_bottomLeft.m_col = DEFAULT_X0;
	m_bottomLeft.m_row = DEFAULT_Y0;

	m_topRight.m_col = DEFAULT_X1;
	m_topRight.m_row = DEFAULT_Y1;
}

bool Rectangle::validateCordinates() const
{
	if (!m_bottomLeft.isValid() || !m_topRight.isValid()
		|| !m_topRight.isHigherThan(m_bottomLeft) || !m_topRight.isToTheRightOf(m_bottomLeft))
		return false;

	return true;
}