#ifndef WIND_H
#define WIND_H

#include "Cell.h"
#include "Grid.h"
#include <vector>

/// <summary>
/// The direction of the wind.
/// NORTH, EAST, SOUTH, WEST, NORTH_EAST, SOUTH_EAST, SOUTH_WEST and NORTH_WEST.
/// </summary>
enum WindDirection
{
	NORTH = 1,
	EAST = 2,
	SOUTH = 3,
	WEST = 4,
	NORTH_EAST = 5,
	SOUTH_EAST = 6,
	SOUTH_WEST = 7,
	NORTH_WEST = 8
};

/// <summary>
/// Controls the effects of the wind direction. Wind direction affects the direction of fire cells spreading.
/// </summary>
class Wind
{
public:
	/// <summary>
	/// Constructs a Wind object. The wind direction is set to NORTH.
	/// </summary>
	Wind(void);

	/// <summary>
	/// Constructs a Wind object with a wind direction.
	/// </summary>
	/// <param name="weatherType">The wind direction.</param>
	Wind(const WindDirection& windDirection);

	/// <summary>
	/// Returns the wind direction of this Wind.
	/// </summary>
	/// <returns>The wind direction</returns>
	WindDirection GetWindDirection(void) const;

	/// <summary>
	/// Returns the wind direction by its index of this Wind.
	/// </summary>
	/// <param name="index">The wind direction index.</param>
	/// <returns>The wind direction.</returns>
	WindDirection GetWindDirection(const int index) const;

	/// <summary>
	/// Sets the wind direction for this Wind.
	/// </summary>
	/// <param name="windDirection">The wind direction.</param>
	void SetWindDirection(const WindDirection& windDirection);

	/// <summary>
	/// Returns a vector of the surrounding neighbours based on the wind direction.
	/// </summary>
	/// <param name="cell">The Cell to check neighbours.</param>
	/// <param name="grid">The Grid to retrieve the Cell's neighbours.</param>
	/// <returns>A vector containing the cell's neighbours. Max 3 neighbours.</returns>
	std::vector<Cell> WindEffect(const Cell& cell, const Grid& grid);

private:
	WindDirection windDirection;
};

#endif