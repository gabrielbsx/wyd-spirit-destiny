#pragma once
struct EXP_CLASS
{
	int Evolution;
	int LevelMin, LevelMax;
	int Multiply;
};
struct EXP_AREA
{
	int X, Y, xMin, yMin, xMax, yMax, Mult;
};
class CExpController
{
public:
	static void NKD_ExpMultiply();
	static bool LoadExpClass();
	static bool LoadExpArea();

private:
	static INT64 ProcessExpController(int conn, INT64 exp);
	static INT64 ExpMultiply(int conn, INT64 exp);
	static std::vector<EXP_CLASS> vExpControl;
	static std::vector<EXP_AREA> vExpArea;
};

