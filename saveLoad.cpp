#include "saveLoad.h"

bool SaveLoad::checkSavePosition(Player* player)
{
	return true;
}

void SaveLoad::save(Level* level, Player* player)
{
	cout << "saving..." << endl;
	ofs.open("./save/save.txt", ios::out);
	if (ofs.is_open())
	{
		ofs << level->getLevelNumber() << endl;
		ofs << level->getSavedPosition().x * level->getTileWidth() << endl; 
		ofs << level->getSavedPosition().y * level->getTileHeight() << endl; 
		ofs << player->getCurrHealthPoints() << endl;
		ofs << player->getCurrMana() << endl;
		ofs << player->getCurrStamina() << endl;
		ofs << player->getCurrLevel() << endl;
		ofs << player->getCurrExp() << endl;
		ofs << player->getMaxHealthPoints() << endl;
		ofs << player->getMaxMana() << endl;
		ofs << player->getMaxStamina() << endl;
		ofs << level->getTreasurePoints() << endl;
		for (int i = 0; i < level->getHeightMap(); i++)
		{
			for (int j = 0; j < level->getWidthMap(); j++)
			{
				if (level->getTileMapTreasure()[i][j] == 'x')
				{
					ofs << i << "&" << j << "|";
				}
			}
		}
		ofs << endl;
		ofs << player->getLevelPoints() << endl;
		ofs << "false" << endl; //new game
		ofs << player->getCurrIceBallPerkLevel() << endl;
		ofs << player->getCurrFoamyDiscPerkLevel() << endl;
		ofs << player->getCurrJugglerPerkLevel() << endl;
		ofs << player->getCurrDrippingBladePerkLevel() << endl;
		ofs << player->getCurrHalfDeadPerkLevel() << endl;

		ofs.close();
	}
	else
	{
		cout << "Problems while saving" << endl;
	}
}

void SaveLoad::load(Level** level, Player** player)
{
	cout << "loading" << endl;

	ifs.open("./save/save.txt", ios::in);
	if (ifs.is_open())
	{
		int i = 0;

		while (!ifs.eof())
		{
			string s;
			ifs >> s;

			if (i == 0)
			{
				if (s == "1")
				{
					*level = new Level1();
				}
				else if (s == "2")
				{
					*level = new Level2();
				}
			}
			else if (i == 1)
			{
				*player = new Player("Character1", 0, 0);
				(*player)->setPosition(stoi(s), 0);
			
			}
			else if (i == 2)
			{
				(*player)->setPosition((*player)->getCurrPosition().x, stoi(s));
			}
			else if (i == 3)
			{
				(*player)->setCurrHealthPoints(stoi(s));
			}
			else if (i == 4)
			{
				(*player)->setCurrMana(stoi(s));
			}
			else  if (i == 5)
			{
				(*player)->setCurrStamina(stoi(s));
			}
			else if (i == 6)
			{
				(*player)->setCurrLevel(stoi(s));
			}
			else if (i == 7)
			{
				(*player)->setCurrExp(stoi(s));
			}
			else if (i == 8)
			{
				(*player)->setMaxHealthPoints(stoi(s));
			}
			else if (i == 9)
			{
				(*player)->setMaxMana(stoi(s));
			}
			else if (i == 10)
			{
				(*player)->setMaxStamina(stoi(s));
			}
			else if (i == 11)
			{
				(*level)->setTreasurePoints(stoi(s));
			}
			else if (i == 12)
			{
				for (int i = 0; i < (*level)->getHeightMap(); i++)
				{
					for (int j = 0; j < (*level)->getWidthMap(); j++)
					{
						if ((*level)->getTileMapTreasure()[i][j] == 'x')
						{
							(*level)->getTileMapTreasure()[i][j] = ' ';
						}
					}
				}

				const int tempStrSize = 4;
				char tempStr[tempStrSize];
				int temp = 0;
				const char* str = s.c_str();
				int posX = 0;
				int posY = 0;
				for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
				{
					if (str[i] == '&')
					{
						posX = atoi(tempStr);
						temp = 0;
					}
					else if (str[i] == '|')
					{
						tempStr[temp] = '\0';
						posY = atoi(tempStr);
						temp = 0;
						cout << "\nposX: " << posX << endl;
						cout << "posY: " << posY << endl << endl;
						(*level)->getTileMapTreasure()[posX][posY] = 'x';
					}
					else
					{
						tempStr[temp++] = str[i];
					}
					cout << str[i];
				}
			}
			else if (i == 13)
			{
				(*player)->setLevelPoints(stoi(s));
			}
			else if (i == 14)
			{
				if (s == "true")
				{
					(*player)->setNewGame(true);
				}
				else
				{
					(*player)->setNewGame(false);
				}
			}
			else if (i == 15)
			{
				(*player)->setIceBallPerkLevel(stoi(s));
			}
			else if (i == 16)
			{
				(*player)->setFoamyDiscPerkLevel(stoi(s));
			}
			else if (i == 17)
			{
				(*player)->setJugglerPerkLevel(stoi(s));
				cout << "Juggler perk level: " << s << endl;
			}
			else if (i == 18)
			{
				(*player)->setDrippingBladePerkLevel(stoi(s));
			}
			else if (i == 19)
			{
				(*player)->setHalfDeadPerksLevel(stoi(s));
			}
			i++;
		}

		ifs.close();
	}
	else
	{
		cout << "Save file doesn't exist" << endl;
		ofs.open("./save/save.txt", ios::out);
		if (ofs.is_open())
		{
			*level = new Level1();
			*player = new Player("Character1", 2 * 64, 2 * 64);
			ofs << (*level)->getLevelNumber() << endl;
			ofs << 2 * (*level)->getTileWidth() << endl;
			ofs << 2 * (*level)->getTileHeight() << endl;
			ofs << (*player)->getCurrHealthPoints() << endl;
			ofs << (*player)->getCurrMana() << endl;
			ofs << (*player)->getCurrStamina() << endl;
			ofs << (*player)->getCurrLevel() << endl;
			ofs << (*player)->getCurrExp() << endl;
			ofs << (*player)->getMaxHealthPoints() << endl;
			ofs << (*player)->getMaxMana() << endl;
			ofs << (*player)->getMaxStamina() << endl;
			ofs << (*level)->getTreasurePoints() << endl;
			for (int i = 0; i < (*level)->getHeightMap(); i++)
			{
				for (int j = 0; j < (*level)->getWidthMap(); j++)
				{
					if ((*level)->getTileMapTreasure()[i][j] == 'x')
					{
						ofs << i << "&" << j << "|";
					}
				}
			}
			ofs << endl;
			ofs << (*player)->getLevelPoints() << endl;
			ofs << "true" << endl; //new game
			ofs << (*player)->getCurrIceBallPerkLevel() << endl;
			ofs << (*player)->getCurrFoamyDiscPerkLevel() << endl;
			ofs << (*player)->getCurrJugglerPerkLevel() << endl;
			ofs << (*player)->getCurrDrippingBladePerkLevel() << endl;
			ofs << (*player)->getCurrHalfDeadPerkLevel() << endl;

			ofs.close();
			cout << "Save file created" << endl;
		}
		else
		{
			cout << "Problems while creating save file" << endl;
		}
	}
}

