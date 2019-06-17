#include <iostream>
#include <SDL.h>
#include <SDL_main.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

void start(SDL_Renderer *renderer, SDL_Rect red, SDL_Rect blue, SDL_Rect green);


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
	SDL_Rect red = { 0, 500, 100, 100 };
	SDL_Rect blue = { 100, 500, 100, 100 };
	SDL_Rect green = { 200, 500, 100, 100 };
	start(renderer, red, blue, green);

	while (IsRunning)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
				case (SDL_KEYDOWN):
				{
					switch (event.key.keysym.sym)
					{
						case(SDLK_ESCAPE):
						{
							std::cout << "esc\n";
							IsRunning = 0;
							break;
						}
					}
					break;
				}

				case (SDL_MOUSEBUTTONDOWN):
				{
					if (event.button.x > 0  && event.button.x <= 100 && event.button.y >= 500 && event.button.y <= 600)
						SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
					if (event.button.x > 100 && event.button.x <= 200 && event.button.y >= 500 && event.button.y <= 600)
						SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
					if (event.button.x > 200 && event.button.x <= 300 && event.button.y >= 500 && event.button.y <= 600)
						SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
					while (1)
					{
						SDL_PollEvent(&event);
						if (event.type == SDL_MOUSEBUTTONUP)
							break;
						SDL_RenderDrawPoint(renderer, event.button.x, event.button.y);
						SDL_RenderPresent(renderer);
					}
					break;
				}

				case (SDL_QUIT):
				{
					std::cout << "X\n";
					IsRunning = 0;
					break;
				}
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}

void start(SDL_Renderer *renderer, SDL_Rect red, SDL_Rect blue, SDL_Rect green)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	SDL_RenderFillRect(renderer, &red);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	SDL_RenderFillRect(renderer, &blue);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
	SDL_RenderFillRect(renderer, &green);
	SDL_RenderPresent(renderer);
}