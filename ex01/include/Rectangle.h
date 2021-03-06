#pragma once

#include "Vertex.h"
#include "Board.h"

class Rectangle
{
public:
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(const Vertex vertices[2]);
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& start, double width, double height);
	
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	double getWidth() const;
	double getHeight() const;

private:
	void buildDefaultRectangle();
	bool validateCordinates() const;
	Vertex m_bottomLeft;
	Vertex m_topRight;
};

const double DEFAULT_X0 = 20;
const double DEFAULT_Y0 = 10;

const double DEFAULT_X1 = 30;
const double DEFAULT_Y1 = 20;