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
