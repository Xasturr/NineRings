#include "settings.h"

Settings::Settings()
{
	const int numOfParams = 5;
	int settingsArray[numOfParams] = { 0 };
	ifstream ifs;
	ifs.open("./settings/settings.txt", ios::in);
	if (ifs.is_open())
	{
		int i = 0;

		while (!ifs.eof())
		{
			string s;
			ifs >> s;
			if (i < numOfParams)
			{
				settingsArray[i] = stoi(s);
			}
			i++;
		}

		ifs.close();
	}
	else
	{
		cout << "Settings file doesn't exist" << endl;

		ofstream ofs;
		ofs.open("./settings/settings.txt", ios::out);
		if (ofs.is_open())
		{
			ofs << 22 << endl; //W
			ofs << 0 << endl; //A
			ofs << 3 << endl; //D
			ofs << 15 << endl; //P
			ofs << 57 << endl; //Space
		
			settingsArray[0] = 22;
			settingsArray[1] = 0;
			settingsArray[2] = 3;
			settingsArray[3] = 15;
			settingsArray[4] = 57;

			ofs.close();
		}
		else
		{
			cout << "Some problems" << endl;
			exit(EXIT_FAILURE);
		}
	}

	moveUp_ = settingsArray[0];
	moveLeft_ = settingsArray[1];
	moveRight_ = settingsArray[2];
	shoot_ = settingsArray[3];
	attack_ = settingsArray[4];
}

void Settings::setMoveUp(char c)
{
	if (c >= 65 && c <= 90 && isFree(c))
	{
		moveUp_ = c - 65;
		saveSattings();
	}
}

void Settings::setMoveLeft(char c)
{
	if (c >= 65 && c <= 90 && isFree(c))
	{
		moveLeft_ = c - 65;
		saveSattings();
	}
}

void Settings::setMoveRight(char c)
{
	if (c >= 65 && c <= 90 && isFree(c))
	{
		moveRight_ = c - 65;
		saveSattings();
	}
}

void Settings::setShoot(char c)
{
	if (c >= 65 && c <= 90 && isFree(c))
	{
		shoot_ = c - 65;
		saveSattings();
	}
}

void Settings::setAttack(char c)
{
	if (c >= 65 && c <= 90 && isFree(c))
	{
		shoot_ = c - 65;
		saveSattings();
	}
}

void Settings::saveSattings()
{
	ofstream ofs;
	ofs.open("./settings/settings.txt", ios::out);
	if (ofs.is_open())
	{
		ofs << moveUp_ << endl; 
		ofs << moveLeft_ << endl; 
		ofs << moveRight_ << endl; 
		ofs << shoot_ << endl; 
		ofs << attack_ << endl;

		ofs.close();
	}
	else
	{
		cout << "Some problems" << endl;
		exit(EXIT_FAILURE);
	}
}

int Settings::getMoveUp()
{
	return moveUp_;
}

int Settings::getMoveLeft()
{
	return moveLeft_;
}

int Settings::getMoveRight()
{
	return moveRight_;
}

int Settings::getShoot()
{
	return shoot_;
}

int Settings::getAttack()
{
	return attack_;
}

bool Settings::isFree(char c)
{
	if (moveUp_ == c - 65)
		return false;
	if (moveLeft_ == c - 65)
		return false;
	if (moveRight_ == c - 65)
		return false;
	if (shoot_ == c - 65)
		return false;

	return true;
}