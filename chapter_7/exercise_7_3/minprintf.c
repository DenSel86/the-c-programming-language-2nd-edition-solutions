#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void minprintf(const char *fmt, ...);

int main(int argc, char *argv[])
{
  minprintf("This is a test. Let's print %d, %i, %o, %x, %X, %u, %c, %e, %E, %g, %G, %f, and %s.\n", 2, 3, 8, 16, 16, -1, 97, 0.0025f, 0.0023f, 0.0025f, 0.0023f, 3.14159f, "hello, world");
  return EXIT_SUCCESS;
}

void minprintf(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  for (; *fmt != '\0'; ++fmt)
  {
    if (*fmt != '%')
    {
      putc(*fmt, stdout);
      continue;
    }

    switch (*++fmt)
    {
    case 'd':
    case 'i':
      printf("%d", va_arg(ap, int));
      break;

    case 'o':
      printf("%o", va_arg(ap, int));
      break;

    case 'x':
    case 'X':
      printf("%x", va_arg(ap, int));
      break;

    case 'u':
      printf("%u", va_arg(ap, int));
      break;

    case 'c':
      printf("%c", va_arg(ap, int));
      break;

    case 's':
      printf("%s", va_arg(ap, char *));
      break;

    case 'f':
      printf("%f", va_arg(ap, double));
      break;

    case 'e':
    case 'E':
      printf("%e", va_arg(ap, double));
      break;

    case 'g':
    case 'G':
      printf("%g", va_arg(ap, double));
      break;

    default:
      putc(*fmt, stdout);
      break;
    }
  }
  va_end(ap);
}
