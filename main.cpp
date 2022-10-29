#include <bits/stdc++.h>

using namespace std;

#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x45
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x49
#define VK_J 0x4A
#define VK_K 0x4B
#define VK_L 0x4C
#define VK_M 0x4D
#define VK_N 0x4E
#define VK_O 0x4F
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x55
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5A
struct GAMEINFO {
COORD PlayerOnePosition;
COORD PlayerTwoPosition;
COORD PlayerOneBullet;
COORD PlayerTwoBullet;
COORD PlayerOneBullet2;
COORD PlayerTwoBullet2;
COORD ZeroZero;
};
HANDLE hInput, hOutput;
GAMEINFO GameInfo;
void Movement(GAMEINFO &GameInfo);
void Draw(GAMEINFO);
void Erase(GAMEINFO);
int LaunchBullet(GAMEINFO &GameInfo, int);
void LaunchBullet2(GAMEINFO &GameInfo, int);
int Wait();
int main()
{
GAMEINFO GameInfo;
hInput = GetStdHandle(STD_INPUT_HANDLE);
hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleMode(hOutput, ENABLE_PROCESSED_INPUT);
GameInfo.PlayerOnePosition.X = 19;
GameInfo.PlayerOnePosition.Y = 12;
GameInfo.PlayerTwoPosition.X = 61;
GameInfo.PlayerTwoPosition.Y = 12;
GameInfo.PlayerOneBullet.X = 0;
GameInfo.PlayerOneBullet.Y = 0;
GameInfo.PlayerTwoBullet.X = 79;
GameInfo.PlayerTwoBullet.Y = 0;
GameInfo.PlayerOneBullet2.X = 1;
GameInfo.PlayerOneBullet2.Y = 0;
GameInfo.PlayerTwoBullet2.X = 78;
GameInfo.PlayerTwoBullet2.Y = 0;
GameInfo.ZeroZero.X = 0;
GameInfo.ZeroZero.Y = 0;
int i;
GameInfo.ZeroZero.Y = 24;
for(i = 0; i < 79; i++){
SetConsoleCursorPosition(hOutput, GameInfo.ZeroZero);
cout << ".";
GameInfo.ZeroZero.X++;
}
Draw(GameInfo);
while(1){
Movement(GameInfo);
}
return 0;
}
void Movement(GAMEINFO &GameInfo)
{ 
INPUT_RECORD InputRecord;
DWORD Events = 0;
}