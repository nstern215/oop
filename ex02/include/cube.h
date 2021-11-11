#pragma once

#include <string>
#include <vector>

using std::vector;
using std::string;

class cube
{
public:
	cube(int row = 0, int col = 0, char content = ' ', char overrideBy = 0);
	cube(const cube& other);

	cube& operator=(const cube& other);
	bool operator==(const cube& other) const;
	
	void setContent(char newContent);
	bool moveIn(cube& source);
	char getActiveElement() const;
	void removeActiveElement();
	void print() const;

	int getCol() const;
	int getRow() const;
	char getContent() const;
	char getOverride() const;

private:
	int m_col;
	int m_row;
	char m_content;
	char m_override;
};
