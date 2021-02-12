#pragma once
class CHook
{
public:
	CHook();
	~CHook();

	bool Initialize();

private:
	bool StartupConstants();
	bool StartupNakeds();
};

