#pragma once

#include "map.h"

class Map1 : public Map
{
	static const int HEIGHT_MAP = 37;
	const int WIDTH_MAP = 61;

	const int TILE_WIDTH = 64;
	const int TILE_HEIGHT = 64;

	std::string tileMap[HEIGHT_MAP] =
	{
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
		"                                                            ",
	};

	std::string tileMapElse[HEIGHT_MAP] =
	{
		"000000000000000000000000000000000000000000000000000000000000",
		"0                                                          0",
		"0                                                          0",
		"0                                                          0",
		"0                                                          0",
		"0                                                          0",
		"0                                                00000000000",
	    "0       1                         4000002        00000000000",
		"011111111            0      0                              0",
		"0                000 40000002                              0",
		"0                    30000001                              0",
		"0                                                          0",
		"0                                                          0",
		"0                                               400000000000",
		"0                                               300000000000",
		"0       4000002                                            0",
		"0       3000001                                            0",
		"0                                                          0",
		"0                                           400002         0",
		"0                                           300001         0",
		"0                                                          0",
		"0                                                          0",
		"0                 40000000002                              0",
		"0                 00000000000                              0",
		"0                 00       00                              0",
		"0                 00       00                              0",
		"0                 00       00       4000000002             0",
		"0                 00000000000       3000000001             0",
		"0                 30000000001                         400000",
		"0                                                     300000",
		"0                                                          0",
		"0                                                          0",
		"002                                                        0",
		"000                                                        0",
		"000000000000000000000000000000000000000000000000000000000000",
		"000000000000000000000000000000000000000000000000000000000000",
	};

	Texture texture_;
	Sprite sprite_;
public:
	Map1();
	~Map1();

	const size_t getHeightMap();
	const size_t getWidthMap();
	const size_t getTileWidth();
	const size_t getTileHeight();

	string* getTileMapElse();

	bool getValue(int i, int j, char c, string tileMap[]);
	bool getCollision(int i, int j, char c);

	Texture getTexture();

	Sprite getSprite(int i, int j, string tileMap);

	size_t getTextureSizeX();
	size_t getTextureSizeY();

	void buildMap(RenderWindow* window, Vector2f playerPos, Vector2f viewSize);
};