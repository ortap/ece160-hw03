#include <stdio.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major;
  char *year;
  // (Done!) TODO: add fields here for major and year
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
      printf("%s %s %s\n", s.year, s.first_name, s.last_name);
      break;
    
	// (Done!) TODO: handle other cases
  }
}

/*
	argv[1] will be the Mode integer
	argv[2...] will be student info in the form [first_name, last_name, major, year]
	the fields are all strings (char[])
	except year is a number (int)
*/
void main(int argc, char *argv[]) {
  // TODO: parse argv to populate student structs 
  // for now, here's two hardcoded students:
  // Declarations
  Student s[argc-2];
  Mode mode = atoi(argv[1]);
  int i,j=0;
  for(int i=2; i<= argc-3; i+=4){
    s[j].first_name = argv[i];
    s[j].last_name = argv[i+1];
    s[j].major = argv[i+2];
    s[j].year = argv[i+3];
    print_student(mode, s[j]);
    j++;
  }
}
