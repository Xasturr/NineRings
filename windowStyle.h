#pragma once

static class WindowStyle
{
	string closeWindow_ = "Close";
	string defaultWindow_ = "Default";
	string fullscreenWindow_ = "Fullscreen";
	string noneWindow_ = "None";
	string resizeWindow_ = "Resize";
	string titlebarWindow_ = "Titlebar";
public:
	string getCloseWindow();
	string getdefaultWindow();
	string getFullscreenWindow();
	string getNoneWindow();
	string getResizeWindow();
	string getTitlebarWindow();
};