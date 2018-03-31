#ifndef TERRAIN_H
#define TERRAIN_H

/// <summary>
/// The type of Terrain. NORMAL, DRY and WET.
/// </summary>
enum TerrainType
{
	DRY = 0,
	NORMAL = 1,
	WET = 2
};

/// <summary>
/// Controls the effect of the terrain type. Terrain type affects the regeneration of Cells.
/// </summary>
class Terrain
{
public:
	/// <summary>
	/// Constructs a Terrain object. The terrain type is set to NORMAL.
	/// </summary>
	Terrain(void);

	/// <summary>
	/// Constructs a Terrain object with a terrain type.
	/// </summary>
	/// <param name="weatherType">The type of terrain.</param>
	Terrain(const TerrainType& terraintype);

	/// <summary>
	/// Returns the regeneration chance of the terrain type. 
	/// </summary>
	/// <returns>The regeneration chance of the terrain type.</returns>
	float TerrainEffect(void);

	/// <summary>
	/// Returns the terrain type of this Terrain.
	/// </summary>
	/// <returns>The terrain type.</returns>
	TerrainType GetTerrainType(void) const;

	/// <summary>
	/// Sets the terrain type for this Terrain.
	/// </summary>
	/// <param name="terrainType">The terrain type.</param>
	void SetTerrainType(const TerrainType& terrainType);

private:
	TerrainType terrainType;
	float regeneration;
};

#endif