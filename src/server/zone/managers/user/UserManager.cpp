/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

/*
 *	server/zone/managers/user/UserManager.cpp generated by Engine3 IDL compiler 0.51
 */

#include "UserManager.h"

#include "UserManagerImplementation.h"

/*
 *	UserManagerStub
 */

UserManager::UserManager() : ORBObjectStub(NULL) {
}

UserManager::UserManager(ORBObjectServant* obj) : ORBObjectStub(obj) {
}

UserManager::UserManager(UserManager& ref) : ORBObjectStub(ref) {
}

UserManager::~UserManager() {
}

UserManager* UserManager::clone() {
	return new UserManager(*this);
}


bool UserManager::checkUser(unsigned int ipid) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);
		invocation.addUnsignedIntParameter(ipid);

		return invocation.executeWithBooleanReturn();
	} else
		return ((UserManagerImplementation*) _impl)->checkUser(ipid);
}

bool UserManager::isAdmin(const string& name) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);
		invocation.addAsciiParameter(name);

		return invocation.executeWithBooleanReturn();
	} else
		return ((UserManagerImplementation*) _impl)->isAdmin(name);
}

void UserManager::parseBanList() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);

		invocation.executeWithVoidReturn();
	} else
		((UserManagerImplementation*) _impl)->parseBanList();
}

void UserManager::banUser(const string& ipaddr) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 9);
		invocation.addAsciiParameter(ipaddr);

		invocation.executeWithVoidReturn();
	} else
		((UserManagerImplementation*) _impl)->banUser(ipaddr);
}

bool UserManager::banUserByName(string& name, string& admin) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 10);
		invocation.addAsciiParameter(name);
		invocation.addAsciiParameter(admin);

		return invocation.executeWithBooleanReturn();
	} else
		return ((UserManagerImplementation*) _impl)->banUserByName(name, admin);
}

void UserManager::changeUserCap(int amount) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 11);
		invocation.addSignedIntParameter(amount);

		invocation.executeWithVoidReturn();
	} else
		((UserManagerImplementation*) _impl)->changeUserCap(amount);
}

bool UserManager::isBannedUser(unsigned int ipid) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 12);
		invocation.addUnsignedIntParameter(ipid);

		return invocation.executeWithBooleanReturn();
	} else
		return ((UserManagerImplementation*) _impl)->isBannedUser(ipid);
}

int UserManager::getUserCap() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 13);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((UserManagerImplementation*) _impl)->getUserCap();
}

/*
 *	UserManagerAdapter
 */

UserManagerAdapter::UserManagerAdapter(UserManagerImplementation* obj) : ORBObjectAdapter((ORBObjectServant*) obj) {
}

Packet* UserManagerAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertBoolean(checkUser(inv->getUnsignedIntParameter()));
		break;
	case 7:
		resp->insertBoolean(isAdmin(inv->getAsciiParameter(_param0_isAdmin__string_)));
		break;
	case 8:
		parseBanList();
		break;
	case 9:
		banUser(inv->getAsciiParameter(_param0_banUser__string_));
		break;
	case 10:
		resp->insertBoolean(banUserByName(inv->getAsciiParameter(_param0_banUserByName__string_string_), inv->getAsciiParameter(_param1_banUserByName__string_string_)));
		break;
	case 11:
		changeUserCap(inv->getSignedIntParameter());
		break;
	case 12:
		resp->insertBoolean(isBannedUser(inv->getUnsignedIntParameter()));
		break;
	case 13:
		resp->insertSignedInt(getUserCap());
		break;
	default:
		return NULL;
	}

	return resp;
}

bool UserManagerAdapter::checkUser(unsigned int ipid) {
	return ((UserManagerImplementation*) impl)->checkUser(ipid);
}

bool UserManagerAdapter::isAdmin(const string& name) {
	return ((UserManagerImplementation*) impl)->isAdmin(name);
}

void UserManagerAdapter::parseBanList() {
	return ((UserManagerImplementation*) impl)->parseBanList();
}

void UserManagerAdapter::banUser(const string& ipaddr) {
	return ((UserManagerImplementation*) impl)->banUser(ipaddr);
}

bool UserManagerAdapter::banUserByName(string& name, string& admin) {
	return ((UserManagerImplementation*) impl)->banUserByName(name, admin);
}

void UserManagerAdapter::changeUserCap(int amount) {
	return ((UserManagerImplementation*) impl)->changeUserCap(amount);
}

bool UserManagerAdapter::isBannedUser(unsigned int ipid) {
	return ((UserManagerImplementation*) impl)->isBannedUser(ipid);
}

int UserManagerAdapter::getUserCap() {
	return ((UserManagerImplementation*) impl)->getUserCap();
}

/*
 *	UserManagerHelper
 */

ORBClassHelper* UserManagerHelper::instance = new UserManagerHelper();

UserManagerHelper::UserManagerHelper() {
	className = "UserManager";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

ORBClassHelper* UserManagerHelper::getInstance() {
	if (instance == NULL)
		return instance = new UserManagerHelper();
	else
		return instance;
}

ORBObject* UserManagerHelper::instantiateObject() {
	return new UserManager();
}

ORBObjectAdapter* UserManagerHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new UserManagerAdapter((UserManagerImplementation*)obj);

	ORBObjectStub* stub = new UserManager(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	UserManagerServant
 */

UserManagerServant::UserManagerServant() {
	_classHelper = UserManagerHelper::getInstance();
}

UserManagerServant::~UserManagerServant() {
}
void UserManagerServant::_setStub(ORBObjectStub* stub) {
	_this = (UserManager*) stub;
}

ORBObjectStub* UserManagerServant::_getStub() {
	return _this;
}

