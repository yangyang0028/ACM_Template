#include <stdio.h>
#include <string.h>

char a[35][35][35];
int b[35][35][35];
int time = 0, l, r, c, sh, si, sj, eh, ei, ej;

int Judge(int h, int i, int j) {
  int f = 0;
  if(h <0 || i <0 || j <0 || h >= l || i >= r || j >= c) f = 1;
  else if(a[h][i][j] == '#') f = 1;
    else if(b[h][i][j]) f = 1;
  return f;
}

void  bl(int x, int y, int z) {
    x ++;
    if(!Judge(x, y, z)) b[x][y][z] = time + 1;
    x -= 2;
    if(!Judge(x, y, z)) b[x][y][z] = time + 1;
    x ++;
    y ++;
    if(!Judge(x, y, z)) b[x][y][z] = time + 1;
    y -= 2;
    if(!Judge(x, y, z)) b[x][y][z] = time + 1;
    y ++;
    z ++;
    if(!Judge(x, y, z)) b[x][y][z] = time + 1;
    z -= 2;
    if(!Judge(x, y, z)) b[x][y][z] = time + 1;
  }

int Bfs() {
  int h, i, j;
  if(b[eh][ei][ej]) return b[eh][ei][ej];
  time ++;
  for (h = 0; h < l; h ++) {
    for (i = 0; i < r; i ++) {
      for(j = 0; j < c; j ++) {
        if(b[h][i][j] == time) bl(h, i, j);
      }
    }
  }
  if(time > 10000) return 0;
  Bfs();
}

int main(int argc, char const *argv[]) {
  while (scanf("%d %d %d", &l, &r, &c) && l != 0) {
    time = 0;
    memset(a, '#', sizeof(a));
    memset(b, 0, sizeof(b));
    for (int h = 0; h < l; h ++) {
      for (int i = 0; i < r; i ++) {
        scanf("%s", a[h][i]);
        for(int j = 0;j < c;j ++) {
          if(a[h][i][j] == 'S')	sh = h, si = i, sj = j;
          if(a[h][i][j] == 'E')	eh = h, ei = i, ej = j;
				}
      }
      getchar();
    }
    bl(sh, si, sj);
    if(Bfs()) printf("Escaped in %d minute(s).\n", b[eh][ei][ej]);
    else printf("Trapped!\n");
  }
  return 0;
}
