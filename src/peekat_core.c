#include "peekat.h"

/*
** Default maximum size for bordered windows
*/

static void	event_loop(SDL_Renderer *rend,
			   SDL_Surface *image, SDL_Rect *pos)
{
  SDL_Event	event;
  
  set_renderer(rend, image, pos);
  do
    {
      if (SDL_PollEvent(&event) == 1)
	{
	  switch (event.type)
	  case SDL_KEYDOWN:
	    {
	      if (event.key.keysym.sym == SDLK_ESCAPE)
		event.type = SDL_QUIT;
	      break;
	    }
	}
      SDL_RenderPresent(rend);
    }
  while (event.type != SDL_QUIT);
}

void	quit_sdl(void)
{
  SDL_Quit();
}

int	sdl_error_output(char *func_name)
{
  fprintf(stderr, "%s: %s.\n", func_name, SDL_GetError());
  return (2);
}

int			peekat_core(char *filename, char type)
{
  SDL_Window		*window;
  SDL_Renderer		*renderer;
  SDL_Surface		*image;
  SDL_Rect		border, fullscr;
  SDL_DisplayMode	desktop;

  if (!(image = IMG_Load(filename)))
      return (sdl_error_output("IMG_Load"));
  if (SDL_Init(SDL_INIT_VIDEO) == 1)
    return (sdl_error_output("SDL_Init"));
  atexit(quit_sdl);
  SDL_GetCurrentDisplayMode(0, &desktop);
  setup_rect(image, &desktop, &border, &fullscr);
  if (!(window = setup_window(&border, &desktop, filename, type)))
    return (sdl_error_output("SDL_CreateWindow"));
  if (!(renderer = SDL_CreateRenderer(window, -1, 0)))
    return (sdl_error_output("SDL_CreateRenderer"));
  if (type == 'b')
    event_loop(renderer, image, &border);
  else
    event_loop(renderer, image, &fullscr);
  SDL_FreeSurface(image);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  return (0);
}
