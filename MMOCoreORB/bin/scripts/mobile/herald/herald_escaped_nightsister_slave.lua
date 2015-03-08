herald_escaped_nightsister_slave = Creature:new {
	objectName = "@mob/creature_names:escaped_nightsister_slave",
	randomNameType = NAME_GENERIC_TAG,
	socialGroup = "slave",
	faction = "",
	level = 28,
	chanceHit = 0.36,
	damageMin = 270,
	damageMax = 280,
	baseXp = 2730,
	baseHAM = 7200,
	baseHAMmax = 8800,
	armor = 0,
	resists = {35,35,15,-1,-1,-1,-1,15,-1},
	meatType = "",
	meatAmount = 0,
	hideType = "",
	hideAmount = 0,
	boneType = "",
	boneAmount = 0,
	milk = 0,
	tamingChance = 0,
	ferocity = 0,
	pvpBitmask = NONE,
	creatureBitmask = NONE,
	optionsBitmask = 136,
	diet = HERBIVORE,

	templates = {"object/mobile/dressed_dathomir_nightsister_escaped_slave.iff"},
	lootGroups = {},
	weapons = {},
	conversationTemplate = "heraldConvoTemplate",
	attacks = {}
}

CreatureTemplates:addCreatureTemplate(herald_escaped_nightsister_slave, "herald_escaped_nightsister_slave")