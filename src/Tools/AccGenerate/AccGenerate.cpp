// AccGenerate.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <io.h>
struct STRUCT_ACCOUNT
{
	char login[16];
	char Password[16];
	char Unk[8032];
};

int main()
{
	
	while (true)
	{
		system("CLS");
		std::cout << "Digite seu login:\n";
		STRUCT_ACCOUNT acc{};
		std::cin >> acc.login;
		std::cout << "Digite sua senha:\n";
		std::cin >> acc.Password;

		FILE* fp;
		char szTmp[1024];
		sprintf_s(szTmp, "./account/%C/%s", acc.login[0], acc.login);
		fopen_s(&fp, szTmp, "wb+");
		if (fp != nullptr)
		{
			fwrite(&acc, sizeof(STRUCT_ACCOUNT), 1, fp);
			fclose(fp);
			std::cout << " Conta criada com sucesso!\n";
			system("pause");
		}
		else
		{
			std::cout << "Falha ao criar sua conta!\n";
			system("pause");
		}
	}
}

