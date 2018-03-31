#include "Renderer.h"
#include <iostream>

# pragma region Constructors
Renderer::Renderer(void)
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hwnd = GetConsoleWindow();
	if (hwnd != NULL) MoveWindow(hwnd, 0, 0, 800, 400, true);
}

Renderer::Renderer(Manager& manager)
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hwnd = GetConsoleWindow();
	if (hwnd != NULL) MoveWindow(hwnd, 0, 0, 800, 400, true);
	this->manager = &manager;
}
#pragma endregion Constructors

#pragma region Public Methods
void Renderer::ChangeConsoleSize(const int width, const int height)
{
	MoveWindow(hwnd, 0, 0, width, height, true);
}

void Renderer::DisplayConditions(void)
{
	displayWeather();
	displayTerrain();
	displayWindDirection();
	displayFrame();
}

void Renderer::DisplayGrid(const Grid& grid)
{
	std::cout << std::endl;

	for (int x = 0; x < grid.GetRowSize(); x++)
	{
		for (int y = 0; y < grid.GetColSize(); y++)
		{
			displayState(grid.GetCell(x, y));
		}
		std::cout << std::endl;
	}
}

void Renderer::ClearScreen(void)
{
	// stops the screen flickering when clearing
	// http://www.cplusplus.com/forum/beginner/18191/
	COORD position;
	position.X = 0;
	position.Y = 0;
	SetConsoleCursorPosition(consoleHandle, position);
}
#pragma endregion Public Methods

#pragma region Private Methods
void Renderer::displayState(const Cell& cell)
{
	ConsoleColour colour;

	switch (cell.GetState())
	{
	case EMPTY:
		std::cout << " ";
		break;
	case TREE:
		SetConsoleTextAttribute(consoleHandle, colour = GREEN);
		std::cout << "^";
		break;
	case FIRE:
		SetConsoleTextAttribute(consoleHandle, colour = RED);
		std::cout << "X";
		break;
	case BORDER:
		SetConsoleTextAttribute(consoleHandle, colour = WHITE);
		std::cout << "#";
		break;
	}
}

void Renderer::displayWeather(void)
{
	std::cout << "Current Weather: ";

	switch (manager->GetWeather())
	{
	case CLEAR:		std::cout << "CLEAR" << std::endl; break;
	case SUNNY:		std::cout << "SUNNY" << std::endl; break;
	case RAINING:	std::cout << "RAINING" << std::endl; break;
	}
}

void Renderer::displayTerrain(void)
{
	std::cout << "Current Terrain: ";

	switch (manager->GetTerrain())
	{
	case NORMAL:	std::cout << "NORMAL" << std::endl; break;
	case DRY:		std::cout << "DRY" << std::endl; break;
	case WET:		std::cout << "WET" << std::endl; break;
	}
}

void Renderer::displayWindDirection(void)
{
	std::cout << "Current Wind Direction: ";

	switch (manager->GetWind())
	{
	case NORTH:			std::cout << "NORTH" << std::endl; break;
	case NORTH_EAST:	std::cout << "NORTH EAST" << std::endl; break;
	case EAST:			std::cout << "EAST" << std::endl; break;
	case SOUTH_EAST:	std::cout << "SOUTH EAST" << std::endl; break;
	case SOUTH:			std::cout << "SOUTH" << std::endl; break;
	case SOUTH_WEST:	std::cout << "SOUTH WEST" << std::endl; break;
	case WEST:			std::cout << "WEST" << std::endl; break;
	case NORTH_WEST:	std::cout << "NORTH WEST" << std::endl; break;
	}
}

void Renderer::displayFrame(void)
{
	int count = manager->Frame();
	std::cout << "Current frame: " << count << ' ' << std::endl;
}
#pragma endregion Private Methods