function OnExecute(id)
	local mob = iMob.new(id);
	local face = mob:GetFace();
	Send.Message(id, "Mob face: "..face);
end