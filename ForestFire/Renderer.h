 #ifndef RENDERER_H
#define RENDERER_H

#include "Manager.h"
#include <Windows.h>

/// <summary>
/// The colour of the console. GREEN, RED and WHITE.
/// </summary>
enum ConsoleColour
{
	GREEN = 10,
	RED = 12,
	WHITE = 15
};

/// <summary>
/// Controls the display of the console.
/// </summary>
class Renderer
{
public:
	/// <summary>
	/// Constructs an empty Renderer.
	/// </summary>
	Renderer(void);

	/// <summary>
	/// Constructs a Renderer with a GameManager.
	/// </summary>
	Renderer(Manager& manager);

	/// <summary>
	/// Changes the size of the console window. Default:
	/// Width : 800
	/// Height : 400
	/// </summary>
	/// <param name="width">The width of the console.</param>
	/// <param name="height">The height of the console.</param>
	void ChangeConsoleSize(const int width, const int height);

	/// <summary>
	/// Displays environment variables. Weather, Terrain and Wind.
	/// </summary>
	void DisplayConditions(void);

	/// <summary>
	/// Renders a Grid to the console.
	/// </summary>
	/// <param name="grid">The grid to render.</param>
	void DisplayGrid(const Grid& grid);

	/// <summary>
	/// Clear the console screen.
	/// </summary>
	void ClearScreen(void);

private:
	Manager* manager;
	HANDLE consoleHandle;
	HWND hwnd;

	/// <summary>
	/// Renders a Grid.
	/// </summary>
	void displayState(const Cell& cell);

	/// <summary>
	/// Renders the weather type.
	/// </summary>
	void displayWeather(void);

	/// <summary>
	/// Renders the terrain type.
	/// </summary>
	void displayTerrain(void);

	/// <summary>
	/// Renders the wind direction.
	/// </summary>
	void displayWindDirection(void);

	/// <summary>
	/// Renders the frame count.
	/// </summary>
	void displayFrame(void);
};

#endif