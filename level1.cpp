#include "level1.h"

Level1::Level1()
{
	map_ = new Map1();

	enemies_.push_back(new Enemy("Character1", 640, 960, new PhysxImplEnWalk()));
	enemies_.push_back(new Enemy("Character1", 2560, 1664, new PhysxImplEnWalk()));
	enemies_.push_back(new Enemy("Character1", 448, 2176, new PhysxImplEnWalk()));
	enemies_.push_back(new Enemy("Character1", 666, 2176, new PhysxImplEnWalk()));
	enemies_.push_back(new Enemy("Character1", 1600, 576, new PhysxImplEnWalk()));
	enemies_.push_back(new Enemy("Bat", 666, 2176-64*2, new PhysxImplEnFly(400, 40 * 64)));
	//enemies_.push_back(new Enemy("Character1", 1600, 576));
	//enemies_.push_back(new Enemy("Character1", 1600, 576));
	//enemies_.push_back(new Enemy("Character1", 1600, 576));
	//enemies_.push_back(new Enemy("Character1", 1600, 576));
	//enemies_.push_back(new Enemy("Character1", 1600, 576));
	//enemies_.push_back(new Enemy("Character1", 1600, 576));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));
	//enemies_.push_back(new Enemy("Character1", 1600, 330));


	//enemies_.push_back(new Enemy("Character1", 1700, 930));
	//enemies_.push_back(new Enemy("Character1", 2500, 930));
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

void Level1::buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize, float elapsedTime)
{
	map_->buildMap(window, playerPos, viewSize, elapsedTime);
}

void Level1::updateAndDrawEnemies(RenderWindow* window, Player* player, Vector2f viewSize, float elapsedTime)
{
	int eraseEnemy = -1;

	for (int i = 0; i < enemies_.size(); i++)
	{
		if (enemies_[i]->getEnemyLife())
		{
			Vector2f oldEnemyPosition = enemies_[i]->getPosition();
			enemies_[i]->flyingShellsUpdateAndDraw(elapsedTime, map_, window);
			int enDamage = enemies_[i]->flyingShellsMakeDamage(player->getCurrPosition(), player->getWidth(), player->getHeight());
			if (enDamage > 0)
			{
				player->setCurrHealthPoints(player->getCurrHealthPoints() - enDamage * (100 - player->getArmor()) / 100);
				player->setHurt(true);
				cout << "Player health: " << player->getCurrHealthPoints() << endl;
			}
			enemies_[i]->updatePosition(elapsedTime);
			enemies_[i]->calculateVariables(elapsedTime);
			enemies_[i]->decision(elapsedTime, player);
			enemies_[i]->interactionWithMap(oldEnemyPosition, map_, elapsedTime);
			enemies_[i]->draw(window, player, viewSize, elapsedTime);
			int damage = player->flyingShellsMakeDamage(enemies_[i]->getPosition(), enemies_[i]->getWidth(), enemies_[i]->getHeight());
			if (damage > 0)
			{
				enemies_[i]->setCurrHealthPoints(enemies_[i]->getCurrHealthPoints() - damage);
				enemies_[i]->setHurt(true);
				cout << "Enemy " << i << " health: " << enemies_[i]->getCurrHealthPoints() << endl;
			}
		}
		else
		{
			player->setCurrExp(player->getCurrExp() + enemies_[i]->getKillExp());
			eraseEnemy = i;
		}
	}

	if (eraseEnemy != -1)
	{
		Enemy* en = enemies_.at(eraseEnemy);
		enemies_.erase(enemies_.begin() + eraseEnemy);
		delete en;
	}
}

/*void Level1::playerInteractionWithMap(Vector2f oldPlayerPosition, Player* player, float elapsedTime)
{
	map_->playerInteractionWithMap(oldPlayerPosition, player, elapsedTime);
}*/

Map* Level1::getMap()
{
	return map_;
}

int Level1::getLevelNumber()
{
	return 1;
}