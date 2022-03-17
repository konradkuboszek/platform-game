#include "TileMap.h"

TileMap::TileMap(float screenHeight, float screenWidth, int level)
{
	initMap(screenHeight, screenWidth,level);
}

TileMap::~TileMap()
{
}
void TileMap::initMap(float screenHeight, float screenWidth,int level)
{
	int x = 0, y = 0, i = 0;
	map.clear();
	std::string tile2TextureName = "Textures/Tile2.png";
	std::string tileTexture{};
	std::string tile1TextureName = "Textures/Tile1.png";
	std::string tile3TextureName = "Textures/Tile3.png";
	std::string tile4TextureName = "Textures/spikes.png";
	std::string mapRow;
	std::fstream plik("Resources/TileMap.txt");
	std::fstream plik1("Resources/TileMapLevel2.txt");
	int isPassable = 0;
	std::vector<Tile*> firstRow;
	for (int rows = 0; rows <= 32; rows++) {
		if (level == 1)
			plik >> mapRow;
		else if (level == 2)
			plik1 >> mapRow;
		i = 0;
		x = 0;
		firstRow.clear();
		for (; x <= screenWidth; x += 25) {
			if (mapRow[i] == '2') {
				//tileTexture = tile1TextureName;
				isPassable = 0;
				firstRow.push_back(new Tile(tile1TextureName, x, y, isPassable));
			}
			else if (mapRow[i] == '1') {
				//tileTexture = tile2TextureName;
				isPassable = 0;
				firstRow.push_back(new Tile(tile2TextureName, x, y, isPassable));
			}
			else if (mapRow[i] == '3') {
				//tileTexture = tile2TextureName;
				isPassable = 1;
				firstRow.push_back(new Tile(tile3TextureName, x, y, isPassable));
			}
			else if (mapRow[i] == '4') {
				//tileTexture = tile2TextureName;
				isPassable = 2;
				firstRow.push_back(new Tile(tile4TextureName, x, y, isPassable));
			}
			else {
				firstRow.push_back(new Tile(tile1TextureName, x, y, isPassable));

			}
			i++;
			/*firstRow.push_back(new Tile(tileTexture, x, 0, isPassable));*/
		}
		map.push_back(firstRow);
		y += 25;
		/*std::vector<Tile*> secondRow;
		for (x = 0; x <= screenWidth; x += 25)
			secondRow.push_back(new Tile("Textures/tile1.png", x, 25, 1));
		map.push_back(secondRow);*/

	}
}