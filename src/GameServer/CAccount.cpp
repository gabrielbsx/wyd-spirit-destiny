#include "pch.h"
#include "CAccount.h"
#include "Native.h"
#include "CExtra.h"
#include "CMain.h"
#include <PEHook.h>

// HookSave
// HookClose
// HookCharLogout

bool CAccount::Initialize()
{
	try
	{
		PEHook::JMP_NEAR(0x0559235, CAccount::NKD_AccountLogin, 2);
		PEHook::JMP_NEAR(0x056B518, CAccount::NKD_SaveUser, 2);
		PEHook::JMP_NEAR(0x056A3BF, CAccount::NKD_CloseUser, 2);
		PEHook::JMP_NEAR(0x056B7C1, CAccount::NKD_OnCharLogout, 4);
		return true;
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return false;
	}
}

int CAccount::Run(int conn, char* pMsg)
{
	auto p = reinterpret_cast<MSG_AccountLogin*>(pMsg);
	if (g_pExtra[conn].Load(p->AccountName))
	{
		if (g_pExtra[conn].Account.Info.banStatus)
		{
			SendClientMessage(conn, "Conta bloqueada!");
			CloseUser(conn);
			return false;
		}

		if (g_pMain->Maitence)
		{
			if (g_pExtra[conn].Account.Admin.AccessLevel == 0)
			{
				SendClientMessage(conn, "Aguarde a liberação do servidor!");
				CloseUser(conn);
				return false;
			}
		}

		for (auto& i : g_pMain->BanMac)
		{
			if (!strncmp(p->AdapterName, i.CurrentMac, sizeof(p->AdapterName)))
			{
				SendClientMessage(conn, "Conta bloqueada!");
				g_pExtra[conn].Account.Info.banStatus = true;
				CAccount::ExtraCloseUser(conn);
				CloseUser(conn);
				
				return false;
			}
		}
	}
	else
	{
		if (g_pMain->Maitence)
		{
			if (g_pExtra[conn].Account.Admin.AccessLevel == 0)
			{
				SendClientMessage(conn, "Aguarde a liberação do servidor!");
				CloseUser(conn);
				return false;
			}
		}
	}

	return true;
}

int CAccount::ExtraRun(int conn)
{

	if (g_pExtra[conn].Load(pUser[conn].AccountName, true))
	{

		if (g_pMain->Maitence)
		{
			if (g_pExtra[conn].Account.Admin.AccessLevel == 0)
			{
				SendClientMessage(conn, "Aguarde a liberação do servidor!");
				CloseUser(conn);
				return false;
			}
		}
		if (strlen(g_pExtra[conn].Account.Info.LastMac) > 0 && strncmp(g_pExtra[conn].Account.Info.LastMac, pUser[conn].Mac, sizeof(g_pExtra[conn].Account.Info.LastMac)))
		{
			SendClientMessage(conn, "Houve um acesso apartir de outra maquina em sua conta, altere sua senha!");

			strncpy_s(g_pExtra[conn].Account.Info.CurrentMac, pUser[conn].Mac, sizeof(g_pExtra[conn].Account.Info.CurrentMac));
		}
		if (g_pExtra[conn].Account.Info.IsLocked)
		{
			SendClientMessage(conn, "Conta bloqueada, algumas funções encontram-se indisponíveis!");
		}
		return true;
	}
	else
	{
		SendClientMessage(conn, "Conta inválida!");
		CloseUser(conn);
		return false;
	}
}

void CAccount::ExtraCloseUser(int conn)
{
	if (conn > 0 && conn <= MAX_USER)
	{
		g_pExtra[conn].Save(SaveType::CloseUser);
	}
}

void CAccount::ExtraSaveUser(int conn)
{
	if (conn > 0 && conn <= MAX_USER)
	{
		g_pExtra[conn].Save(SaveType::OnlySave);
	}
}

void CAccount::ExtraOnCharLogout(int conn)
{
	if (conn > 0 && conn <= MAX_USER)
	{
		g_pExtra[conn].Save(SaveType::CharLogout);
	}
}

/// Hook
__declspec(naked) void CAccount::NKD_AccountLogin()
{
	__asm
	{
		PUSH DWORD PTR SS : [EBP - 0x24]
		CALL CAccount::Run
		ADD ESP, 0x4
		MOV EAX, DWORD PTR SS : [EBP - 0x24]
		IMUL EAX, EAX, 0xFC8
		PUSH 0x55923E
		RETN
	}
}


__declspec(naked) void CAccount::NKD_OnCharLogout()
{
	__asm
	{
		PUSH DWORD PTR SS : [EBP + 8]
		CALL CAccount::ExtraOnCharLogout
		ADD ESP, 0x4
		MOV EAX, DWORD PTR SS : [EBP + 8]
		CMP EAX, DWORD PTR DS : [0x61AA148]

		PUSH 0x56B7CA
		RETN
	}
}
__declspec(naked) void CAccount::NKD_SaveUser()
{
	__asm
	{
		CMP DWORD PTR SS : [EBP - 0xAD4] , 0
		JE lblFunctionFail

		PUSH DWORD PTR SS : [EBP + 0x8]
		CALL CAccount::ExtraSaveUser
		ADD ESP, 0x4
		PUSH 0x56B55F
		RETN

		lblFunctionFail :
		PUSH 0x56B521
			RETN
	}
}
__declspec(naked) void CAccount::NKD_CloseUser()
{
	__asm
	{
		PUSH DWORD PTR SS : [EBP + 0x8]
		CALL CAccount::ExtraCloseUser
		ADD ESP, 0x4
		MOV ECX, DWORD PTR SS : [EBP + 0x8]
		IMUL ECX, ECX, 0xFC8
		CMP DWORD PTR DS : [ECX + 0x61AAAD0] , 0x16
		JNZ lblContinue

		PUSH 0x56A3C8
		RETN

		lblContinue :
		PUSH 0x56A441
			RETN
	}
}