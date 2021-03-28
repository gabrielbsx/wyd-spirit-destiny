#include "pch.h"
#include "ImportInfo.h"
#include <io.h>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#pragma warning(disable: 4996) // this function or variable may be unsafe

static int(*ReadImportItem)() = (int(__cdecl*)()) 0x0455BCC;

__declspec(naked) void ImportInfo::NKD_Modify()
{
	__asm
	{
		CALL ImportInfo::Execute
		PUSH 0x048D94F
		RETN
	}
}

void ImportInfo::Execute()
{
	ReadImportItem();
	ImportInfo::ImportUser();
	ImportInfo::ImportPass();
	ImportInfo::ImportToken();
}

void ImportInfo::ImportUser()
{
	char line[256];
	char path[256];
	char arq[256];

	strncpy_s(path, "../../Imports/User/*.txt", 25);

	struct _finddata_t file;

	INT32 findFile = _findfirst(path, &file);

	if (findFile == -1)
		return;

	do
	{
		if (file.name[0] == '.')
		{
			INT32 t = _findnext(findFile, &file);
			if (t != 0)
				break;

			continue;
		}

		sprintf_s(arq, "../../Imports/User/%s", file.name);
		FILE* pFile = nullptr;
		fopen_s(&pFile, arq, "rt");

		if (pFile != NULL)
		{
			char* result = fgets(line, 127, pFile);
			if (result == 0)
			{
				fclose(pFile);

				INT32 t = _findnext(findFile, &file);
				if (t != 0)
					break;

				continue;
			}

			char user[16] = { 0 };
			char pass[12] = { 0 };

			INT32 access = 0;
			INT32 ret = sscanf(line, "%s %s", user, pass);
			if (ret != 2)
			{
				fclose(pFile);

				INT32 t = _findnext(findFile, &file);
				if (t != 0)
					break;

				continue;
			}

			fclose(pFile);

			strupr(user);

			ImportInfo::CreateAccount(user, pass);

			remove(arq);

			INT32 t = _findnext(findFile, &file);
			if (t != 0)
				break;
		}
	} while (true);
}

void ImportInfo::ImportPass()
{
	char line[256];
	char path[256];
	char arq[256];

	strncpy_s(path, "../../Imports/Password/*.txt", 29);

	struct _finddata_t file;

	INT32 findFile = _findfirst(path, &file);

	if (findFile == -1)
		return;

	do
	{
		if (file.name[0] == '.')
		{
			INT32 t = _findnext(findFile, &file);
			if (t != 0)
				break;

			continue;
		}

		sprintf_s(arq, "../../Imports/Password/%s", file.name);
		FILE* pFile = nullptr;
		fopen_s(&pFile, arq, "rt");

		if (pFile != NULL)
		{
			char* result = fgets(line, 127, pFile);
			if (result == 0)
			{
				fclose(pFile);

				INT32 t = _findnext(findFile, &file);
				if (t != 0)
					break;

				continue;
			}

			char user[16] = { 0 };
			char pass[12] = { 0 };

			INT32 access = 0;
			INT32 ret = sscanf(line, "%s %s", user, pass);
			if (ret != 2)
			{
				fclose(pFile);

				INT32 t = _findnext(findFile, &file);
				if (t != 0)
					break;

				continue;
			}

			fclose(pFile);

			strupr(user);

			ImportInfo::ChangePass(user, pass);

			remove(arq);

			INT32 t = _findnext(findFile, &file);
			if (t != 0)
				break;
		}
	} while (true);
}

void ImportInfo::ImportToken()
{
	char line[256];
	char path[256];
	char arq[256];

	strncpy_s(path, "../../Imports/Token/*.txt", 26);

	struct _finddata_t file;

	INT32 findFile = _findfirst(path, &file);

	if (findFile == -1)
		return;

	do
	{
		if (file.name[0] == '.')
		{
			INT32 t = _findnext(findFile, &file);
			if (t != 0)
				break;

			continue;
		}

		sprintf_s(arq, "../../Imports/Token/%s", file.name);
		FILE* pFile = nullptr;
		fopen_s(&pFile, arq, "rt");

		if (pFile != NULL)
		{
			char* result = fgets(line, 127, pFile);
			if (result == 0)
			{
				fclose(pFile);

				INT32 t = _findnext(findFile, &file);
				if (t != 0)
					break;

				continue;
			}

			char user[16] = { 0 };
			char pass[12] = { 0 };

			INT32 access = 0;
			INT32 ret = sscanf(line, "%s %s", user, pass);
			if (ret != 2)
			{
				fclose(pFile);

				INT32 t = _findnext(findFile, &file);
				if (t != 0)
					break;

				continue;
			}

			fclose(pFile);

			strupr(user);

			ImportInfo::ChangeToken(user, pass);

			remove(arq);

			INT32 t = _findnext(findFile, &file);
			if (t != 0)
				break;
		}
	} while (true);
}

void ImportInfo::CreateAccount(const char* login, const char* pass)
{
	FILE* fp = nullptr;
	char temp[512];
	sprintf_s(temp, sizeof(temp), "./account/%C/%s", login[0], login);

	fopen_s(&fp, temp, "rb");
	if (fp == nullptr)
		fopen_s(&fp, temp, "wb");
	else
		return;
	if (fp != nullptr)
	{
		sizeof(st_info);
		st_info acc;
		memset(&acc, 0, sizeof(acc));

		sprintf(acc.Username, "%s", login);
		sprintf(acc.Password, "%s", pass);

		fwrite(&acc, sizeof(st_info), 1, fp);
		fclose(fp);
	}
	
}

void ImportInfo::ChangePass(const char* login, const char* pass)
{
	FILE* fp = nullptr;
	char temp[512];
	sprintf_s(temp, sizeof(temp), "./account/%C/%s", login[0], login);

	fopen_s(&fp, temp, "rb");
	if (fp != nullptr)
	{
		sizeof(st_info);
		st_info acc;
		memset(&acc, 0, sizeof(acc));
		fread(&acc, sizeof(st_info), 1, fp);
		fclose(fp);
		if (acc.Password[0] == '@' || acc.Password[0] == '#' || acc.Password[0] == '!')
			return;
		sprintf(acc.Username, "%s", login);
		sprintf(acc.Password, "%s", pass);

		fopen_s(&fp, temp, "wb");
		if (fp != nullptr)
		{
			fwrite(&acc, sizeof(st_info), 1, fp);
			fclose(fp);
			
		}
	}
}

void ImportInfo::ChangeToken(const char* login, const char* token)
{
	FILE* fp = nullptr;
	char temp[512];
	sprintf_s(temp, sizeof(temp), "./account/%C/%s", login[0], login);

	fopen_s(&fp, temp, "rb");
	if (fp != nullptr)
	{
		sizeof(st_info);
		st_info acc;
		memset(&acc, 0, sizeof(acc));
		fread(&acc, sizeof(st_info), 1, fp);
		fclose(fp);
		if (acc.Password[0] == '@' || acc.Password[0] == '#' || acc.Password[0] == '!')
			return;
		sprintf(acc.Username, "%s", login);
		sprintf(acc.NumericToken, "%s", token);

		fopen_s(&fp, temp, "wb");
		if (fp != nullptr)
		{
			fwrite(&acc, sizeof(st_info), 1, fp);
			fclose(fp);

		}
	}
}
