#include "level2.h"

Level2::Level2()
{
	map_ = new Map1();
}

Level2::~Level2()
{
	cout << "In Level2 distructor" << endl;

	for (int i = 0; i < enemies_.size(); i++)
	{
		delete enemies_.at(i);
	}

	delete map_;
}

const size_t Level2::getHeightMap()
{
	if (!map_)
	{
		cout << "Map == nullptr" << endl;
		//return 0;
	}
	return map_->getHeightMap();
}

const size_t Level2::getWidthMap()
{
	return map_->getWidthMap();
}

const size_t Level2::getTileWidth()
{
	return map_->getTileWidth();
}

const size_t Level2::getTileHeight()
{
	return map_->getTileHeight();
}

string* Level2::getTileMapElse()
{
	return map_->getTileMapElse();
}

string* Level2::getTileMapTreasure()
{
	return map_->getTileMapTreasure();
}

bool Level2::getValue(int i, int j, char c, string tileMap[])
{
	if (tileMap[i][j] == c)
	{
		return true;
	}

	return false;
}

bool Level2::getCollision(int i, int j, char c)
{
	if (map_->getCollision(i, j, c))
	{
		return true;
	}

	return false;
}

bool Level2::getInSaveZone()
{
	return map_->getInSaveZone();
}

//Texture Level2::getTexture()
//{
//	return map_->getTexture();
//}

Sprite Level2::getSprite(int i, int j, string tileMap)
{
	return map_->getSprite(i, j, tileMap);
}

size_t Level2::getTextureSizeX()
{
	return map_->getTextureSizeX();
}

size_t Level2::getTextureSizeY()
{
	return map_->getTextureSizeY();
}

void Level2::buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize, int playerWidth, int playerHeight, float elapsedTime)
{
	map_->buildMap(window, playerPos, viewSize, playerWidth, playerHeight, elapsedTime);
}

void Level2::updateAndDrawEnemies(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime)
{
	int eraseEnemy = -1;

	for (int i = 0; i < enemies_.size(); i++)
	{
		if (enemies_[i]->getEnemyLife())
		{
			Vector2f oldEnemyPosition = enemies_[i]->getPosition();
			enemies_[i]->updatePosition(elapsedTime);
			//enemies_[i]->calculateVariables(elapsedTime);
			enemies_[i]->decision(elapsedTime, player);
			enemies_[i]->interactionWithMap(oldEnemyPosition, map_, elapsedTime);
			enemies_[i]->draw(window, player, viewSize, elapsedTime);
			int damage = player->flyingShellsMakeDamage(enemies_[i]->getPosition(), enemies_[i]->getWidth(), enemies_[i]->getHeight());
			if (damage > 0)
			{
				enemies_[i]->setCurrHealthPoints(enemies_[i]->getCurrHealthPoints() - damage);
				enemies_[i]->setHurt(true);
			}
		}
		else
		{
			eraseEnemy = i;
		}
	}

	if (eraseEnemy != -1)
	{
		enemies_.erase(enemies_.begin() + eraseEnemy);
	}
}

void Level2::setTreasurePoints(int treasurePoints)
{
	map_->setTreasurePoints(treasurePoints);
}

Map* Level2::getMap()
{
	return map_;
}

int Level2::getLevelNumber()
{
	return 2;
}

int Level2::getCatchedCoins()
{
	return map_->getCatchedCoins();
}

int Level2::getTreasurePoints()
{
	return map_->getTreasurePoints();
}

Vector2i Level2::getSavedPosition()
{
	return map_->getSavedPosition();
}