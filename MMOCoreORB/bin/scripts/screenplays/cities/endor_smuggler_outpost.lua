EndorSmugglerOutpostScreenPlay = CityScreenPlay:new {
	numberOfActs = 1,

	screenplayName = "EndorSmugglerOutpostScreenPlay",

	planet = "endor",

	patrolMobiles = {
		--{patrolPoints, template, level, x, z, y, direction, cell, mood},
		{"r3_1", "r3", 60, -950.705, 73, 1542.69, 331.775, 0, "neutral"},
	},

	patrolPoints = {
		--table_name = {{x, z, y, cell, delayAtNextPoint}} 1 = no delay 0 = delay}
		r3_1 = {{-951, 73, 1542, 0, 1}, {-905, 76, 1586, 0, 1}, {-904, 80, 1612, 0, 1}, {-886, 76, 1600, 0, 1}, {-880, 76, 1589, 0, 1}, {-858, 76, 1584, 0, 1}, {-854, 79, 1600, 0, 1}, {-858, 76, 1584, 0, 1}, {-885, 76, 1586, 0, 1}},
	},
}

registerScreenPlay("EndorSmugglerOutpostScreenPlay", true)

function EndorSmugglerOutpostScreenPlay:start()
	if (isZoneEnabled("endor")) then
		self:spawnMobiles()
		self:spawnPatrolMobiles()
	end
end

function EndorSmugglerOutpostScreenPlay:spawnMobiles()

	--mission term building
	local pNpc = spawnMobile("endor", "commoner_technician",60,3.5,0.1,3.9,0,3605972)
	self:setMoodString(pNpc, "sad")

	--tavern
	local pNpc = spawnMobile("endor", "commoner_old",60,1.0,0.7,-4.4,0,6645605)
	self:setMoodString(pNpc, "npc_sitting_chair")

	--outside
	spawnMobile("endor", "businessman", 60, -899.977, 78, 1548.09, 107.809, 0)
	spawnMobile("endor", "commoner", 60, -828.009, 76, 1573.28, 320.402, 0)
	spawnMobile("endor", "commoner", 60, -838.625, 76, 1574.97, 333.27, 0)
	spawnMobile("endor", "commoner", 60, -864.293, 79.5001, 1598.78, 184.686, 0)
	spawnMobile("endor", "commoner", 60, -841.483, 79.5144, 1602.34, 240.991, 0)
	spawnMobile("endor", "commoner", 60, -851.058, 80.0739, 1555.56, 238.812, 0)
	spawnMobile("endor", "commoner", 60, -875.462, 80.0597, 1571.89, 84.1865, 0)
	spawnMobile("endor", "commoner", 60, -880.276, 76, 1604.61, 30.4167, 0)
	spawnMobile("endor", "commoner", 60, -880.194, 76, 1624.44, 273.171, 0)
	spawnMobile("endor", "commoner", 60, -880.718, 76, 1638.25, 11.1628, 0)
	spawnMobile("endor", "commoner", 60, -896.026, 80, 1621.19, 243.324, 0)
	spawnMobile("endor", "scientist", 60, -874.656, 80, 1564.76, 108.353, 0)
	spawnMobile("endor", "scientist", 60, -845.301, 79.5, 1599.49, 197.393, 0)
	spawnMobile("endor", "smuggler", 300, -889.786, 76, 1591.32, 182.753, 0)
	spawnMobile("endor", "smuggler", 300, -890.91, 76, 1591.38, 253.162, 0)
	spawnMobile("endor", "smuggler", 300, -889.732, 76, 1592.45, 319.914, 0)
	spawnMobile("endor", "noble", 60, -829.243, 76, 1567.61, 95.886, 0)
end
