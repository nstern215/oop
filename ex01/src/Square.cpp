#include "Square.h"
#include "Vertex.h"
#include "Rectangle.h"
#include "Triangle.h"

Square::Square(const Vertex& bottomLeft, const Vertex& topRight)
	:m_rectangle(bottomLeft, topRight)
{
	if (!validateSize())
		//in this case the rectangle should be built with default parameters
		//the Rectangle class has a private function to build a default rectangle
		//by calling the rectangle ctor with wrong input params will cause the ctor
		//to call this function
		m_rectangle = Rectangle(topRight, bottomLeft);
}
Square::Square(const Vertex& start, double length)
	:m_rectangle(start, start)
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

Vertex Square::getBottomLeft() const
{
	return m_rectangle.getBottomLeft();
}

Vertex Square::getTopRight() const
{
	return m_rectangle.getTopRight();
}

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
