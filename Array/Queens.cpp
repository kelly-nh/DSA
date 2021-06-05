#include <iostream>
using namespace std;

bool isMaxOnDirection(int a[100][100], int& n, int cur_row, int cur_col, int stepX, int stepY) {
  int i = cur_row;
  int j = cur_col;

  while (i >= 0 && i < n && j >= 0 && j < n) {
    
    if (a[cur_row][cur_col] < a[i][j])
      return false;
    i += stepX;
    j += stepY;
  }
  return true;
}

bool isQueen(int arr[100][100], int& n, int cur_row, int cur_col) {
  bool direction_1 = isMaxOnDirection(arr,n,cur_row,cur_col,0,1);
  bool direction_2 = isMaxOnDirection(arr,n,cur_row,cur_col,0,-1);
  bool direction_3 = isMaxOnDirection(arr,n,cur_row,cur_col,1,1);
  bool direction_4 = isMaxOnDirection(arr,n,cur_row,cur_col,-1,-1);
  bool direction_5 = isMaxOnDirection(arr,n,cur_row,cur_col,-1,1);
  bool direction_6 = isMaxOnDirection(arr,n,cur_row,cur_col,1,0);
  bool direction_7 = isMaxOnDirection(arr,n,cur_row,cur_col,-1,0);
  bool direction_8 = isMaxOnDirection(arr,n,cur_row,cur_col,1,-1);

  return direction_1 && direction_2 && direction_3 && direction_4 && direction_5 && direction_6 && direction_7 && direction_8;
}

int main() {
  int n;
  int a[100][100];
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (isQueen(a, n, i, j)) {
        cnt++;
      }
    }
  }

  cout << cnt;
  return 0;
}