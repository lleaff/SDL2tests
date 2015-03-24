/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main()
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		std::cerr <<  "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( 
				/* Window name */
				"Hello world",
				/* Window pos x, y	*/
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				/* Window size x, y */
				SCREEN_WIDTH, SCREEN_HEIGHT,
				/* SDL_WindowFlags, combine with "|" */
				SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS 
				);
		if( window == NULL )
		{
			std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );

			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, 
					SDL_MapRGB( screenSurface->format, 200, 200, 10 ) );
			
			//Update the surface
			SDL_UpdateWindowSurface( window );

			//Wait two seconds
			SDL_Delay( 5000 );
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
