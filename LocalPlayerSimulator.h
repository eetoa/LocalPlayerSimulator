#pragma once
#include <iostream>
#include <Windows.h>


typedef struct
{
	int x, y, z;
} vec3d;


class CPlayer 
{
public:
	CPlayer(int health, vec3d pos, int skill);
	~CPlayer();

	int health;
	int skill;
	vec3d pos;

private:
};