function OnExecute(conn, message)
	local item, EF1, EFV1, EF2, EFV2, EF3, EFV3 = string.match(message, "(%d+) (%d+) (%d+) (%d+) (%d+) (%d+) (%d+)");
	
	if(item == nil or EF1 == nil or EFV1 == nil or EF1 == nil or EFV1 == nil or EF1 == nil or EFV1 == nil) then
		tSend.SendClientMessage(conn, "use /item ID EF1 EFV1 EF2 EFV2 EF3 EFV3");
		return true;
		end
	local sendeditem = CItem.new();
	sendeditem:SetValue(tonumber(item), tonumber(EF1), tonumber(EFV1), tonumber(EF2), tonumber(EFV2), tonumber(EF3), tonumber(EFV3));
	tSend.SendPutItem(conn, sendeditem);
	return true;
end