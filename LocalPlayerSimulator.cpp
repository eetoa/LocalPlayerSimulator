// LocalPlayerSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "LocalPlayerSimulator.h"

CPlayer::CPlayer(int health, vec3d pos, int skill) : health(health), pos(pos), skill(skill){}
CPlayer::~CPlayer(){}

static int g_health, g_skill;
static vec3d g_pos;

int main()
{
    __asm {
		mov eax, eax
		mov eax, eax
		mov eax, eax
		mov eax, eax
		mov eax, eax
		mov eax, eax
    }

	bool isAddSkill = false;
	bool isGetHurt = false;
	bool isMoving = false;

    CPlayer cplayer(100, { 0, 0, 0 }, 120);
	std::cout << "LocalPlayer Generated." << std::endl << std::endl;
	
	std::cout << "Health: " << cplayer.health << " Skill:" << cplayer.skill << " Pos.x: " << cplayer.pos.x
		<< " Pos.y: " << cplayer.pos.y << " Pos.z: " << cplayer.pos.z << std::endl;

	std::cout << "LocalPlayer Address: " << std::hex << &cplayer << std::endl;
	std::cout << std::dec << std::endl;

	while (1) {
		Sleep(30);

		/*
		g_health = cplayer.health;
		g_skill = cplayer.skill;
		g_pos = cplayer.pos;
		*/

		isAddSkill = GetAsyncKeyState(VK_INSERT) & 1;
		isGetHurt = GetAsyncKeyState(VK_DELETE) & 1;
		isMoving = GetAsyncKeyState(VK_CONTROL) & 1;
		if (isAddSkill) {
			cplayer.skill++;
			std::cout << "Health: " << cplayer.health << " Skill:" << cplayer.skill << " Pos.x: " << cplayer.pos.x
				<< " Pos.y: " << cplayer.pos.y << " Pos.z: " << cplayer.pos.z << std::endl;
			isAddSkill = !isAddSkill;
		}
		if (isGetHurt) {
			cplayer.health--;
			std::cout << "Health: " << cplayer.health << " Skill:" << cplayer.skill << " Pos.x: " << cplayer.pos.x
				<< " Pos.y: " << cplayer.pos.y << " Pos.z: " << cplayer.pos.z << std::endl;
			isGetHurt = !isGetHurt;
		}
		if (isMoving) {
			cplayer.pos.x ++;
			cplayer.pos.y++;
			cplayer.pos.z++;
			std::cout << "Health: " << cplayer.health << " Skill:" << cplayer.skill << " Pos.x: " << cplayer.pos.x
				<< " Pos.y: " << cplayer.pos.y << " Pos.z: " << cplayer.pos.z << std::endl;
			isMoving = !isMoving;
		}
	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
