#ifndef CELL_H
#define CELL_H

/// <summary>
/// The state of a Cell. EMPTY, TREE, FIRE and BORDER.
/// </summary>
enum CellState
{
	EMPTY = 0,
	TREE = 1,
	FIRE = 2,
	BORDER = 3
};

/// <summary>
/// Contains the position and state of a Cell.
/// </summary>
class Cell
{
public:
	/// <summary>
	/// Constructs an empty Cell object.
	/// </summary>
	explicit Cell(void);

	/// <summary>
	/// Constructs a Cell with an X and Y position, and a state.
	/// </summary>
	/// <param name="x">The X position.</param>
	/// <param name="y">The Y position</param>
	/// <param name="state">The CellState.</param>
	explicit Cell(const int x, const int y, const CellState state);

	/// <summary>
	/// Returns the X position.
	/// </summary>
	/// <returns>The X posiiton.</returns>
	int GetX(void) const;

	/// <summary>
	/// Returns the Y position.
	/// </summary>
	/// <returns>The Y position.</returns>
	int GetY(void) const;

	/// <summary>
	/// Returns the CellState.
	/// </summary>
	/// <returns>The state of the cell.</returns>
	CellState GetState(void) const;

	/// <summary>
	/// Sets the X position.
	/// </summary>
	/// <param name="x">The X position.</param>
	void SetX(const int x);

	/// <summary>
	/// Sets the Y position.
	/// </summary>
	/// <param name="y">The Y position.</param>
	void SetY(const int y);

	/// <summary>
	/// Sets the CellState.
	/// </summary>
	/// <param name="state">The CellState</param>
	void SetState(const CellState state);

private:
	int x;
	int y;
	CellState state;
};

#endif