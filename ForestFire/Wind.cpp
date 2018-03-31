#include "Wind.h"

#pragma region Constructors
Wind::Wind(void)
{
	windDirection = NORTH;
}

Wind::Wind(const WindDirection& windDirection)
{
	this->windDirection = windDirection;
}
#pragma endregion Constructors

#pragma region Public Methods
WindDirection Wind::GetWindDirection(void) const
{
	return windDirection;
}

WindDirection Wind::GetWindDirection(const int index) const
{
	switch (index)
	{
	case 1:	return NORTH;
	case 2: return EAST;
	case 3: return SOUTH;
	case 4: return WEST;
	case 5: return NORTH_EAST;
	case 6: return SOUTH_EAST;
	case 7: return SOUTH_WEST;
	case 8: return NORTH_WEST;
	default: return NORTH;
	}
}

void Wind::SetWindDirection(const WindDirection& windDirection)
{
	this->windDirection = windDirection;
}

std::vector<Cell> Wind::WindEffect(const Cell& cell, const Grid& grid)
{
	// [ -1,  1 ] [ 0,  1 ] [ 1,  1 ]
	// [ -1,  0 ] [ 0,  0 ] [ 1,  0 ]
	// [ -1, -1 ] [ 0, -1 ] [ 1, -1 ]
	std::vector<Cell> neighbours(3);
	switch (windDirection)
	{
	case NORTH:
		neighbours[0] = grid.GetCell(cell.GetX() - 1, cell.GetY() - 1);
		neighbours[1] = grid.GetCell(cell.GetX() - 1, cell.GetY());
		neighbours[2] = grid.GetCell(cell.GetX() - 1, cell.GetY() + 1);
		return neighbours;

	case NORTH_EAST:
		neighbours[0] = grid.GetCell(cell.GetX() - 1, cell.GetY());
		neighbours[1] = grid.GetCell(cell.GetX() - 1, cell.GetY() + 1);
		neighbours[2] = grid.GetCell(cell.GetX(), cell.GetY() + 1);
		return neighbours;

	case EAST:
		neighbours[0] = grid.GetCell(cell.GetX() - 1, cell.GetY() + 1);
		neighbours[1] = grid.GetCell(cell.GetX(), cell.GetY() + 1);
		neighbours[2] = grid.GetCell(cell.GetX() + 1, cell.GetY() + 1);
		return neighbours;

	case SOUTH_EAST:
		neighbours[0] = grid.GetCell(cell.GetX(), cell.GetY() + 1);
		neighbours[1] = grid.GetCell(cell.GetX() + 1, cell.GetY() + 1);
		neighbours[2] = grid.GetCell(cell.GetX() + 1, cell.GetY());
		return neighbours;

	case SOUTH:
		neighbours[0] = grid.GetCell(cell.GetX() + 1, cell.GetY() + 1);
		neighbours[1] = grid.GetCell(cell.GetX() + 1, cell.GetY());
		neighbours[2] = grid.GetCell(cell.GetX() + 1, cell.GetY() - 1);
		return neighbours;

	case SOUTH_WEST:
		neighbours[0] = grid.GetCell(cell.GetX() + 1, cell.GetY());
		neighbours[1] = grid.GetCell(cell.GetX() + 1, cell.GetY() - 1);
		neighbours[2] = grid.GetCell(cell.GetX(), cell.GetY() - 1);
		return neighbours;

	case WEST:
		neighbours[0] = grid.GetCell(cell.GetX() + 1, cell.GetY() - 1);
		neighbours[1] = grid.GetCell(cell.GetX(), cell.GetY() - 1);
		neighbours[2] = grid.GetCell(cell.GetX() - 1, cell.GetY() - 1);
		return neighbours;

	case NORTH_WEST:
		neighbours[0] = grid.GetCell(cell.GetX(), cell.GetY() - 1);
		neighbours[1] = grid.GetCell(cell.GetX() - 1, cell.GetY() - 1);
		neighbours[2] = grid.GetCell(cell.GetX() - 1, cell.GetY());
		return neighbours;
	}
	return neighbours;
}
#pragma endregion Public Methods