#include "level1.h"

Level1::Level1()
{
	map_ = new Map1();

	enemies_.push_back(new Enemy("Character1", 1400, 230));
	enemies_.push_back(new Enemy("Character1", 100, 85));
	enemies_.push_back(new Enemy("Character1", 1700, 930));
	//enemies_.push_back(new Enemy("Character1", 2000, 1430));
}

Level1::~Level1() {}

const size_t Level1::getHeightMap()
{
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

bool Level1::getValue(int i, int j, char c, string tileMap[])
{
	if (tileMap[i][j] == c)
		return true;

	return false;
}

Texture Level1::getTexture()
{
	return map_->getTexture();
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

void Level1::buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize)
{
	map_->buildMap(window, playerPos, viewSize);
}

void Level1::updateAndDrawEnemies(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime)
{
	int eraseEnemy = -1;

	for (int i = 0; i < enemies_.size(); i++)
	{
		if (enemies_[i]->getEnemyLife())
		{
			Vector2f oldEnemyPosition = enemies_[i]->getPosition();
			enemies_[i]->updatePosition(elapsedTime);
			enemies_[i]->calculateVariables(elapsedTime);
			enemies_[i]->interactionWithMap(oldEnemyPosition, enemies_[i]->getPosition(), map_, elapsedTime);
			enemies_[i]->decision();
			enemies_[i]->draw(window, player, viewSize, elapsedTime);
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

Map* Level1::getMap()
{
	return map_;
}