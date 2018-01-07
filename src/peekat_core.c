/*
** Copyright (C) 2018 Berthelot Régis (berthelot.regis@gmail.com)
**
** This software is provided 'as-is', without any express or implied
** warranty.  In no event will the authors be held liable for any damages
** arising from the use of this software.
** 
** Permission is granted to anyone to use this software for any purpose,
** including commercial applications, and to alter it and redistribute it
** freely, subject to the following restrictions:
** 
** 1. The origin of this software must not be misrepresented; you must not
**    claim that you wrote the original software. If you use this software
**    in a product, an acknowledgment in the product documentation would be
**    appreciated but is not required.
** 2. Altered source versions must be plainly marked as such, and must not be
**    misrepresented as being the original software.
** 3. This notice may not be removed or altered from any source distribution.
*/

#include "peekat.h"

static void	refresh_renderer(SDL_Renderer *rend,
				 SDL_Texture *fimg, SDL_Rect *pos)
{
  SDL_RenderClear(rend);
  SDL_RenderCopy(rend, fimg, NULL, pos);
  SDL_RenderPresent(rend);
}

static void	event_loop(SDL_Renderer *rend,
			   SDL_Surface *image, SDL_Rect *pos)
{
  SDL_Event	event;
  SDL_Texture	*fimg;

  fimg = SDL_CreateTextureFromSurface(rend, image);
  do
    {
      if (SDL_PollEvent(&event) == 1)
	{
	  refresh_renderer(rend, fimg, pos);
	  switch (event.type)
	  case SDL_KEYDOWN:
	    {
	      if (event.key.keysym.sym == SDLK_ESCAPE
		  || event.key.keysym.sym == SDLK_q)
		event.type = SDL_QUIT;
	      break;
	    }
	}
    }
  while (event.type != SDL_QUIT);
  SDL_DestroyTexture(fimg);
}

static int	sdl_error_output(char *func_name)
{
  fprintf(stderr, "%s: %s.\n", func_name, SDL_GetError());
  return (2);
}

int			peekat_core(char *filename, scr_display_mode_t mode)
{
  const int		DSK_MAX_W = 1600, DSK_MAX_H = 900;
  SDL_Window		*window;
  SDL_Renderer		*renderer;
  SDL_Surface		*image;
  SDL_Rect		border;
  SDL_DisplayMode	desktop;

  if (!(image = IMG_Load(filename)))
      return (sdl_error_output("IMG_Load"));
  if (SDL_Init(SDL_INIT_VIDEO) == 1)
    return (sdl_error_output("SDL_Init"));
  atexit(quit_sdl);
  if (mode == BORDERED_MODE)
    setup_rect(image, &border, DSK_MAX_W, DSK_MAX_H, BORDERED_MODE);
  else
    {
      SDL_GetCurrentDisplayMode(0, &desktop);
      setup_rect(image, &border, desktop.w, desktop.h, FULLSCREEN_MODE);
    }
  if (!(window = setup_window(&border, filename, mode)))
    return (sdl_error_output("SDL_CreateWindow"));
  if (!(renderer = SDL_CreateRenderer(window, -1, 0)))
    return (sdl_error_output("SDL_CreateRenderer"));
  event_loop(renderer, image, &border);
  SDL_FreeSurface(image);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  return (0);
}

