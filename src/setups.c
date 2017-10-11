#include "iiw.h"

SDL_Window	*setup_window(SDL_Rect *border, SDL_DisplayMode *desktop,
			      char *filename, char type)
{
  SDL_Window		*window;

  if (type == 'b')
    {
      window = SDL_CreateWindow(filename,
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				border->w, border->h,
				SDL_WINDOW_ALLOW_HIGHDPI);
    }
  else
    {
      window = SDL_CreateWindow(filename,
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				desktop->w, desktop->h,
				SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
  return (window);
}

int		set_renderer(SDL_Renderer *rend,
			     SDL_Surface *img, SDL_Rect *pos)
{
  SDL_Texture	*fimg;

  SDL_RenderClear(rend);
  fimg = SDL_CreateTextureFromSurface(rend, img);
  SDL_RenderCopy(rend, fimg, NULL, pos);
  SDL_DestroyTexture(fimg);
  return (0);
}

void		setup_rect(SDL_Surface *image, SDL_DisplayMode *desktop,
			   SDL_Rect *border, SDL_Rect *fullscr)
{
  const int	DESK_MAX_W = 1600, DESK_MAX_H = 900;
  
  /* Setting dimentions for bordered window */
  if (image->w > DESK_MAX_W || image->h > DESK_MAX_H)
    {
      border->w = (image->w > image->h ? DESK_MAX_W : (float)image->w / ((float)image->h / DESK_MAX_H));
      border->h = (image->w > image->h ? (float)image->h / ((float)image->w / DESK_MAX_W) : DESK_MAX_H);
    }
  else
    {
      border->w = image->w;
      border->h = image->h;
    }
  border->x = (border->y = 0);
  /* Setting dimentions for fullscreen */
  if (image->w > desktop->w || image->h > desktop->h)
    {
      fullscr->w = (image->w > image->h ? desktop->w : (float)image->w / ((float)image->h / desktop->h));
      fullscr->h = (image->w > image->h ? (float)image->h / ((float)image->w / desktop->w) : desktop->h);
    }
  else
    {
      fullscr->w = image->w;
      fullscr->h = image->h;
    }
  fullscr->x = (desktop->w - fullscr->w) / 2;
  fullscr->y = (desktop->h - fullscr->h) / 2;
}
