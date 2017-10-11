#ifndef IIW_H_
 # define IIW_H_
  #include <stdio.h>
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
  #include <errno.h>
  #ifdef _WIN32
   #include <io.h>
  #else
   #include <unistd.h>
  #endif /* !_WIN32 */
#endif /* !IIW_H_ */

/*
** iiw_core.c
*/

int	peekat_core(char *filename, char type);

/*
** setups.c
*/

SDL_Window	*setup_window(SDL_Rect *border, SDL_DisplayMode *desktop, char *name, char type);
int		set_renderer(SDL_Renderer *rand, SDL_Surface *img, SDL_Rect *pos);
void		setup_rect(SDL_Surface *img, SDL_DisplayMode *desktop, SDL_Rect *border, SDL_Rect *fullscr);
