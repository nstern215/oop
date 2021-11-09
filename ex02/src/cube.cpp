#include "cube.h";

cube::cube(int row, int col, char content, char overrideBy):
	m_col(col),
	m_row(row),
	m_content(content),
	m_override(overrideBy)
{
	setContent(content);
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

bool cube::moveIn(cube& source)
{
	const char activeElement = getActiveElement();

	switch (activeElement)
	{
	case ' ':
		return true;
	case '=':
		return false;
	case '#':
		if (source.getActiveElement() == 'T' /*todo: and has key*/)
			return true;
		return false;
	case '*':
		if (source.getActiveElement() == 'M')
			return true;
		return false;
	case 'X':
		if (source.getActiveElement() != 'M')
			return true; //todo: and send to the pair cube
		return true;
	case '@':
		if (source.getActiveElement() == 'K')
			return true; //todo: finish the game
		return false;
	case '!':
		if (source.getActiveElement() == 'W')
			return true; //todo: drop a key
		return false;
		default:
			return false;
	}
}

bool cube::setContent(char newContent)
{
	m_content = newContent;
	//m_content += newContent;
	//todo: do we need this?
	return true;
}

char cube::getActiveElement() const
{
	/*return m_content[0];*/
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

