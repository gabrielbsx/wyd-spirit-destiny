#pragma once
class CExpController
{
public:
	static void NKD_ExpMultiply();

private:
	static INT64 ProcessExpController(int conn, INT64 exp);
	static INT64 ExpMultiply(int conn, INT64 exp);
};

