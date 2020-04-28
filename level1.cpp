#include "level1.h"

Level1::Level1()
{
	cout << "In Level1 constructor" << endl;
	map_ = new Map1();

	enemies_.push_back(new Enemy(Characters::Character1_name, 64 * 40, 64 * 11, new PhysxImplEnWalk(Characters::Character1_name)));
	enemies_.push_back(new Enemy(Characters::Character1_name, 64 * 52, 64 * 9, new PhysxImplEnWalk(Characters::Character1_name)));
	enemies_.push_back(new Enemy(Characters::Character1_name, 64 * 58, 64 * 8, new PhysxImplEnWalk(Characters::Character1_name)));
	enemies_.push_back(new Enemy(Characters::Character1_name, 64 * 60, 64 * 5, new PhysxImplEnWalk(Characters::Character1_name)));
	enemies_.push_back(new Enemy(Characters::Character1_name, 64 * 64, 64 * 7, new PhysxImplEnWalk(Characters::Character1_name)));
	enemies_.push_back(new Enemy(Characters::Character1_name, 64 * 74, 64 * 9, new PhysxImplEnWalk(Characters::Character1_name)));
	enemies_.push_back(new Enemy(Characters::Character1_name, 64 * 68, 64 * 22, new PhysxImplEnWalk(Characters::Character1_name)));
	enemies_.push_back(new Enemy(Characters::Character1_name, 64 * 33, 64 * 19, new PhysxImplEnWalk(Characters::Character1_name)));
	enemies_.push_back(new Enemy(Characters::CharacterBat_name, 64 * 60, 64 * 5, new PhysxImplEnFly(64 * 46, 64 * 78, Characters::CharacterBat_name)));
}

Level1::~Level1() 
{
	cout << "In Level1 distructor" << endl;

	for (int i = 0; i < enemies_.size(); i++)
	{
		delete enemies_.at(i);
	}

	delete map_;
}

const size_t Level1::getHeightMap()
{
	if (!map_)
	{
		cout << "Map == nullptr" << endl;
	}
	return map_->getHeightMap();

}

const size_t Level1::getWidthMap()
{
	return map_->getWidthMap();
}

const size_t Level1::getTileWidth()
{
	return map_->getTileWidth();
}

const size_t Level1::getTileHeight()
{
	return map_->getTileHeight();
}

string* Level1::getTileMapElse()
{
	return map_->getTileMapElse();
}

string* Level1::getTileMapTreasure()
{
	return map_->getTileMapTreasure();
}

bool Level1::getValue(int i, int j, char c, string tileMap[])
{
	if (tileMap[i][j] == c)
	{
		return true;
	}

	return false;
}

bool Level1::getCollision(int i, int j, char c)
{
	if (map_->getCollision(i, j, c))
	{
		return true;
	}

	return false;
}

bool Level1::getInSaveZone()
{
	return map_->getInSaveZone();
}

Sprite Level1::getSprite(int i, int j, string tileMap)
{
	return map_->getSprite(i, j, tileMap);
}

size_t Level1::getTextureSizeX()
{
	return map_->getTextureSizeX();
}

size_t Level1::getTextureSizeY()
{
	return map_->getTextureSizeY();
}

void Level1::buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize, int playerWidth, int playerHeight, float elapsedTime)
{
	map_->buildMap(window, playerPos, viewSize, playerWidth, playerHeight, elapsedTime);
}

void Level1::updateAndDrawEnemies(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime)
{
	int eraseEnemy = -1;

	for (int i = 0; i < enemies_.size(); i++)
	{
		enemies_[i]->flyingShellsUpdateAndDraw(elapsedTime, map_, window);
		int enDamage = enemies_[i]->flyingShellsMakeDamage(player->getCurrPosition(), player->getWidth(), player->getHeight());
		if (enDamage > 0)
		{
			cout << "enDamage: " << enDamage << endl << "plArmor: " << player->getArmor() << endl;
			player->setCurrHealthPoints(player->getCurrHealthPoints() - enDamage * (100 - player->getArmor()) / 100);
			player->setHurt(true);
			cout << "Player health: " << player->getCurrHealthPoints() << endl;
		}
		if (enemies_[i]->getEnemyLife())
		{
			Vector2f oldEnemyPosition = enemies_[i]->getPosition();
			enemies_[i]->updatePosition(elapsedTime);
			enemies_[i]->calculateVariables(elapsedTime);
			enemies_[i]->decision(elapsedTime, player);
			enemies_[i]->interactionWithMap(oldEnemyPosition, map_, elapsedTime);
			enemies_[i]->draw(window, player, viewSize, elapsedTime);
			int damage = player->flyingShellsMakeDamage(enemies_[i]->getPosition(), enemies_[i]->getWidth(), enemies_[i]->getHeight());
			if (damage > 0 && !enemies_[i]->getHurt())
			{
				cout << "Damage: " << damage << endl;
				int oldHp = enemies_[i]->getCurrHealthPoints();
				enemies_[i]->setCurrHealthPoints(enemies_[i]->getCurrHealthPoints() - damage);
				if (player->getCurrVampireDraculaPerkLevel() && player->getCurrHealthPoints() < player->getMaxHealthPoints())
				{
					player->setCurrHealthPoints(player->getCurrHealthPoints() + player->getVampireDraculaPerkBonus() * float(oldHp - enemies_[i]->getCurrHealthPoints()) / 100);
					if (player->getMaxHealthPoints() < player->getCurrHealthPoints())
					{
						player->setCurrHealthPoints(player->getMaxHealthPoints());
					}
				}
				enemies_[i]->setHurt(true);
				cout << "Enemy " << i << " health: " << enemies_[i]->getCurrHealthPoints() << endl;
			}
		}
		else
		{
			player->setCurrExp(player->getCurrExp() + enemies_[i]->getKillExp());
			if (enemies_[i]->getCurrFlyingShellsAmount() == 0)
			{
				eraseEnemy = i;
			}
		}
	}

	if (eraseEnemy != -1)
	{
		Enemy* en = enemies_.at(eraseEnemy);
		enemies_.erase(enemies_.begin() + eraseEnemy);
		delete en;
	}
}

void Level1::setTreasurePoints(int treasurePoints)
{
	map_->setTreasurePoints(treasurePoints);
}

Map* Level1::getMap()
{
	return map_;
}

int Level1::getLevelNumber()
{
	return 1;
}

int Level1::getCatchedCoins()
{
	return map_->getCatchedCoins();
}

int Level1::getTreasurePoints()
{
	return map_->getTreasurePoints();
}

Vector2i Level1::getSavedPosition()
{
	return map_->getSavedPosition();
}