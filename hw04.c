#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** padraic mcatee | hw04 | ece-160 ***/

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  int year;
  int tmp;
} Student;

void print_student(Mode m, Student s) {
  switch (m) {
  case NAME_ONLY:
    printf("%s %s\n", s.first_name, s.last_name);
    break;
  case MAJOR_AND_NAME:
    printf("%s %s %s\n", s.major, s.first_name, s.last_name);
    break;
  case YEAR_AND_NAME:
    printf("%d %s %s\n", s.year, s.first_name, s.last_name);
    break;
  case YEARS_LEFT_AND_NAME:
    printf("%d %s %s\n", s.year, s.first_name, s.last_name);
    break;
  }
}

int main(int argc, char* argv[]) {
  if (argc<2) {
    printf("Requires file to read!");
    return 0;
  }
  /* declarations */
  FILE *fp;
  char *line = malloc(256);
  char buf[256];
  char ch;
  int num_lines = 0;
  fp = fopen(argv[1],"r");
  
  while(!feof(fp)) {
    ch = fgetc(fp);
    if(ch == '\n') {
      num_lines++;
    }
  }
  Student s[num_lines];
  int i,j = 0;
  while (fgets(line,255,fp)) {
    /*
    sscanf(line,"%s %s %s %d",&s[i].first_name,&s[i].last_name,&s[i].major,&s[i].year);
    i++;*/
    i = 0;
    char* input;
    char* ptrbuf = line;
    while(input=strsep(&ptrbuf,"\n")) {
      s[j].tmp = 1;
      if(i == 0) {
	s[j].first_name = malloc(256);
	strcpy(s[j].first_name,input);
      }
      else if(i == 1) {
	s[j].last_name = malloc(256);
	strcpy(s[j].last_name,input);
      }
      else if(i == 2) {
	s[j].major = malloc(256);
	strcpy(s[j].major,input);
      }
      else if(i == 3) {
	s[j].year = malloc(256);
	strcpy(s[j].year,input);
      }
      i++;
    }
    j++;
  }
  /*while (1) {
    int idx,mode;
    scanf("%d %d ",&idx,&mode);
    Mode mode_name = mode;
    print_student(mode_name,s[idx]);
    }*/
  int idx, mode_tmp;
  while(fgets(buf,255,stdin)) {
    if(sscanf(buf,"%d %d\n",&idx,&mode_tmp)==2) {
      Mode m = mode_tmp;
      print_student(m,s[idx]);
    }
    else {
      printf("Unrecognized input");
    }
  }
  return 0;
}
