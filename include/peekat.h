#ifndef PEEKAT_H_
 # define PEEKAT_H_
  #include <stdio.h>
  #include <SDL2/SDL.h>
  #include <SDL2/SDL_image.h>
  #include <errno.h>
  #ifdef _WIN32
   #include <io.h>
  #else
   #include <unistd.h>
  #endif /* !_WIN32 */
#endif /* !PEEKAT_H_ */

/*
** main.c
*/

void	quit_sdl(void);

/*
** peekat_core.c
*/

int	peekat_core(char *filename, char type);

/*
** setups.c
*/

SDL_Window	*setup_window(SDL_Rect *border, char *name, char type);
void		setup_rect(SDL_Surface *img, SDL_Rect *border,
			   int w, int h, char mode);
