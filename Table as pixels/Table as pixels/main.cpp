#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>


int main(int argc, char *argv[])
{
	bool IsRunning = 1;
	srand(time(0));
	SDL_Event event;
	SDL_Renderer *renderer;
	SDL_Window *window;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(600, 600, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	while(IsRunning)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
				case (SDL_KEYDOWN):
				{
					switch (event.key.keysym.sym)
					{
						default:
							continue;

						case(SDLK_ESCAPE):
						{
							IsRunning = 0;
							std::cout << "esc\n";
						}
					}
				}

				case (SDL_MOUSEBUTTONDOWN):
				{
					if (IsRunning == 0)
						break;
					while (1)
					{
						SDL_PollEvent(&event);
						if(event.type == SDL_MOUSEBUTTONUP)
							break;
						SDL_SetRenderDrawColor(renderer, rand() % 255, rand() % 255, rand() % 255, 0);
						SDL_RenderDrawPoint(renderer, event.button.x, event.button.y);
						SDL_RenderPresent(renderer);
					}
				}
			}
		}	

		if (IsRunning == 0) 
		{
			break;
		}
		else
		{
			if (event.type == SDL_QUIT)
				break;
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}