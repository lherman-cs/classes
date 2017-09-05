/*
   2-maze program
   Lukas Herman (lukash)
   April 22, 2017
   This program is to solve the maze problem
*/

#include <stdio.h>
#include <iostream>

using namespace std;

#define X_DIM 6
#define Y_DIM 6

struct coord_type
{
   int y;
   int x;
}  path [Y_DIM * X_DIM];

int maze[Y_DIM][X_DIM];
int visited[Y_DIM][X_DIM];

int starty, startx;      // (y, x) start coordinates
int targety, targetx;    // (y, x) target coordinates
int truelen;             // true length of the path

void print_path(int len)
{
   int i;

   printf("\n");
   for(i = 0; i <= len; i++){
      printf("%d (%d, %d )\n", i, path[i].y, path[i].x);
   }

}


void read_maze(void)
{
   int i = 0;
   int *loc = maze[0];

   while (i < X_DIM * Y_DIM)
   {
      cin >> *loc;
      loc += 1;
      i += 1;
   }
   cin >> starty  >> startx;
   cin >> targety >> targetx;
}

int legal_move(int y, int x)
{
   if(y >= 0 && y < Y_DIM &&
      x >= 0 && x < X_DIM &&
      maze[y][x] == 0 && visited[y][x] == 0)
        return 1;
   return 0;
}

int build_path(int pathlen, int y, int x)
{
   int rc = 0;
   visited[y][x] = 1;
   fprintf(stderr, "visiting %d %d with pathlen %d \n", y, x, pathlen);
   path[pathlen].y = y;
   path[pathlen].x = x;
   if(y == targety && x == targetx){
      fprintf(stderr, "\nfound the target at %d %d\n", y, x);
      truelen = pathlen;
      return 1;
   }

   /* Haven't reached the target so need to press onward */
   if(legal_move(y, x+1))
      rc = build_path(pathlen+1, y, x+1);
   if(!rc && legal_move(y+1, x))
      rc = build_path(pathlen+1, y+1, x);
   if(!rc && legal_move(y, x-1))
      rc = build_path(pathlen+1, y, x-1);
   if(!rc && legal_move(y-1, x))
      rc = build_path(pathlen+1, y-1,x);

   if(rc)
      return 1;

   /* Hit a dead end... back up one spot */
   else{
      fprintf (stderr, "stuck at %d %d backing up \n", y, x);
      return 0;
   }
}



int main()
{
   int pathlen = 0;

   read_maze();

   pathlen = build_path(pathlen, starty, startx);

   if (pathlen > 0)
      print_path(truelen);
   else
      cout << "Couldn't get there from here \n";

}
