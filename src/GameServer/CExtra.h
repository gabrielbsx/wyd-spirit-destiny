#pragma once
struct St_Ingame
{
	struct
	{
		unsigned long long dwLastAttackTime;
		unsigned long long dwLastInvalid;
		int InvalidCounter;
	}Protection;
	struct
	{
		bool EnableReward;
		bool isAutoTrading;
		int TimerAutoTrading;
	}Store;
	struct
	{
		bool isAdmin;
	}Admin;
};
struct St_Save 
{
	struct
	{
		bool banStatus;
		char Login[18];
		char LastMac[18];
		char CurrentMac[18];
		char LockAccount[16];
		bool IsLocked;
	}Info;
	struct
	{
		int Quests[10];
	}QuestInfo;
	struct
	{
		int AccessLevel;
	}Admin;
};

enum class SaveType : int
{
	CloseUser,
	CharLogout,
	OnlySave,
	NoExists
};
class CExtra
{
public:
	CExtra();
	~CExtra();
	bool Save(SaveType type);
	bool Load(const char* login, bool write = false);
	
private:
	int isValid(char character);
public:
	St_Ingame InGame;
	St_Save Account;
};

extern CExtra g_pExtra[MAX_USER];
