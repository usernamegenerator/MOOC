/*
 * lifegame.c
 *
 *  Created on: Jan 7, 2010
 *      Author: Daniel Weller
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "lifegame.h"

/* hard-coded world size */
#define WORLDWIDTH 39
#define WORLDHEIGHT 20

/* character representations of cell states */
#define CHAR_ALIVE '*'
#define CHAR_DEAD ' '

/* current cell states of the world */
static int world[WORLDWIDTH][WORLDHEIGHT];

/* next generation cell states */
static int nextstates[WORLDWIDTH][WORLDHEIGHT];

/* functions to write for Part B of lab */
void initialize_world_from_file(const char * filename) {
	/* TODO: read the state of the world from a file with
	   name "filename". Assume file exists, is readable, and
	   the ith character of the jth line (zero-indexed) describes
	   world[i][j] according to the characters CHAR_ALIVE and
	   CHAR_DEAD

	   Assume a line does not contain more than 256 characters
	   (including newline). If a line doesn't contain WORLDWIDTH
	   characters, remaining cells in line are presumed DEAD.
	   Similarly, if the file does not contain WORLDHEIGHT lines,
	   remaining lines are presumed dead.

	   On error, print some useful error message and call abort().

	   Also need to reset the next generation to DEAD
	 */

	FILE * pfile;
	int i = 0, j = 0, len;
	char strread[256];

	if ((pfile = fopen(filename, "r")) == NULL) {
		fprintf(stderr,"Error: unable to read \"%s\" (error #%d).\n",
				filename, errno);
		abort();
	}

	while (j < WORLDHEIGHT && !feof(pfile) &&
			fgets(strread, 256, pfile) != NULL) {
		/* jth line read */
		len = strlen(strread);
		if (len > WORLDWIDTH)
			len = WORLDWIDTH; /* ignore extra chars */
		for (i = 0; i < len; i++)
			world[i][j] = strread[i] == CHAR_ALIVE ? ALIVE : DEAD;

		/* take care of unspecified cells in row */
		for (;i < WORLDWIDTH; i++)
			world[i][j] = DEAD;
		j++; /* next line */
	}

	/* take care of unspecified last lines */
	for (; j < WORLDHEIGHT; j++)
		for (i = 0; i < WORLDWIDTH; i++)
			world[i][j] = DEAD;

	/* initialize next generation to DEAD */
	for (i = 0; i < WORLDWIDTH; i++)
		for (j = 0; j < WORLDHEIGHT; j++)
			nextstates[i][j] = DEAD;

	fclose(pfile);
}

void save_world_to_file(const char * filename) {
	/* TODO: write the state of the world into a file with
	   name "filename". Assume the file can be created, or if
	   the file exists, overwrite the file. The ith character
	   of the jth line (zero-indexed) describes world[i][j]
	   using the characters CHAR_ALIVE and CHAR_DEAD

	   This file should be readable using the function
	   initialize_world_from_file(filename) above; we can use
	   it to resume a game later
	 */

	FILE * pfile;
	int i, j;
	char strwrite[WORLDWIDTH+1];

	if ((pfile = fopen(filename, "w")) == NULL) {
		fprintf(stderr,"Error: unable to open \"%s\" for writing (error #%d).\n",
				filename, errno);
		abort();
	}

	strwrite[WORLDWIDTH] = '\0'; /* null terminator */
	for (j = 0; j < WORLDHEIGHT; j++) {
		for (i = 0; i < WORLDWIDTH; i++)
			strwrite[i] = world[i][j] == ALIVE ? CHAR_ALIVE : CHAR_DEAD;
		fprintf(pfile,"%s\n",strwrite);
	}

	fclose(pfile);
}

/* you shouldn't need to edit anything below this line */

/* initializes the world to a hard-coded pattern, and resets
   all the cells in the next generation to DEAD */
void initialize_world(void) {
	int i, j;

	for (i = 0; i < WORLDWIDTH; i++)
		for (j = 0; j < WORLDHEIGHT; j++)
			world[i][j] = nextstates[i][j] = DEAD;
	/* pattern "glider" */
	world[1][2] = ALIVE;
	world[3][1] = ALIVE;
	world[3][2] = ALIVE;
	world[3][3] = ALIVE;
	world[2][3] = ALIVE;
}

int get_world_width(void) {
	return WORLDWIDTH;
}

int get_world_height(void) {
	return WORLDHEIGHT;
}

int get_cell_state(int x, int y) {
	if (x < 0 || x >= WORLDWIDTH || y < 0 || y >= WORLDHEIGHT)
		return DEAD;
	return world[x][y];
}

void set_cell_state(int x, int y, int state) {
	if (x < 0 || x >= WORLDWIDTH || y < 0 || y >= WORLDHEIGHT) {
		fprintf(stderr,"Error: coordinates (%d,%d) are invalid.\n",
				x, y);
		abort();
	}
	nextstates[x][y] = state;
}

void finalize_evolution(void) {
	int x, y;
	for (x = 0; x < WORLDWIDTH; x++) {
		for (y = 0; y < WORLDHEIGHT; y++) {
			world[x][y] = nextstates[x][y];
			nextstates[x][y] = DEAD;
		}
	}
}

void output_world(void) {
	char worldstr[2*WORLDWIDTH+2];
	int i, j;

	worldstr[2*WORLDWIDTH+1] = '\0';
	worldstr[0] = '+';
	for (i = 1; i < 2*WORLDWIDTH; i++)
		worldstr[i] = '-';
	worldstr[2*WORLDWIDTH] = '+';
	puts(worldstr);
	for (i = 0; i <= 2*WORLDWIDTH; i+=2)
		worldstr[i] = '|';
	for (i = 0; i < WORLDHEIGHT; i++) {
		for (j = 0; j < WORLDWIDTH; j++)
			worldstr[2*j+1] = world[j][i] == ALIVE ? CHAR_ALIVE : CHAR_DEAD;
		puts(worldstr);
	}
	worldstr[0] = '+';
	for (i = 1; i < 2*WORLDWIDTH; i++)
		worldstr[i] = '-';
	worldstr[2*WORLDWIDTH] = '+';
	puts(worldstr);
}
