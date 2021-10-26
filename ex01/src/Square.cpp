#pragma once

#include "Square.h"
#include "Vertex.h"
#include "Rectangle.h"

Square::Square(const Vertex& bottomLeft, const Vertex& topRight)
	:m_rectangle(bottomLeft, topRight)
{
	//reuse rectangle
}
Square::Square(const Vertex& start, double length)
	:m_rectangle(start, start)
{
	
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

bool Square::scale(double factor)
{
	return m_rectangle.scale(factor);
}