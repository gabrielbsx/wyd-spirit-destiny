-- Início Helper Extra
QUEST_1 = 0;
QUEST_2 = 1;
QUEST_3 = 2;
QUEST_4 = 3;
QUEST_5 = 4;
QUEST_6 = 5;
QUEST_7 = 6;
QUEST_8 = 7;
QUEST_9 = 8;
QUEST_10 = 9;

FLAG_1 = 0;
FLAG_2 = 1;
FLAG_3 = 2;
FLAG_4 = 3;
FLAG_5 = 4;
FLAG_6 = 5;
FLAG_7 = 6;
FLAG_8 = 7;
FLAG_9 = 8;
FLAG_10 = 9;
FLAG_11 = 10;
FLAG_12 = 11;
FLAG_13 = 12;
FLAG_14 = 13;
FLAG_15 = 14;
FLAG_16 = 15;
FLAG_17 = 16;
FLAG_18 = 17;
FLAG_19 = 18;
FLAG_20 = 19;
FLAG_21 = 20;
FLAG_22 = 21;
FLAG_23 = 22;
FLAG_24 = 23;
FLAG_25 = 24;
FLAG_26 = 25;
FLAG_27 = 26;
FLAG_28 = 27;
FLAG_29 = 28;
FLAG_30 = 29;
FLAG_31 = 30;
FLAG_32 = 31;
-- Fim Helper Extra

function OnExecute(conn, message)
	local result = tExtra.CheckQuest(conn, QUEST_1, FLAG_2);
	if(result == false) then
		tSend.SendClientMessage(conn, "Você já ativou sua recompensa antes!");
		return true;
		end
	tExtra.SetQuest(conn, QUEST_1, FLAG_1);
	local sendeditem = CItem.new();
	sendeditem:SetValue(413, 61, 120, 0, 0, 0, 0);
	tSend.SendPutItem(conn, sendeditem);
	local affectSlot = tGet.GetAffect(conn, 39);
	if(affectSlot == -1) then
		tSend.SetAffect(conn, 39, 600, 50);
	end
		
	affectSlot = tGet.GetAffect(conn, 30);
	if(affectSlot == -1) then
		tSend.SetAffect(conn, 30,600, 50);
	end
	
	tSend.SendScore(conn);
	tSend.SendClientMessage(conn, "Recomensa ativada com sucesso!");
	return true;
end