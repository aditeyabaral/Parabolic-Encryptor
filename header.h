#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

int seed;
int sum;

void secret();
int parabola(int);
void encrypt(char*,char*);
int inv_parabola(int);
void decrypt();
void write_to_file(char*);
