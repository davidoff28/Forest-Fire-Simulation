#ifndef GRID_H
#define GRID_H

#include "Cell.h"
#include <vector>

/// <summary>
/// Contains a number of defined Cells in a 2D grid.
/// </summary>
class Grid
{
public:
	/// <summary>
	/// Constructs a 2D 21x21 Grid.
	/// </summary>
	Grid(void);

	/// <summary>
	/// Constructs a 2D Grid with the specified row and column sizes.
	/// </summary>
	/// <param name="rows">The number of rows.</param>
	/// <param name="columns">The number of columns.</param>
	Grid(const int rows, const int columns);

	/// <summary>
	/// Returns the number of rows.
	/// </summary>
	/// <returns>The number of rows.</returns>
	int GetRowSize(void) const;

	/// <summary>
	/// Returns the number of columns.
	/// </summary>
	/// <returns>The number of columns.</returns>
	int GetColSize(void) const;

	/// <summary>
	/// Returns a Cell at the given X and Y position.
	/// </summary>
	/// <param name="x">The X position.</param>
	/// <param name="y">The Y position.</param>
	/// <returns>The Cell at the X and Y position.</returns>
	Cell GetCell(const int x, const int y) const;

	/// <summary>
	/// Resizes the Grid to a new set of row and column sizes.
	/// </summary>
	/// <param name="rows">The number of rows.</param>
	/// <param name="columns">The number of columns.</param>
	void ResizeGrid(const int rows, const int columns);

	/// <summary>
	/// Sets a Cell on the Grid. The X and Y positions are taken from the given Cell.
	/// </summary>
	/// <param name="cell">The Cell to set on the grid.</param>
	void SetCell(const Cell& cell);

private:
	int rowSize;
	int colSize;
	std::vector < std::vector<Cell> >grid;
};

#endif