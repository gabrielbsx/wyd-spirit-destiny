function OnExecute(conn, message)
	local level = string.match(message, "(%d+)");
	
	if(level == nil) then
		tSend.SendClientMessage(conn, "use /level NÍVEL");
		return true;
		end
	tSet.SetLevel(conn ,tonumber(level));
	tSend.SendScore(conn);
	return true;
end