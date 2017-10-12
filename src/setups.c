#include "peekat.h"

SDL_Window	*setup_window(SDL_Rect *border, char *filename, char type)
{
  SDL_Window		*window;

  window = SDL_CreateWindow(filename,
			    SDL_WINDOWPOS_UNDEFINED,
			    SDL_WINDOWPOS_UNDEFINED,
			    border->w, border->h,
			    SDL_WINDOW_ALLOW_HIGHDPI |
			    (type == 'b' ? 0 : SDL_WINDOW_FULLSCREEN_DESKTOP));
  return (window);
}

static float	fit_ratio(int disp_w, int disp_h, int img_w, int img_h)
{
  const float	DISPLAY_RATIO = 16.0/9;

  return ((DISPLAY_RATIO > (float)img_w / img_h) ?
	  (float)disp_h / img_h : (float)disp_w / img_w);
}

void	setup_rect(SDL_Surface *image, SDL_Rect *size,
		   int disp_w, int disp_h,
		   char mode)
{
  float		scale_factor, fwidth, fheight;

  if (image->w > disp_w || image->h > disp_h) /* Scale down on overflow */
    {
      scale_factor = fit_ratio(disp_w, disp_h, image->w, image->h);
      fwidth = image->w * scale_factor;
      fheight = image->h * scale_factor;
      size->w = fwidth;
      size->h = fheight;
    }
  else
    {
      size->w = image->w;
      size->h = image->h;
    }
  size->x = (mode == 'b' ? 0 : disp_w / 2 - image->h / 2);
  size->y = (mode == 'b' ? 0 : disp_h / 2 - image->w / 2);
}
