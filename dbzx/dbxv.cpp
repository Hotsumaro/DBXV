#include "stdafx.h"
#include "dbxv.h"
#include <stdio.h>

DWORD BaseAddress = (DWORD)GetModuleHandle(L"DBXV.exe");
DWORD MoneyAddress = (*((DWORD*)(BaseAddress + 0x1A58FAC)) + 0x44);
int SlotOffset = 0x3BC;

void AddZeny(unsigned int zeny, unsigned int slot)
{
	DWORD* MoneyPointer = (DWORD*)MoneyAddress;
	*MoneyPointer = *MoneyPointer + zeny;
}

void AddAttributes(unsigned int num, unsigned int slot)
{
	DWORD* AttributePointer = (DWORD*)((MoneyAddress + 0x11878) + ((slot - 1) * SlotOffset));
	*AttributePointer += num;
}

void AddLevel(unsigned int num, unsigned int slot)
{
	DWORD* LvlPointer = (DWORD*)((MoneyAddress + 0x11870) + ((slot - 1) * SlotOffset));
	*LvlPointer += num;
}

void AddExperience(unsigned int num, unsigned int slot)
{
	DWORD* ExpPointer = (DWORD*)((MoneyAddress + 0x11874) + ((slot - 1) * SlotOffset));
	*ExpPointer += num;
}