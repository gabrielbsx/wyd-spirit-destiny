#pragma once
struct DROP_AREA
{
	int X, Y, xMin, yMin, xMax, yMax, Bonus;
};
class CDropController
{
public:
	static bool Initialize();
	static void NKD_BlockDrop();
	static void NKD_DropArea();


private:
	static int ProcessBlockDrop(short itemID);
	static int DropMultiply(int conn, int rate);
	static bool LoadDropArea();
	static bool LoadBlockDrop();

	static std::vector<DROP_AREA> vDropArea;
	static std::vector<short> vBlockDrop;
};

