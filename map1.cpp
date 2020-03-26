#include "map1.h"

Map1::Map1()
{
	cout << "In Map1 constructor" << endl;

<<<<<<< HEAD
	texture1_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile1_orange.png");
	texture2_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile2_orange.png");
	texture3_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile3_orange.png");
	texture4_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile4_orange.png");
	texture5_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile5_orange.png");
	texture6_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile6_orange.png");
	texture7_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile7_orange.png");
	texture8_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile8_orange.png");
	texture9_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile9_orange.png");

	textureStatue_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Details/marker_statue1.png");
	textureBackground_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Background/Pale/Background.png");
	textureBackground_.setRepeated(true);

	sprite_.setOrigin(32, 0); // 32 == half of texture width

	oldPlayerPos_.x = oldPlayerPos_.y = -1;

	treasureFactory_ = new TreasureFactory();

	catchedCoins = 0;
	savedPosition_.x = 15;
	savedPosition_.y = 7;
	treasurePoints_ = 0;
	offset_ = 0;
=======
	texture_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile5.png");
	textureStatue_.loadFromFile("./textures/tiles/DungeonTiles/PNG/Details/marker_statue1.png");

	sprite_.setTexture(texture_);
	sprite_.setOrigin(32, 0); // 32 == half of texture width

	treasureFactory_ = new TreasureFactory();

	catchedCoins = 0;
	savedPosition_.x = 0;
	savedPosition_.y = 0;
	treasurePoints_ = 0;
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57

	inSaveZone_ = false;
}

Map1::~Map1()
{
	cout << "In Map1 destructor" << endl;

	delete treasureFactory_;

	if (treasure_)
	{
	//	delete treasure_;
	}
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

string* Map1::getTileMapDecoration()
{
	return tileMapDecoration;
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

bool Map1::getInSaveZone()
{
	return inSaveZone_;
}

<<<<<<< HEAD
//Texture Map1::getTexture()
//{
//	return texture_;
//}
=======
Texture Map1::getTexture()
{
	return texture_;
}
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57

Sprite Map1::getSprite(int i, int j, string tileMap)
{
	Sprite sprite;
	//Texture texture;
	//CreateTextureAndBitmask(texture, "./textures/tiles/DungeonTiles/PNG/Tiles_rock/tile4.png");
	//sprite.setTexture(texture);
	//sprite.setPosition(300, 128);

	if (tileMap == "tileMapElse")
	{
<<<<<<< HEAD
		if (tileMapElse[i][j] == '1')	sprite.setTexture(texture1_);
		else if (tileMapElse[i][j] == '2')	sprite.setTexture(texture2_);
		else if (tileMapElse[i][j] == '3')	sprite.setTexture(texture3_);
		else if (tileMapElse[i][j] == '4')	sprite.setTexture(texture4_);
		else if (tileMapElse[i][j] == '5')	sprite.setTexture(texture5_);
		else if (tileMapElse[i][j] == '6')	sprite.setTexture(texture6_);
		else if (tileMapElse[i][j] == '7')	sprite.setTexture(texture7_);
		else if (tileMapElse[i][j] == '8')	sprite.setTexture(texture8_);
		else if (tileMapElse[i][j] == '9')	sprite.setTexture(texture9_);
=======
		if (tileMapElse[i][j] == '1')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '2')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '3')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '4')	sprite.setTexture(texture_);
		else if (tileMapElse[i][j] == '0')	sprite.setTexture(texture_);
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57

		//cout << "Here" << endl;
		sprite.setPosition(j * 64, i * 64);
		//sprite.setOrigin(64, 64);
	}

	return sprite;
}

size_t Map1::getTextureSizeX()
{
<<<<<<< HEAD
	return texture1_.getSize().x;
=======
	return texture_.getSize().x;
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57
}

size_t Map1::getTextureSizeY()
{
<<<<<<< HEAD
	return texture1_.getSize().y;
=======
	return texture_.getSize().y;
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57
}

void Map1::buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize, int playerWidth, int playerHeight, float elapsedTime)
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

