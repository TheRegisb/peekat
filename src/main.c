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

static void	show_help(char *prog_name)
{
  printf("%s -- A monotask image viewer\n"
	 "Usage: %s [(-b/)-f] [file]\nOptions:\n"
	 "  -b: Show image in a bordered window (implicit default).\n"
	 "  -f: Show image in fullscreen.\n"
	 "  -h: Show this help message.\n"
	 "  -v: Show version and lisence.\n"
	 "File must be either a BMP, GIF, JPEG, PNG, TGA, TIFF, LBM,"
	 "PNM, PCX, WEBP, XCF, XPM or XV file.\n"
	 "If the image is to large for the window/screen, "
	 "it will be arbitrarily scaled down to fit.\n"
	 "Press Esc key, q key or window's cross to quit.\n",
	 prog_name, prog_name);
}

static void	show_version(char *prog_name)
{
	printf("%s -- A monotask image viewer\n   Version: 0.7\n   "
	       "Made by: Régis Berthelot\n   "
	       "Lisenced under Zlib\n   "
	       "This software is free, and you are welcome to redistribute it "
	       "under cetain conditions.\n   "
	       "This program comes with ABSOLUTELY NO WARRANTY.\n",
	       prog_name);
}

void	quit_sdl(void) /* Linked to peekat_core's atexit() */
{
  SDL_Quit();
}

int	main(int ac, char **av)
{
  int	opt;
  scr_display_mode_t mode = BORDERED_MODE;

  if (ac == 1)
    {
      fprintf(stderr, "Syntax error: Type %s -h for help.\n", av[0]);
      return (1);
    }
  while (( opt = getopt(ac, av, "bfhv")) != -1)
    {
      switch (opt)
	{
	case 'h':
	  show_help(av[0]);
	  return (0);
	case 'v':
	  show_version(av[0]);
	  return (0);
	case 'b':
	  mode = BORDERED_MODE;
	  break;
	case 'f':
	  mode = FULLSCREEN_MODE;
	  break;
	default:
	  fprintf(stderr, "Type %s -h for help.\n", av[0]);
	  return (1);
	}
    }
  if (av[optind])
    {
      if (access(av[optind], R_OK) == 0)
	return (peekat_core(av[optind], mode));
      fprintf(stderr, "Error parsing \"%s\": %s.\n",
	      av[optind], strerror(errno));
    }
  else
    fprintf(stderr, "Syntax error: No file given.\n");
  return (2);
}
