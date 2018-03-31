#include "Terrain.h"

#pragma region Constructors
Terrain::Terrain(void)
{
	terrainType = NORMAL;
}

Terrain::Terrain(const TerrainType& terrainType)
{
	this->terrainType = terrainType;
}
#pragma endregion Constructors

#pragma region Public Methods
TerrainType Terrain::GetTerrainType(void) const
{
	return terrainType;
}

void Terrain::SetTerrainType(const TerrainType& terrainType)
{
	this->terrainType = terrainType;
}

float Terrain::TerrainEffect(void)
{
	if (terrainType == DRY)		regeneration = 0.25f;
	else if (terrainType == NORMAL)	regeneration = 0.5f;
	else if (terrainType == WET)		regeneration = 0.75f;
	return regeneration;
}
#pragma endregion Public Methods