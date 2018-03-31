#include "Manager.h"

#pragma region Constructors
Manager::Manager(void)
{
	weather = Weather();
	terrain = Terrain();
	wind = Wind();

	burnChance = weather.WeatherEffect();
	regeneration = terrain.TerrainEffect();
	frame = 0;
}
#pragma endregion Constructors

#pragma region Public Methods
void Manager::CreateGrid(void)
{
	int rowSize = grid.GetRowSize();
	int colSize = grid.GetColSize();

	for (int x = 0; x < rowSize; x++)
	{
		for (int y = 0; y < colSize; y++)
		{
			if (x == 0 || x == rowSize - 1) grid.SetCell(Cell(x, y, BORDER));
			else if (y == 0 || y == colSize - 1) grid.SetCell(Cell(x, y, BORDER));
			else grid.SetCell(Cell(x, y, TREE));
		}
	}
	grid.SetCell(Cell(10, 10, FIRE));
}

void Manager::UpdateGrid(void)
{
	frame = UpdateEnvironment(frame);
	if (isAllTrees()) spawnFire();

	for (int x = 1; x < grid.GetRowSize() - 1; x++)
	{
		for (int y = 1; y < grid.GetColSize() - 1; y++)
		{
			Cell cell = grid.GetCell(x, y);
			if (cell.GetState() == FIRE) fireCells.push_back(cell);
			else if (cell.GetState() == EMPTY) emptyCells.push_back(cell);
		}
	}

	spreadFire(fireCells);
	respawnTree(emptyCells);
	fireCells.clear();
	emptyCells.clear();
}

int Manager::UpdateEnvironment(int frame)
{
	bool enable = false;

	if (frame == 10)
	{
		if (GetWeather() == SUNNY && GetTerrain() != DRY) SetTerrain(DRY);
		else if (GetWeather() == RAINING && GetTerrain() != WET) SetTerrain(WET);
		else if (GetWeather() == CLEAR && GetTerrain() != NORMAL) SetTerrain(NORMAL);
	}

	if (frame == 20)
	{
		DynamicWeather();
		DynamicWind();
		frame = 0;
	}

	frame++;
	return frame;
}

void Manager::DynamicWeather()
{
	random = rand() % 3;
	WeatherType type = weather.GetWeatherType(random);
	SetWeather(type);
}

void Manager::DynamicWind()
{
	random = rand() % 8 + 1;
	WindDirection direction = wind.GetWindDirection(random);
	SetWindDirection(direction);
}

void Manager::SetWeather(const WeatherType& weatherType)
{
	this->weather.SetWeathertype(weatherType);
	burnChance = weather.WeatherEffect();
}

void Manager::SetTerrain(const TerrainType& terrainType)
{
	this->terrain.SetTerrainType(terrainType);
	regeneration = terrain.TerrainEffect();
}

void Manager::SetWindDirection(const WindDirection& windDirection)
{
	this->wind.SetWindDirection(windDirection);
}

void Manager::SetGrid(const Grid& grid)
{
	this->grid = grid;
}

WeatherType Manager::GetWeather(void) const
{
	return weather.GetWeatherType();
}

TerrainType Manager::GetTerrain(void) const
{
	return terrain.GetTerrainType();
}

WindDirection Manager::GetWind(void) const
{
	return wind.GetWindDirection();
}

Grid Manager::GetGrid(void) const
{
	return grid;
}

int Manager::Frame(void) const
{
	return frame;
}
#pragma endregion Public Methods

#pragma region Private Methods
bool Manager::isAllTrees(void)
{
	bool allTrees = true;

	for (int x = 1; x < grid.GetRowSize() - 1; x++)
	{
		for (int y = 1; y < grid.GetColSize() - 1; y++)
		{
			Cell cell = grid.GetCell(x, y);
			if (cell.GetState() == FIRE) allTrees = false;
		}
	}

	return allTrees;
}

void Manager::spreadFire(const std::vector<Cell>& cellList)
{
	Cell fireCell;
	std::vector<Cell> dirCell;

	for (int i = 0; i < cellList.size(); i++)
	{
		fireCell = cellList[i];
		dirCell = wind.WindEffect(fireCell, grid);

		for (int j = 0; j < dirCell.size(); j++)
		{
			Cell cell = dirCell[j];
			random = rand() % 100 + 1;

			if (cell.GetState() == TREE && random < (burnChance * 100)) cell.SetState(FIRE);
			grid.SetCell(cell);
		}

		fireCell.SetState(EMPTY);
		grid.SetCell(fireCell);
	}
}

void Manager::respawnTree(const std::vector<Cell>& cellList)
{
	Cell regenCell;

	for (int i = 0; i < cellList.size(); i++)
	{
		regenCell = cellList[i];
		random = rand() % 100 + 1;

		if (random < (regeneration * 100)) regenCell.SetState(TREE);
		grid.SetCell(regenCell);
	}
}

void Manager::spawnFire(void)
{
	for (int i = 0; i < 20; i++)
	{
		int x = random = rand() % 20 + 1;
		int y = random = rand() % 20 + 1;

		Cell cell = grid.GetCell(x, y);
		if (cell.GetState() == TREE) cell.SetState(FIRE);
		grid.SetCell(cell);
	}
}
#pragma endregion Private Methods