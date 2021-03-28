#pragma once
typedef struct
{

	char Username[16];
	// 0 - 15
	char Password[12];
	// 16 - 27
	char Unk[160];
	// 28 - 187
	char NumericToken[6];
	// 188 - 193
	char Unk2[14];      // 194 - 207

	char temp[5908];
	char temp2[1948];
}st_info;

class ImportInfo
{
public:
	static void NKD_Modify();

private:
	static void Execute();
	static void ImportUser();
	static void ImportPass();
	static void ImportToken();

	static void CreateAccount(const char* login, const char* pass);
	static void ChangePass(const char* login, const char* pass);
	static void ChangeToken(const char* login, const char* pass);
};

