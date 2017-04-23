#pragma once

class Dungeon {

public:
	Dungeon::Dungeon();
	void Dungeon::Main();
	void Dungeon::BuildMap();
	void Dungeon::BuildRoom();
	bool Dungeon::IsConnected();
	void Dungeon::BuildPath();

};
