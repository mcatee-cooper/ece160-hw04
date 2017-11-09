#include <stdio.h>
#include <stdlib.h>

/* padraic mcatee | hw03 | ece160 */

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3,
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  char *year;
} Student;

void print_student(Mode m, Student s){
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
    case MAJOR_AND_NAME:
      printf("%s %s %s\n", s.major, s.first_name, s.last_name);
      break;
    case YEAR_AND_NAME:
      printf("%s %s %s\n", s.year, s.first_name, s.last_name);
      break;
    case YEARS_LEFT_AND_NAME: 
      printf("%d %s %s\n", (atoi(s.year)-2017), s.first_name, s.last_name);
      break;
  }
}


void main(int argc, char *argv[]) {

  FILE *fp = fopen(argv[1], "r");
  char ch;
  int num_lines = 0;
  while(!feof(fp)) {
    ch = fgetc(fp);
    if(ch == '\n') {
      num_lines++;
    }
  }
  fclose(fp);
  FILE *fpp = fopen(argv[1],"r");
  char *buffer = malloc(256);
  Student s[num_lines];
  Student sx;
  int i = 0;
  while((fgets(buffer,255,fp)) != NULL){
    sx.first_name = malloc(256);
    sx.last_name = malloc(256);
    sx.major = malloc(256);
    sx.year = malloc(256);
    sscanf(buffer, "%s %s %s %s", sx.first_name, sx.last_name, sx.major, sx.year);
    s[i] = sx;
    i++;
  }
  int idx,mode;
  while(fgets(buffer,255,stdin))
    {
      if(sscanf(buffer, "%d %d\n", &idx, &mode) == 2)
	{
	  Mode m = mode;
	  if(m>3 || m < 0)
	    printf("Error: Invalid Mode\n");
	  if(idx>num_lines || idx<0)
	    printf("Error: Invalid Index\n");
	  else
	    print_student(m,s[idx]);
	}
      else
	printf("Error:Invalid Input\n");
    }
}
