#include "Square.h"
#include "Vertex.h"
#include "Rectangle.h"

Square::Square(const Vertex& bottomLeft, const Vertex& topRight)
	:m_rectangle(bottomLeft, topRight)
{
	  if(!validateSize())
		  m_rectangle.buildDefaultRectangle();
}
Square::Square(const Vertex& start, double length)
{
	Vertex topRight;
	topRight.m_col = start.m_col + length;
	topRight.m_row = start.m_row + length;

	m_rectangle = Rectangle(start, topRight);
}

void Square::draw(Board& board) const
{
	m_rectangle.draw(board);
}
Rectangle Square::getBoundingRectangle() const
{
	return m_rectangle.getBoundingRectangle();
}

double Square::getArea() const
{
	return m_rectangle.getArea();
}

double Square::getPerimeter() const
{
	return m_rectangle.getPerimeter();
}

Vertex Square::getCenter() const
{
	return m_rectangle.getCenter();
}

//get vertexes

bool Square::scale(double factor)
{
	return m_rectangle.scale(factor);
}

double Square::getLength() const
{
	return (m_rectangle.getTopRight().m_row - m_rectangle.getBottomLeft().m_row);
}

bool Square::validateSize() const
{
	return ((m_rectangle.getTopRight().m_row - m_rectangle.getBottomLeft().m_row)
		- (m_rectangle.getTopRight().m_col - m_rectangle.getBottomLeft().m_col)
		<= EPSILON);
}
