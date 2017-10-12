#include "peekat.h"

static void	show_help(char *prog_name)
{
  printf("peekat -- A monotask image viewer\n"
	 "Usage: %s [(-b/)-f] [file]\nOptions:\n"
	 "  -b: Show image in a bordered window. (implicit default)\n"
	 "  -f: Show image in fullscreen.\n"
	 "File must be either a BMP, GIF, JPEG, PNG, TGA, TIFF, LBM,"
	 "PNM, PCX, WEBP, XCF, XPM or XV file.\n"
	 "If the image is to large for the window/screen, "
	 "it will be arbitrarily scaled down to fit.\n"
	 "Press Esc key or window's cross to quit.\n", prog_name);
}

void	quit_sdl(void) /* Linked to peekat_core's atexit() */
{
  SDL_Quit();
}

int	main(int ac, char **av)
{
  int	opt;
  enum { BORDERED_MODE = 'b', FULLSCREEN_MODE = 'f' } mode = BORDERED_MODE;

  if (ac == 1)
    {
      fprintf(stderr, "Syntax error: Type %s -h for help.\n", av[0]);
      return (1);
    }
  while (( opt = getopt(ac, av, "bfh")) != -1)
    {
      switch (opt)
	{
	case 'h':
	  show_help(av[0]);
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
