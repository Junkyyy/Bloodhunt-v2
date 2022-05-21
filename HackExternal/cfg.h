#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include "singleton.h"
#include "imgui/imgui.h"
#include <map>

DWORD keys[] = { VK_LMENU, VK_MENU, VK_SHIFT, VK_RSHIFT, VK_CONTROL, VK_RCONTROL, VK_LBUTTON, VK_RBUTTON,VK_XBUTTON1,VK_XBUTTON2 };
const char* keyItems[] = { "LAlt", "RAlt", "LShift", "RShift", "LControl", "RControl", "LMouse", "RMouse","Mousebutton1", "Mousebutton2"};

inline namespace Configuration
{
	class Settings : public Singleton<Settings>
	{
	public:

		const char* BoxTypes[2] = { "Full Box","Cornered Box" };
		const char* LineTypes[3] = { "Bottom To Enemy","Top To Enemy","Crosshair To Enemy" };
		

		bool b_MenuShow = true;


		bool b_Visual = true;
		bool b_EspBox = false;
		bool b_EspSkeleton = true;
		bool b_EspLine = false;
		bool b_EspDistance = true;
		bool b_EspHealth  = true;
		bool b_EspName = false;
		bool b_type1 = false;
		bool bspread = false;

		bool b_Aimbot = true;
		bool b_AimbotFOV = true;
		bool b_AimbotSmooth = true;
		bool b_TeamCheck = true;
		bool b_reload = false;
		bool b_fastres = false;
		bool b_NoRecoil = true;
		bool b_Rapidfire = false;
		bool b_Fastreload = false;
		bool b_radar = false;
		bool b_eac1 = false;
		bool b_test1 = false;
		bool NoSpread = true;


		ImColor VisibleColor = ImColor(255.f / 255, 0.f, 0.f);
		float fl_VisibleColor[3] = { 0.f,255.f / 255,0.f };  //

		ImColor InvisibleColor = ImColor(0.f, 255.f / 255, 0.f);
		float fl_InvisibleColor[3] = { 255.f / 255,0.f,0.f };  //

		ImColor FovColor = ImColor(255.f / 255, 0.f, 0.f);
		float fl_FovColor[3] = { 255.f / 255,0.f,0.f };  //

		int BoxType = 0;
		int LineType = 0;
		int tab_index = 0;
		int AimKey = 7;

		float Smoothing = 8.0f;
		float AimbotFOV = 70.0f;
		float max_distance = 500.0f;
		//float Firerate = 100.0f;
	
	};
#define CFG Configuration::Settings::Get()
}
bool GetAimKey()
{
	return GetAsyncKeyState(keys[CFG.AimKey]);
}
