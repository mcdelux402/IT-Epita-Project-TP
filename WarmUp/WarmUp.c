# include <stdio.h>
# include <stdlib.h>

int *FindTarget(int list[], size_t t,  int target)
{
  int* s = NULL;
  s = malloc(sizeof(int)*2);
  size_t i = 0;
  printf("1");
  while (i < t - 1 && list[i] < target)
    {
      printf("2");
      size_t j = i + 1;
      while(j < t && list[j] < target)
	{
	  printf("3");
	  if (list[i] + list[j] == target)
	    {
	      s[0] = i;
	      s[1] = j;
	    }
	  j++;
	}
      i++;
    }
  printf("%d", s[0]);
  printf("%d", s[1]);
  
  return(s);
  free(s);
}

int main()
{
  int list[] = {2,7,11,15};
  FindTarget(list, 4, 17);
  return 0;
}




