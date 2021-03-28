#pragma once

struct		  MSG_AccountLogin
{
	PacketHeader Header;

	char AccountPassword[ACCOUNTPASS_LENGTH];
	char AccountName[ACCOUNTNAME_LENGTH];

	char Zero[52];


	int  ClientVersion;

	int  DBNeedSave;

	char AdapterName[16];
};

class CAccount
{
public:
	static bool Initialize();

	static int Run(int conn, char* pMsg);
private:
	static int ExtraRun(int conn);
	static void ExtraCloseUser(int conn);
	static void ExtraSaveUser(int conn);
	static void ExtraOnCharLogout(int conn);
	static void NKD_AccountLogin();
	static void NKD_OnCharLogout();
	static void NKD_SaveUser();
	static void NKD_CloseUser();
};

