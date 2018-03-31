#include "Cell.h"

#pragma region Constructors
Cell::Cell(void)
{
	x = 0;
	y = 0;
	state = EMPTY;
}

Cell::Cell(const int x, const int y, const CellState state)
{
	this->x = x;
	this->y = y;
	this->state = state;
}
#pragma endregion Constructors

#pragma region Public Methods
int Cell::GetX(void) const
{
	return x;
}

int Cell::GetY(void) const
{
	return y;
}

CellState Cell::GetState(void) const
{
	return state;
}

void Cell::SetX(const int x)
{
	this->x = x;
}

void Cell::SetY(const int y)
{
	this->y = y;
}

void Cell::SetState(const CellState state)
{
	this->state = state;
}
#pragma endregion Public Methods