<<<<<<< HEAD
	if (oldPlayerPos_.x == -1)
	{
		spriteBackground_.setTextureRect(IntRect(0, 0, 9999999, 9999999));
		spriteBackground_.setPosition(playerPos.x - 9999, playerPos.y - viewSize.y / 2);
		spriteBackground_.setScale(viewSize.x / textureBackground_.getSize().x, viewSize.y / textureBackground_.getSize().y);
	}

	spriteBackground_.setPosition(spriteBackground_.getPosition().x, playerPos.y - viewSize.y / 2);
	if (oldPlayerPos_.x < playerPos.x)
	{
		offset_ = 130 * elapsedTime;
		spriteBackground_.setPosition(spriteBackground_.getPosition().x + offset_, playerPos.y - viewSize.y / 2);
	}
	else if (oldPlayerPos_.x > playerPos.x)
	{
		offset_ = -130 * elapsedTime;
		spriteBackground_.setPosition(spriteBackground_.getPosition().x + offset_, playerPos.y - viewSize.y / 2);
	}
	oldPlayerPos_ = playerPos;
	spriteBackground_.setTexture(textureBackground_);
	window->draw(spriteBackground_);

=======
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57
	for (int i = jMin; i < jMax; i++)
	{
		for (int j = iMin; j < iMax; j++)
		{
			if (tileMapElse[i][j] == ' ')
			{
			}
			else
			{
<<<<<<< HEAD
				if (tileMapElse[i][j] == '1') sprite_.setTexture(texture1_);
				else if (tileMapElse[i][j] == '2')  sprite_.setTexture(texture2_);
				else if (tileMapElse[i][j] == '3')  sprite_.setTexture(texture3_);
				else if (tileMapElse[i][j] == '4')  sprite_.setTexture(texture4_);
				else if (tileMapElse[i][j] == '5')  sprite_.setTexture(texture5_);
				else if (tileMapElse[i][j] == '6')  sprite_.setTexture(texture6_);
				else if (tileMapElse[i][j] == '7')  sprite_.setTexture(texture7_);
				else if (tileMapElse[i][j] == '8')  sprite_.setTexture(texture8_);
				else if (tileMapElse[i][j] == '9')  sprite_.setTexture(texture9_);
									  
				sprite_.setPosition(j * TILE_HEIGHT, i * TILE_WIDTH);
				sprite_.setOrigin(32, 0);
=======
				if (tileMapElse[i][j] == '1') sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '2')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '3')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '4')  sprite_.setTexture(texture_);
				else if (tileMapElse[i][j] == '0')  sprite_.setTexture(texture_);
									  
				sprite_.setPosition(j * TILE_HEIGHT, i * TILE_WIDTH);
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57
				window->draw(sprite_);
			}

			if (tileMapTreasure[i][j] == 'x')
			{
				treasureFactory_->setTreasureName("Coin");
				treasure_ = treasureFactory_->getTreasure(Vector2f(j, i), TILE_WIDTH, TILE_HEIGHT);
				treasure_->setCurrFrame(elapsedTime);
				treasure_->spriteUpdate();

<<<<<<< HEAD
=======
				//cout << "j: " << j << endl;
				//cout << (playerPos.x - 20) / TILE_WIDTH << endl;
				//cout << (playerPos.x + 20) / TILE_WIDTH << endl << endl;

>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57
				if ((playerPos.x + playerWidth) / TILE_WIDTH > j && (playerPos.x - playerWidth) / TILE_WIDTH < j
					&& int(playerPos.y) / TILE_HEIGHT >= i && int(playerPos.y - playerHeight / 2) / TILE_HEIGHT <= i)
				{
					tileMapTreasure[i][j] = ' ';
					catchedCoins += 1;
					treasurePoints_ += treasure_->getTreasurePoints();
				}
				else
					window->draw(treasure_->getSprite());
			}
			if (tileMapDecoration[i][j] == 's' || tileMapDecoration[i][j] == 'c')
			{
				sprite_.setTexture(textureStatue_);
				sprite_.setPosition(j * TILE_HEIGHT, i * TILE_WIDTH + 3);
<<<<<<< HEAD
				sprite_.setOrigin(32, 0);
=======
>>>>>>> 41294986eeff1eef9bba63422654c3dde8c27d57
				window->draw(sprite_);
				inSaveZone_ = false;

				if (tileMapDecoration[i][j] == 's')
				{
					if (int(playerPos.x - 200) / TILE_WIDTH <= j && int(playerPos.x + 200) / TILE_WIDTH >= j
						&& int(playerPos.y - 300) / TILE_HEIGHT <= i && int(playerPos.x) / TILE_HEIGHT >= i)
					{
						savedPosition_.x = j;
						savedPosition_.y = i;
						tileMapDecoration[i][j] = 'c';
						inSaveZone_ = true;
					}
				}
			}
		}
	}
}

void Map1::setTreasurePoints(int treasurePoints)
{
	treasurePoints_ = treasurePoints;
}

int Map1::getCatchedCoins()
{
	return catchedCoins;
}

int Map1::getTreasurePoints()
{
	return treasurePoints_;
}

Vector2i Map1::getSavedPosition()
{
	return savedPosition_;
}