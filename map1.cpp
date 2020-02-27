#include "map1.h"

Map1::Map1()
{
	texture_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile5.png");

	sprite_.setTexture(texture_);
	sprite_.setOrigin(32, 0); // 32 == half of texture width

	treasureFactory_ = new TreasureFactory();
}

Map1::~Map1()
{
	cout << "In Map1 destructor" << endl;
	delete treasureFactory_;
}

const size_t Map1::getHeightMap()
{
	return HEIGHT_MAP;
}

const size_t Map1::getWidthMap()
{
	return WIDTH_MAP;
}

const size_t Map1::getTileWidth()
{
	return TILE_WIDTH;
}

const size_t Map1::getTileHeight()
{
	return TILE_HEIGHT;
}

string* Map1::getTileMapElse()
{
	return tileMapElse;
}

string* Map1::getTileMapTreasure()
{
	return tileMapTreasure;
}

bool Map1::getValue(int i, int j, char c, string tileMap[])
{
	if (tileMap[i][j] == c)
	{
		return true;
	}

	return false;
}

bool Map1::getCollision(int i, int j, char c)
{
	if (tileMapElse[i][j] == c)
	{
		return true;
	}

	return false;
}

Texture Map1::getTexture()
{
	return texture_;
}

Sprite Map1::getSprite(int i, int j, string tileMap)
{
	Sprite sprite;
	//Texture texture;
	//CreateTextureAndBitmask(texture, "./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile4.png");
	//sprite.setTexture(texture);
	//sprite.setPosition(300, 128);

	if (tileMap == "tileMapElse")
	{
		if (tileMapElse[i][j] == '1')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '2')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '3')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '4')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '0')	sprite.setTexture(texture_);

		//cout << "Here" << endl;
		sprite.setPosition(j * 64, i * 64);
		//sprite.setOrigin(64, 64);
	}

	return sprite;
}

size_t Map1::getTextureSizeX()
{
	return texture_.getSize().x;
}

size_t Map1::getTextureSizeY()
{
	return texture_.getSize().y;
}

void Map1::buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize, float elapsedTime)
{
	int iMin = 0, jMin = 0, iMax = 0, jMax = 0;
	if (playerPos.x / TILE_WIDTH - viewSize.x / TILE_WIDTH / 2 - 1 < 0)
	{
		iMin = 0;
	}
	else
	{
		iMin = playerPos.x / TILE_WIDTH - viewSize.x / TILE_WIDTH / 2 - 1;
	}

	if (playerPos.x / TILE_WIDTH + viewSize.x / TILE_WIDTH / 2 + 2 >= WIDTH_MAP)
	{
		iMax = WIDTH_MAP;
	}
	else
	{
		iMax = playerPos.x / TILE_WIDTH + viewSize.x / TILE_WIDTH / 2 + 2;
	}

	if (playerPos.y / TILE_HEIGHT - viewSize.y / TILE_HEIGHT / 2 - 1 < 0)
	{
		jMin = 0;
	}
	else
	{
		jMin = playerPos.y / TILE_HEIGHT - viewSize.y / TILE_HEIGHT / 2 - 1;
	}

	if (playerPos.y / TILE_HEIGHT + viewSize.y / TILE_HEIGHT / 2 + 1 >= HEIGHT_MAP)
	{
		jMax = HEIGHT_MAP;
	}
	else
	{
		jMax = playerPos.y / TILE_HEIGHT + viewSize.y / TILE_HEIGHT / 2 + 1;
	}

	for (int i = jMin; i < jMax; i++)
	{
		for (int j = iMin; j < iMax; j++)
		{
			if (tileMapElse[i][j] == ' ')
			{
			}
			else
			{
				if (tileMapElse[i][j] == '1') sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '2')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '3')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '4')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '0')  sprite_.setTexture(texture_);
									  
				sprite_.setPosition(j * TILE_HEIGHT, i * TILE_WIDTH);
				window->draw(sprite_);
			}

			if (tileMapTreasure[i][j] == 'x')
			{
				treasureFactory_->setTreasureName("Coin");
				treasure_ = treasureFactory_->getTreasure(Vector2f(j, i), TILE_WIDTH, TILE_HEIGHT);
				treasure_->setCurrFrame(elapsedTime);
				treasure_->spriteUpdate();

				//if (playerPos.x / TILE_WIDTH != j
				//	&& playerPos.y / TILE_HEIGHT != i)
				//{
				//	window->draw(treasure_->getSprite());
				//}
			}
		}
	}
}

//void Map1::playerInteractionWithMap(Vector2f oldPlayerPosition, Player* player, float elapsedTime)
//{
//	Vector2f position = player->getCurrPosition();
//	Vector2f newPlayerPosition = player->getCurrPosition();
//
//	for (int i = (newPlayerPosition.x - player->getWidth() / 2 + getTileWidth() / 2) / getTileWidth(); i < (newPlayerPosition.x + player->getWidth() / 2 + getTileWidth() / 2) / getTileWidth(); i++)
//	{
//		for (int j = (oldPlayerPosition.y - player->getHeight()) / getTileHeight(); j < (oldPlayerPosition.y) / getTileHeight(); j++)
//		{
//			if (!getValue(j, i, ' ', getTileMapElse()))
//			{
//				position.x = oldPlayerPosition.x;
//				break;
//			}
//		}
//	}
//
//	for (int i = (oldPlayerPosition.x - player->getWidth() / 2 + getTileWidth() / 2) / getTileWidth(); i < (oldPlayerPosition.x + player->getWidth() / 2 + getTileWidth() / 2) / getTileWidth(); i++)
//	{
//		for (int j = (newPlayerPosition.y - player->getHeight()) / getTileHeight(); j < (newPlayerPosition.y) / getTileHeight(); j++)
//		{
//			if (!getValue(j, i, ' ', getTileMapElse()))
//			{
//				if (player->getCurrState() == "jumping")
//				{
//					if (oldPlayerPosition.y >= j * getTileHeight() + getTileHeight())
//					{
//						player->setState("falling");
//						cout << oldPlayerPosition.y - newPlayerPosition.y << endl;
//						player->setPosition(oldPlayerPosition.x, 2 * oldPlayerPosition.y - newPlayerPosition.y);
//						player->setCurrGravityAccel(0);
//						cout << "I" << endl;
//						return;
//					}
//				}
//				else
//				{
//					if (position.x == newPlayerPosition.x && newPlayerPosition.x != oldPlayerPosition.x)
//					{
//						player->setState("running");
//						position.y = j * getTileHeight();
//					}
//					else
//					{
//						player->setState("staying");
//						position.y = j * getTileHeight();
//					}
//
//					//position.y = j * getTileHeight() - player->getLowerGap();
//					//position.y = oldPlayerPosition.y;
//				}
//
//				player->setCurrJumpAccel(player->getJumpForce());
//				player->setCurrGravityAccel(0);
//				break;
//			}
//		}
//	}
//
//	player->setPosition(position.x, position.y);
//
//	if (player->getCurrState() != "jumping" && player->getCurrState() != "falling" && player->getCurrState() != "staying" && position == newPlayerPosition)
//	{
//		player->setState("falling");
//	}
//}