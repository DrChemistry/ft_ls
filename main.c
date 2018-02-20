#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <string.h>
#include "my.h"
#include "my_ls.h"

int	main(int ac, char **av)
{
  DIR	*rep;
  struct dirent *lecture;
  struct stat	read;
  char	*str;

  rep = opendir(av[1]);
  while (lecture = readdir(rep))
    {
      str = lecture->d_name;
      printf(" %s ", str);
      stat(str, &read);
      printf("%d", read.st_nlink);
    }
}
