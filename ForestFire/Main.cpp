#include "Manager.h"
#include "Renderer.h"

#include <iostream>
#include <string>

void Init(void);

int main(void)
{
	Init();
	return 0;
}

void Init(void)
{
	Grid grid = Grid(21, 21);
	Manager manager = Manager();
	Renderer renderer = Renderer(manager);
	std::string input;
	bool redraw = true;

	manager.SetGrid(grid);
	manager.CreateGrid();
	renderer.ChangeConsoleSize(800, 400);
	renderer.DisplayConditions();
	renderer.DisplayGrid(manager.GetGrid());

	while (redraw)
	{
		std::cout << "Press Enter" << std::endl;
		std::getline(std::cin, input);

		if (input != "") redraw = false;
		else
		{
			renderer.ClearScreen();
			manager.UpdateGrid();
			renderer.DisplayConditions();
			renderer.DisplayGrid(manager.GetGrid());
		}
	}
}