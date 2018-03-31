#ifndef MANAGER_H
#define MANAGER_H

#include "Cell.h"
#include "Grid.h"
#include "Weather.h"
#include "Terrain.h"
#include "Wind.h"

#include <vector>

/// <summary>
/// Controls the environment. The Manager controls the grid, weather, terrain, and wind variables.
/// </summary>
class Manager
{
public:
	/// <summary>
	/// Constructors a Manager.
	/// </summary>
	Manager(void);

	/// <summary>
	/// Initializes the Grid.
	/// </summary>
	void CreateGrid(void);

	/// <summary>
	/// Updates the Grid each frame.
	/// </summary>
	void UpdateGrid(void);

	/// <summary>
	/// Updates the enviroment variables.
	/// After 5 frames, the terrain changes based on the weather.
	/// After 10 frames, the weather changes.
	/// </summary>
	/// <param name="count">The current frame count.</param>
	int UpdateEnvironment(int count);

	/// <summary>
	/// Randomly changes the Weather.
	/// </summary>
	void DynamicWeather(void);

	/// <summary>
	/// Randomly changes the Wind direction.
	/// </summary>
	void DynamicWind(void);

	/// <summary>
	/// Sets the Weather type.
	/// </summary>
	/// <param name="weatherType">The weather type.</param>
	void SetWeather(const WeatherType& weatherType);

	/// <summary>
	/// Sets the Terrain type.
	/// </summary>
	/// <param name="terrainType">The terrain type.</param>
	void SetTerrain(const TerrainType& terrainType);

	/// <summary>
	/// Sets the Wind direction.
	/// </summary>
	/// <param name="windDirection">The wind direction.</param>
	void SetWindDirection(const WindDirection& windDirection);

	/// <summary>
	/// Sets the Grid.
	/// </summary>
	/// <param name="grid">The Grid to set.</param>
	void SetGrid(const Grid& grid);

	/// <summary>
	/// Returns the current weather type.
	/// </summary>
	/// <returns>The weather type.</returns>
	WeatherType GetWeather(void) const;

	/// <summary>
	/// Returns the current terrain type.
	/// </summary>
	/// <returns>The terrain type.</returns>
	TerrainType GetTerrain(void) const;

	/// <summary>
	/// Returns the current wind direction.
	/// </summary>
	/// <returns>The wind direction.</returns>
	WindDirection GetWind(void) const;

	/// <summary>
	/// Returns the Grid.
	/// </summary>
	/// <returns>The Grid.</returns>
	Grid GetGrid(void) const;

	/// <summary>
	/// Returns the frame.
	/// </summary>
	/// <returns>The current frame.</returns>
	int Frame(void) const;

private:
	float regeneration;
	float burnChance;
	std::vector<Cell> fireCells;
	std::vector<Cell> emptyCells;
	int random;
	int frame;

	Cell burnDirection;
	Grid grid;
	Weather weather;
	Terrain terrain;
	Wind wind;

	/// <summary>
	/// Checks the Grid too see if the Grid is all TREE Cells.
	/// </summary>
	/// <returns>True if the all Cells are TREE's. false if not.</returns>
	bool isAllTrees(void);

	/// <summary>
	/// Turns surrounding Cells on FIRE.
	/// </summary>
	/// <param name="cellList">The list of FIRE Cells.</param>
	void spreadFire(const std::vector<Cell>& cellList);

	/// <summary>
	/// Respawns a TREE Cell for each EMPTY Cell in the cellList.
	/// </summary>
	/// <param name="cellList">The list of EMPTY Cells.</param>
	void respawnTree(const std::vector<Cell>& cellList);

	/// <summary>
	/// Spawns up to 20 FIRE Cells at random places on the Grid.
	/// </summary>
	void spawnFire(void);
};

#endif