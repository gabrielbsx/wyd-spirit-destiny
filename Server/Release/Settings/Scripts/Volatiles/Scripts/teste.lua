function OnExecute(id)
	local mob = tMob.new(id);
	local face = mob:GetFace();
	tSend.SendClientMessage(id, "Mob face: "..face);
end