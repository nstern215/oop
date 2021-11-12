#include "cube.h"

cube::cube(int row, int col, char content, char overrideBy):
	m_col(col),
	m_row(row),
	m_content(content),
	m_override(overrideBy)
{
}

cube::cube(const cube& other):
	m_col(other.getCol()),
	m_row(other.getRow()),
	m_content(other.getContent()),
	m_override(other.getOverride())
{
}

cube& cube::operator=(const cube& other)
{
	if (this != &other)
	{
		m_row = other.getRow();
		m_col = other.getCol();
		m_content = other.getContent();
		m_override = other.getOverride();
	}

	return  *this;
}

bool cube::operator==(const cube& other) const
{
	return m_col == other.getCol() && m_row == other.getRow();
}

bool cube::moveIn(cube& source)
{
	const char activeElement = getActiveElement();

	switch (activeElement)
	{
	case '@':
		if (source.getActiveElement() != 'K')
			return false;

		m_override = source.getActiveElement();
		source.removeActiveElement();
		return true;

	case ' ':
	case 'F':
	case 'X':
		m_override = source.getActiveElement();
		source.removeActiveElement();
		return true;

	default:
		return false;
	}
}

void cube::setContent(char newContent)
{
	m_content = newContent;
}

char cube::getActiveElement() const
{
	return m_override != 0 ? m_override : m_content;
}

void cube::removeActiveElement()
{
	if (getActiveElement() == m_override)
		m_override = 0;
	else
		m_content = ' ';
}

int cube::getRow() const
{
	return m_row;
}

int cube::getCol() const
{
	return m_col;
}

char cube::getContent() const
{
	return m_content;
}

char cube::getOverride() const
{
	return m_override;
}

