#include "Rectangle.h"
#include "macros.h"

//ctors
Rectangle::Rectangle(const Vertex& bottomLeft, const Vertex& topRight)
{
	if (bottomLeft.isValid() && topRight.isValid())
	{
		m_bottomLeft = bottomLeft;
		m_topRight = topRight;
	}
	else
	{
		buildDefaultRectangle();
	}
}

Rectangle::Rectangle(const Vertex vertices[2])
	: Rectangle(vertices[0], vertices[1])
{
}

Rectangle::Rectangle(double x0, double y0, double x1, double y1)
{
	if (!validateCordinates(x0, y0, x1, y1))
		buildDefaultRectangle();
	else
	{
		m_bottomLeft.m_col = x0;
		m_bottomLeft.m_row = y0;

		m_topRight.m_col = x1;
		m_topRight.m_row = y1;
	}
}

Rectangle::Rectangle(const Vertex& start, double width, double height)
	:Rectangle(start.m_col, start.m_row, start.m_row + width, start.m_row + height)
{
}

void Rectangle::draw(Board& board) const
{
	Vertex v1, v2, v3, v4;
	v1 = m_bottomLeft;
	
	v2.m_col = m_bottomLeft.m_col;
	v2.m_row = m_topRight.m_row;
	
	v3 = m_topRight;

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
	//use auto?
	const double center_col = (m_bottomLeft.m_col + m_topRight.m_col) / 2;
	const double center_row = (m_bottomLeft.m_row + m_topRight.m_row) / 2;

	Vertex center;
	center.m_col = center_col;
	center.m_row = center_row;

	return center;
}

bool Rectangle::scale(double factor)
{
	return true;
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

bool Rectangle::validateCordinates(const double x0, const double y0, const double x1, const double y1) const
{
	return x0 >= 0 && y0 <= MAX_COL && x1 >= 0 && y1 <= MAX_ROW;
}
