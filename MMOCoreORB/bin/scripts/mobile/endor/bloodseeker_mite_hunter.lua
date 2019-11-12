bloodseeker_mite_hunter = Creature:new {
	objectName = "@mob/creature_names:bloodseeker_mite_hunter",
	socialGroup = "bloodseeker",
	faction = "",
	level = 31,
	chanceHit = 0.36,
	damageMin = 315,
	damageMax = 340,
	baseXp = 3097,
	baseHAM = 5900,
	baseHAMmax = 7200,
	armor = 0,
	resists = {115,145,-1,180,-1,180,180,15,-1},
	meatType = "meat_insect",
	meatAmount = 15,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = AGGRESSIVE + ATTACKABLE + ENEMY,
	creatureBitmask = PACK,
	optionsBitmask = AIENABLED,
	diet = CARNIVORE,

	templates = {"object/mobile/bloodseeker_mite.iff"},
	hues = { 24, 25, 26, 27, 28, 29, 30, 31 },
	scale = 1.1,
	lootGroups = {},

	-- Primary and secondary weapon should be different types (rifle/carbine, carbine/pistol, rifle/unarmed, etc)
	-- Unarmed should be put on secondary unless the mobile doesn't use weapons, in which case "unarmed" should be put primary and "none" as secondary
	primaryWeapon = "object/weapon/ranged/creature/creature_spit_large_red.iff",
	secondaryWeapon = "object/weapon/ranged/creature/creature_spit_large_red.iff",
	conversationTemplate = "",
	
	-- primaryAttacks and secondaryAttacks should be separate skill groups specific to the weapon type listed in primaryWeapon and secondaryWeapon
	-- Use merge() to merge groups in creatureskills.lua together. If a weapon is set to "none", set the attacks variable to empty brackets
	primaryAttacks = { {"dizzyattack",""}, {"posturedownattack",""} },
	secondaryAttacks = { }
}

CreatureTemplates:addCreatureTemplate(bloodseeker_mite_hunter, "bloodseeker_mite_hunter")
