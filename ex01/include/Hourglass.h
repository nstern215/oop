#pragma once

#include "Vertex.h"
#include "Rectangle.h"
#include "Triangle.h"

class Hourglass
{
public:
	Hourglass(const Triangle& upper, const Triangle& lower);
	Hourglass(const Triangle& lower);

	double getLength() const;
	double getHeight() const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	Triangle m_upper;
	Triangle m_lower;
};