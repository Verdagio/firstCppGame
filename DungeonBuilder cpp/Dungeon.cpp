//written by Daniel Verdejo
// www.github.com/verdagio

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <string.h>


using namespace std;

class Dungeon {

public:
	//This will build a mapable area for rooms & paths...
	void BuildMap() {
		
		setMapX(100); 
		setMapY(100); 
		setTile('#');

		for (int row = 0; row < getMapX(); row++) {
			for (int col = 0; col < getMapY(); col++) {
				setTileMap(row, col, getTile());	
			}//inner for
		}//outer for
	}//build map

	//This will build a single room 
	void BuildRooms() {

		int noOfRooms = 70;
		bool clear = true;
		int min=1;
		int distX;
		int distY;
		Room rooms[100];

		
		//create the room indecies
		for (int i = 0; i < noOfRooms; i++) {
			rooms[i].number = i;
			cout << rooms[i].number << endl;
			//Set the rooms...
			if (!(i == noOfRooms - 2) && !(i == noOfRooms - 1)) {
				setTile(' ');//indicates traversal space
				min = getMapX() - 85;
			} else if (i == noOfRooms - 2) {
				setTile('O');//indicates starting point
				min = getMapY() - 10;
			} else if (i == noOfRooms - 1) {// set the last room
				setTile('E');//indicates ending point
				min = getMapY() - 75;
			}//if else if

			rooms[i].startX = ((rand() % (getMapX() - min) + 5));
			rooms[i].endX = rooms[i].startX + ((rand() % (10 - 5) + 5));
			rooms[i].startY = ((rand() % (getMapY() - min) + 5));
			rooms[i].endY = rooms[i].startY + ((rand() % (10 - 5) + 5));

			//check to see if rooms are overlapping eachother
			for (Room tmp : rooms) {
			
				//if the position of a room is between anothers top left & bottom right positions
					// A.x & y start is less tan B.x & y end && A.x & y start is greater than B.x & y start
				if (rooms[i].startX < tmp.endX && rooms[i].startY < tmp.endY && rooms[i].startX > tmp.startX && rooms[i].startY > tmp.startY) {
					//check that we're not comparing the same room against itself
					if (tmp.number != rooms[i].number) {
						cout << "Overlap found on room " << i << endl;
						cout << "TMP: " << tmp.number << " " << tmp.endX << " " << tmp.endY << endl;
						cout << "room " << i << " " << rooms[i].startX << " " << rooms[i].startY << endl;
						
						//set the distance to be moved
						distX = 1 + tmp.endX - rooms[i].startX;
						distY = 1 + tmp.endY - rooms[i].startY;
						
						//move the room the shorter of the 2 distances
						if (distX < distY) {
							rooms[i].startX += distX;
							cout << "Moving " << distX << " on x. NEW POS:  " << rooms[i].startX << endl;
						} else {
							rooms[i].startY += distY;
							cout << "Moving " << distY << " on y. NEW POS: " << rooms[i].startY << endl;
						}//if else if						
					}//if the room number doesn't match
				}//if	
				rooms[i].isConnected = false;
			}//for each room
				
			//Replace the pillar tiles with the path tiles
			for (int row = rooms[i].startY; row < rooms[i].endY; row++) {
				for (int col = rooms[i].startX; col < rooms[i].endX; col++) {
					setTileMap(row, col, getTile());
				}//inner for
			}//outer for

		}//for
	}//room builder


	 //this will build a path between rooms 
		void BuildPath() {

		Room rooms[100];

		for (Room r : rooms) {
			cout << "Connection pending on " << endl;
			if (r.isConnected == false) {
				cout << "Conecting room " << endl;
			}

		}
		
		
	}//build path

	

	//print out the map.
	void PrintMap() {
		for (int row = 0; row < getMapX(); row++) {
			for (int col = 0; col < getMapY(); col++) {

				cout << getTileMap(row, col);

			}//inner for
			cout << endl;
		}//outer for
	}


	//Getters
	int getMapX() {
		return mapX;
	}//get map x
	int getMapY() {
		return mapY;
	}//get map y
	char getTile() {
		return tile;
	}//get tile
	char getTileMap(int row, int col) {
		return tileMap[row][col];
	}

	//Setters
	void setMapX(int x) {
		mapX = x;
	}// set map x
	void setMapY(int y) {
		mapY = y;
	}//set map y
	void setTile(char c) {
		tile = c;
	}//set tile
	void setTileMap(int row, int col, char t) {
		tileMap[row][col] = t;
	}//store the tile map

private:
	//Map vars
	int mapX;
	int mapY;
	char tile;
	char tileMap[100][100];
	

	struct path {
		int length;
		int x;
		int y;
	};
	//room vars
	struct door {
		int xPos;
		int yPos;
	};
	struct Room {
		int startX;
		int endX;
		int startY;
		int endY;
		int number;
		bool isConnected;
	};

	//startX, startY, endX, endY, player start & end, is connected

};


int main() {

	Dungeon d;
	for (int i = 0; i < 5; i++) {
		d.BuildMap();
		d.BuildRooms();
		//d.BuildPath();
		d.PrintMap();
		cout << "\n" << i+1 << endl;
	}



	return 0;
}
