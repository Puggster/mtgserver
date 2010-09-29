/*
 *	server/zone/objects/player/PlayerObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef PLAYEROBJECT_H_
#define PLAYEROBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace creature {

class CreatureObject;

} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class QueueCommand;

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;

namespace server {
namespace zone {
namespace managers {
namespace objectcontroller {

class ObjectController;

} // namespace objectcontroller
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::objectcontroller;

namespace server {
namespace zone {

class ZoneClientSession;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace waypoint {

class WaypointObject;

} // namespace waypoint
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::waypoint;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace templates {

class SharedObjectTemplate;

} // namespace templates
} // namespace zone
} // namespace server

using namespace server::zone::templates;

#include "server/zone/objects/creature/professions/Certification.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "server/zone/objects/scene/variables/DeltaVectorMap.h"

#include "server/zone/objects/scene/variables/DeltaVector.h"

#include "server/zone/objects/player/variables/WaypointList.h"

#include "server/zone/objects/creature/professions/Skill.h"

#include "server/zone/objects/player/variables/SkillList.h"

#include "server/zone/objects/player/variables/FriendList.h"

#include "server/zone/objects/player/variables/IgnoreList.h"

#include "server/zone/objects/player/variables/SchematicList.h"

#include "server/zone/objects/player/variables/CommandArgumentList.h"

#include "engine/lua/LuaObject.h"

#include "server/zone/objects/intangible/IntangibleObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerObject : public IntangibleObject {
public:
	static const int LFG = 1;

	static const int NEWBIEHELPER = 2;

	static const int ROLEPLAYER = 4;

	static const int AFK = 0x80;

	static const int LD = 0x100;

	static const int FACTIONRANK = 0x200;

	static const int ANONYMOUS = 0x80000000;

	static const int CSR = 1;

	static const int DEV = 2;

	PlayerObject();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void sendBaselinesTo(SceneObject* player);

	void sendMessage(BasePacket* msg);

	int addExperience(const String& xpType, int xp, bool notifyClient = true);

	void removeExperience(const String& xpType, bool notifyClient = true);

	void addWaypoint(WaypointObject* waypoint, bool checkName, bool notifyClient = true);

	void setWaypoint(WaypointObject* waypoint, bool notifyClient = true);

	void addWaypoint(const String& planet, float positionX, float positionY, bool notifyClient = true);

	void removeWaypoint(unsigned long long waypointID, bool notifyClient = true);

	void addSkills(Vector<QueueCommand*>& skills, bool notifyClient = true);

	void addSkills(Vector<Certification*>& skills, bool notifyClient = true);

	void addSkillArgument(const String& skillName, const String& argument);

	void dropSkillArgument(const String& skillName, const String& argument);

	bool hasSkillArgument(const String& skillName, const String& argument);

	CommandArgumentList* getCommandArgumentList();

	void removeSkills(Vector<QueueCommand*>& skills, bool notifyClient = true);

	void removeSkills(Vector<Certification*>& skills, bool notifyClient = true);

	void addSchematics(Vector<ManagedReference<DraftSchematic* > >& schematics, bool notifyClient = true);

	void removeSchematics(Vector<ManagedReference<DraftSchematic* > >& schematics, bool notifyClient = true);

	void addSchematic(DraftSchematic* schematic, bool notifyClient = true);

	void removeSchematic(DraftSchematic* schematic, bool notifyClient = true);

	void setLanguageID(byte language, bool notifyClient = true);

	void addFriend(const String& name, bool notifyClient = true);

	void removeFriend(const String& name, bool notifyClient = true);

	void addIgnore(const String& name, bool notifyClient = true);

	void removeIgnore(const String& name, bool notifyClient = true);

	void setTitle(const String& characterTitle, bool notifyClient = true);

	void setFoodFilling(int newValue, bool notifyClient = true);

	void setDrinkFilling(int newValue, bool notifyClient = true);

	void setCommandMessageString(unsigned int actionCRC, String& message);

	void removeCommandMessageString(unsigned int actionCRC);

	void notifyOnline();

	void doDigest();

	bool isDigesting();

	void notifyOffline();

	bool hasFriend(const String& name);

	bool isIgnoring(const String& name);

	void addReverseFriend(const String& name);

	void removeReverseFriend(const String& name);

	void sendFriendLists();

	bool hasWaypoint(unsigned long long objectID);

	bool hasSkill(Skill* skill);

	bool hasSkill(const String& skillName);

	bool hasCommandMessageString(unsigned int actionCRC);

	unsigned int getCharacterBitmask();

	String getTitle();

	unsigned int getAdminLevel();

	bool isDeveloper();

	bool isCSR();

	bool isPrivileged();

	void setCharacterBitmask(unsigned int bitmask);

	bool setCharacterBit(unsigned int bit, bool notifyClient = false);

	bool clearCharacterBit(unsigned int bit, bool notifyClient = false);

	void toggleCharacterBit(unsigned int bit);

	VectorMap<String, int>* getXpTypeCapList();

	DeltaVectorMap<String, int>* getExperienceList();

	int getForcePower();

	int getForcePowerMax();

	WaypointList* getWaypointList();

	SkillList* getSkills();

	SchematicList* getSchematics();

	DraftSchematic* getSchematic(int i);

	Vector<ManagedReference<DraftSchematic* > > filterSchematicList(PlayerCreature* player, Vector<unsigned int>* enabledTabs, int complexityLevel);

	int getFoodFilling();

	int getFoodFillingMax();

	int getDrinkFilling();

	int getDrinkFillingMax();

	int getJediState();

	byte getLanguageID();

	DeltaVector<String>* getFriendList();

	DeltaVector<String>* getIgnoreList();

	int getExperience(const String& xp);

	String getCommandMessageString(unsigned int actionCRC);

protected:
	PlayerObject(DummyConstructorParameter* param);

	virtual ~PlayerObject();

	String _return_getCommandMessageString;
	String _return_getTitle;

	friend class PlayerObjectHelper;
};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerObjectImplementation : public IntangibleObjectImplementation {
protected:
	unsigned int characterBitmask;

	String title;

	int forcePower;

	int forcePowerMax;

	int foodFilling;

	int foodFillingMax;

	int drinkFilling;

	int drinkFillingMax;

	int jediState;

	unsigned int adminLevel;

	byte languageID;

	VectorMap<String, int> xpTypeCapList;

	VectorMap<unsigned int, String> commandMessageStrings;

	DeltaVectorMap<String, int> experienceList;

	WaypointList waypointList;

	SkillList skillList;

	CommandArgumentList skillArgumentList;

	FriendList friendList;

	IgnoreList ignoreList;

	SchematicList schematicList;

public:
	static const int LFG = 1;

	static const int NEWBIEHELPER = 2;

	static const int ROLEPLAYER = 4;

	static const int AFK = 0x80;

	static const int LD = 0x100;

	static const int FACTIONRANK = 0x200;

	static const int ANONYMOUS = 0x80000000;

	static const int CSR = 1;

	static const int DEV = 2;

	PlayerObjectImplementation();

	PlayerObjectImplementation(DummyConstructorParameter* param);

	void finalize();

	void loadTemplateData(SharedObjectTemplate* templateData);

	void initializeTransientMembers();

	void sendBaselinesTo(SceneObject* player);

	void sendMessage(BasePacket* msg);

	int addExperience(const String& xpType, int xp, bool notifyClient = true);

	void removeExperience(const String& xpType, bool notifyClient = true);

	void addWaypoint(WaypointObject* waypoint, bool checkName, bool notifyClient = true);

	void setWaypoint(WaypointObject* waypoint, bool notifyClient = true);

	void addWaypoint(const String& planet, float positionX, float positionY, bool notifyClient = true);

	void removeWaypoint(unsigned long long waypointID, bool notifyClient = true);

	void addSkills(Vector<QueueCommand*>& skills, bool notifyClient = true);

	void addSkills(Vector<Certification*>& skills, bool notifyClient = true);

	void addSkillArgument(const String& skillName, const String& argument);

	void dropSkillArgument(const String& skillName, const String& argument);

	bool hasSkillArgument(const String& skillName, const String& argument);

	CommandArgumentList* getCommandArgumentList();

	void removeSkills(Vector<QueueCommand*>& skills, bool notifyClient = true);

	void removeSkills(Vector<Certification*>& skills, bool notifyClient = true);

	void addSchematics(Vector<ManagedReference<DraftSchematic* > >& schematics, bool notifyClient = true);

	void removeSchematics(Vector<ManagedReference<DraftSchematic* > >& schematics, bool notifyClient = true);

	void addSchematic(DraftSchematic* schematic, bool notifyClient = true);

	void removeSchematic(DraftSchematic* schematic, bool notifyClient = true);

	void setLanguageID(byte language, bool notifyClient = true);

	void addFriend(const String& name, bool notifyClient = true);

	void removeFriend(const String& name, bool notifyClient = true);

	void addIgnore(const String& name, bool notifyClient = true);

	void removeIgnore(const String& name, bool notifyClient = true);

	void setTitle(const String& characterTitle, bool notifyClient = true);

	void setFoodFilling(int newValue, bool notifyClient = true);

	void setDrinkFilling(int newValue, bool notifyClient = true);

	void setCommandMessageString(unsigned int actionCRC, String& message);

	void removeCommandMessageString(unsigned int actionCRC);

	void notifyOnline();

	void doDigest();

	bool isDigesting();

	void notifyOffline();

	bool hasFriend(const String& name);

	bool isIgnoring(const String& name);

	void addReverseFriend(const String& name);

	void removeReverseFriend(const String& name);

	void sendFriendLists();

	bool hasWaypoint(unsigned long long objectID);

	bool hasSkill(Skill* skill);

	bool hasSkill(const String& skillName);

	bool hasCommandMessageString(unsigned int actionCRC);

	unsigned int getCharacterBitmask();

	String getTitle();

	unsigned int getAdminLevel();

	bool isDeveloper();

	bool isCSR();

	bool isPrivileged();

	void setCharacterBitmask(unsigned int bitmask);

	bool setCharacterBit(unsigned int bit, bool notifyClient = false);

	bool clearCharacterBit(unsigned int bit, bool notifyClient = false);

	void toggleCharacterBit(unsigned int bit);

	VectorMap<String, int>* getXpTypeCapList();

	DeltaVectorMap<String, int>* getExperienceList();

	int getForcePower();

	int getForcePowerMax();

	WaypointList* getWaypointList();

	SkillList* getSkills();

	SchematicList* getSchematics();

	DraftSchematic* getSchematic(int i);

	Vector<ManagedReference<DraftSchematic* > > filterSchematicList(PlayerCreature* player, Vector<unsigned int>* enabledTabs, int complexityLevel);

	int getFoodFilling();

	int getFoodFillingMax();

	int getDrinkFilling();

	int getDrinkFillingMax();

	int getJediState();

	byte getLanguageID();

	DeltaVector<String>* getFriendList();

	DeltaVector<String>* getIgnoreList();

	int getExperience(const String& xp);

	String getCommandMessageString(unsigned int actionCRC);

	PlayerObject* _this;

	operator const PlayerObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~PlayerObjectImplementation();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class PlayerObject;
};

class PlayerObjectAdapter : public IntangibleObjectAdapter {
public:
	PlayerObjectAdapter(PlayerObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void finalize();

	void initializeTransientMembers();

	void sendBaselinesTo(SceneObject* player);

	void sendMessage(BasePacket* msg);

	int addExperience(const String& xpType, int xp, bool notifyClient);

	void removeExperience(const String& xpType, bool notifyClient);

	void addWaypoint(WaypointObject* waypoint, bool checkName, bool notifyClient);

	void setWaypoint(WaypointObject* waypoint, bool notifyClient);

	void addWaypoint(const String& planet, float positionX, float positionY, bool notifyClient);

	void removeWaypoint(unsigned long long waypointID, bool notifyClient);

	void addSkillArgument(const String& skillName, const String& argument);

	void dropSkillArgument(const String& skillName, const String& argument);

	bool hasSkillArgument(const String& skillName, const String& argument);

	void setLanguageID(byte language, bool notifyClient);

	void addFriend(const String& name, bool notifyClient);

	void removeFriend(const String& name, bool notifyClient);

	void addIgnore(const String& name, bool notifyClient);

	void removeIgnore(const String& name, bool notifyClient);

	void setTitle(const String& characterTitle, bool notifyClient);

	void setFoodFilling(int newValue, bool notifyClient);

	void setDrinkFilling(int newValue, bool notifyClient);

	void setCommandMessageString(unsigned int actionCRC, String& message);

	void removeCommandMessageString(unsigned int actionCRC);

	void notifyOnline();

	void doDigest();

	bool isDigesting();

	void notifyOffline();

	bool hasFriend(const String& name);

	bool isIgnoring(const String& name);

	void addReverseFriend(const String& name);

	void removeReverseFriend(const String& name);

	void sendFriendLists();

	bool hasWaypoint(unsigned long long objectID);

	bool hasSkill(const String& skillName);

	bool hasCommandMessageString(unsigned int actionCRC);

	unsigned int getCharacterBitmask();

	String getTitle();

	unsigned int getAdminLevel();

	bool isDeveloper();

	bool isCSR();

	bool isPrivileged();

	void setCharacterBitmask(unsigned int bitmask);

	bool setCharacterBit(unsigned int bit, bool notifyClient);

	bool clearCharacterBit(unsigned int bit, bool notifyClient);

	void toggleCharacterBit(unsigned int bit);

	int getForcePower();

	int getForcePowerMax();

	DraftSchematic* getSchematic(int i);

	int getFoodFilling();

	int getFoodFillingMax();

	int getDrinkFilling();

	int getDrinkFillingMax();

	int getJediState();

	byte getLanguageID();

	int getExperience(const String& xp);

	String getCommandMessageString(unsigned int actionCRC);

protected:
	String _param0_addExperience__String_int_bool_;
	String _param0_removeExperience__String_bool_;
	String _param0_addWaypoint__String_float_float_bool_;
	String _param0_addSkillArgument__String_String_;
	String _param1_addSkillArgument__String_String_;
	String _param0_dropSkillArgument__String_String_;
	String _param1_dropSkillArgument__String_String_;
	String _param0_hasSkillArgument__String_String_;
	String _param1_hasSkillArgument__String_String_;
	String _param0_addFriend__String_bool_;
	String _param0_removeFriend__String_bool_;
	String _param0_addIgnore__String_bool_;
	String _param0_removeIgnore__String_bool_;
	String _param0_setTitle__String_bool_;
	String _param1_setCommandMessageString__int_String_;
	String _param0_hasFriend__String_;
	String _param0_isIgnoring__String_;
	String _param0_addReverseFriend__String_;
	String _param0_removeReverseFriend__String_;
	String _param0_hasSkill__String_;
	String _param0_getExperience__String_;
};

class PlayerObjectHelper : public DistributedObjectClassHelper, public Singleton<PlayerObjectHelper> {
	static PlayerObjectHelper* staticInitializer;

public:
	PlayerObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PlayerObjectHelper>;
};

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

#endif /*PLAYEROBJECT_H_*/
