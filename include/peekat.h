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

typedef enum {
	BORDERED_MODE,
	FULLSCREEN_MODE
}	scr_display_mode_t;

/*
** main.c
*/

void	quit_sdl(void);

/*
** peekat_core.c
*/

int	peekat_core(char *filename, scr_display_mode_t mode);

/*
** setups.c
*/

SDL_Window	*setup_window(SDL_Rect *border, char *name,
			      scr_display_mode_t type);
void		setup_rect(SDL_Surface *img, SDL_Rect *border,
			   int w, int h, scr_display_mode_t mode);


#endif /* !PEEKAT_H_ */
