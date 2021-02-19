#pragma once
class PacketController
{
public:
	static void NKD_ModifyReceived();
	static void NKD_ModifySended();

private:
	static int ExecuteReceived(int clientID, char* pMsg);
	static int ExecuteSended(char* pBuffer, DWORD* socketId, int packetSize);
};

