# include <stdio.h>
# include <stdlib.h>

int *SubString(char str[], size_t t){
  int* count = NULL;
  count = malloc(sizeof(int));
  count[0] = 0;
  char str1[t];
  size_t i = 0;
  str1[0] = str[0];
  printf("0");
  while(count != NULL && i<t){
    size_t j = 0;
    printf("1");
    while(j < i && str1[j] != str[i]){
      j++;
      printf("2");
      }
    if(str1[j] != str[i]){
	str1[j] = str[i];
	printf("3");
      }
    printf("%c", str1[j]);
    i++;
    ;
  }
  printf("4");
  return(count);
  free(count);
}

int main(){
  char list[] = "abcabcbb";
  printf("-1");
  size_t t = 8; 
  SubString(list,  t); 
}
