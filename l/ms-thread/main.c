#include <windows.h>
#include <stdio.h>

DWORD WINAPI ThreadFunc(void* data) {
  printf("Hej from thread (or hello world)\n");
  return 0;
}

int main() {
  printf("hej start \n");
  HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
  printf("sleep\n");
  Sleep(2000);
  printf("hej slut - parent is closing down\n");
  return(0);
}
