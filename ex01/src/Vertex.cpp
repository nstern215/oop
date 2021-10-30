#include "Vertex.h"
#include "macros.h"

#include <iostream>

bool Vertex::isHigherThan(const Vertex& other) const
{
    return m_row > other.m_row;
}

bool Vertex::isToTheRightOf(const Vertex& other) const
{
    return m_col > other.m_col;
}

bool Vertex::isValid() const
{
    return m_col >= 0 && m_col <= MAX_COL && m_row >= 0 && m_row <= MAX_ROW;
}

bool Vertex::isValid(const double col, const double row) const
{
    return col >= 0 && col <= MAX_COL && row >= 0 && row <= MAX_ROW;
}

bool Vertex::scaleFromVertex(const double factor, const Vertex center)
{
    const auto newCol = center.m_col + ((m_col - center.m_col) * factor);
    const auto newRow = center.m_row + ((m_row - center.m_row) * factor);

    if (!isValid(newCol, newRow))
        return false;

    m_col = newCol;
    m_row = newRow;

    return true;
}

std::istream& operator>>(std::istream& istr, Vertex& v)
{
    return istr >> v.m_col >> v.m_row;
}

std::ostream& operator<<(std::ostream& ostr, const Vertex& v)
{
    return ostr << "(" << v.m_col << ", " << v.m_row << ")";
}
