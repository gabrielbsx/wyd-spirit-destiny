function OnExecute(killer, killed)
	tSend.SendClientMessage(killer, "KilledID:"..killed);
	return true;
end