#pragma once

#include "Vertex.h"
#include "Rectangle.h"
#include "Board.h"
#include <cmath>

class Triangle
{
public:
	//ctors
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& v0, const Vertex& v1, double height);

	Vertex getVertex(int index) const;
	double getLength() const;
	double getHeigt() const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	void buildDefaultRectangle();
	bool validateCoordinates(const Vertex v0, const Vertex v1, const Vertex v2) const;
	bool checkParallelX(const Vertex v0, const Vertex v1) const;
	double calcDistance(const Vertex v0, const Vertex v1) const;

	Vertex m_v0;
	Vertex m_v1;
	Vertex m_v2;
};

const double DEFAULT_V0_COL = 20;
const double DEFAULT_V0_ROW = 20;
const double DEFAULT_V1_COL = 20;
const double DEFAULT_V1_ROW = 30;
const double DEFAULT_V2_COL = 25;
const double DEFAULT_V2_ROW = 20 + sqrt(75);

const double EPSILON = 0.5;