void SaveLoad::loadNewGame(Level** level, Player** player)
{
	ofs.open("./save/save.txt", ios::out);
	if (ofs.is_open())
	{
		*level = new Level1();
		*player = new Player("Character1", 2 * 64, 2 * 64);
		ofs << (*level)->getLevelNumber() << endl;
		ofs << 2 * (*level)->getTileWidth() << endl;
		ofs << 2 * (*level)->getTileHeight() << endl;
		ofs << (*player)->getCurrHealthPoints() << endl;
		ofs << (*player)->getCurrMana() << endl;
		ofs << (*player)->getCurrStamina() << endl;
		ofs << (*player)->getCurrLevel() << endl;
		ofs << (*player)->getCurrExp() << endl;
		ofs << (*player)->getMaxHealthPoints() << endl;
		ofs << (*player)->getMaxMana() << endl;
		ofs << (*player)->getMaxStamina() << endl;
		ofs << (*level)->getTreasurePoints() << endl;
		for (int i = 0; i < (*level)->getHeightMap(); i++)
		{
			for (int j = 0; j < (*level)->getWidthMap(); j++)
			{
				if ((*level)->getTileMapTreasure()[i][j] == 'x')
				{
					ofs << i << "&" << j << "|";
				}
			}
		}
		ofs << endl;
		ofs << (*player)->getLevelPoints() << endl;
		ofs << "false" << endl; //new game
		ofs << (*player)->getCurrIceBallPerkLevel() << endl;
		ofs << (*player)->getCurrFoamyDiscPerkLevel() << endl;
		ofs << (*player)->getCurrJugglerPerkLevel() << endl;
		ofs << (*player)->getCurrDrippingBladePerkLevel() << endl;
		ofs << (*player)->getCurrHalfDeadPerkLevel() << endl;

		ofs.close();
		cout << "Save file created" << endl;
	}
	else
	{
		cout << "Problems while creating save file" << endl;
	}
}