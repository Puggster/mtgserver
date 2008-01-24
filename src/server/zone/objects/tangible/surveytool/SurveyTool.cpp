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
 *	server/zone/objects/tangible/surveytool/SurveyTool.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../TangibleObject.h"

#include "../../../packets.h"

#include "../../player/Player.h"

#include "../../creature/CreatureObject.h"

#include "SurveyTool.h"

#include "SurveyToolImplementation.h"

/*
 *	SurveyToolStub
 */

SurveyTool::SurveyTool() : TangibleObject(NULL) {
}

SurveyTool::SurveyTool(ORBObjectServant* obj) : TangibleObject(obj) {
}

SurveyTool::SurveyTool(SurveyTool& ref) : TangibleObject(ref) {
}

SurveyTool::~SurveyTool() {
}

SurveyTool* SurveyTool::clone() {
	return new SurveyTool(*this);
}


int SurveyTool::useObject(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);
		invocation.addObjectParameter(player);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((SurveyToolImplementation*) _impl)->useObject(player);
}

int SurveyTool::getSurveyToolType() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((SurveyToolImplementation*) _impl)->getSurveyToolType();
}

int SurveyTool::getSurveyToolRange() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((SurveyToolImplementation*) _impl)->getSurveyToolRange();
}

void SurveyTool::setSurveyToolRange(int range) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 9);
		invocation.addSignedIntParameter(range);

		invocation.executeWithVoidReturn();
	} else
		((SurveyToolImplementation*) _impl)->setSurveyToolRange(range);
}

void SurveyTool::sendSurveyEffect(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 10);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((SurveyToolImplementation*) _impl)->sendSurveyEffect(player);
}

void SurveyTool::sendSampleEffect(Player* player) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 11);
		invocation.addObjectParameter(player);

		invocation.executeWithVoidReturn();
	} else
		((SurveyToolImplementation*) _impl)->sendSampleEffect(player);
}

void SurveyTool::surveyRequest(Player* player, unicode& resourceName) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 12);
		invocation.addObjectParameter(player);
		invocation.addUnicodeParameter(resourceName);

		invocation.executeWithVoidReturn();
	} else
		((SurveyToolImplementation*) _impl)->surveyRequest(player, resourceName);
}

void SurveyTool::sampleRequest(Player* player, unicode& resourceName) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 13);
		invocation.addObjectParameter(player);
		invocation.addUnicodeParameter(resourceName);

		invocation.executeWithVoidReturn();
	} else
		((SurveyToolImplementation*) _impl)->sampleRequest(player, resourceName);
}

/*
 *	SurveyToolAdapter
 */

SurveyToolAdapter::SurveyToolAdapter(SurveyToolImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* SurveyToolAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 7:
		resp->insertSignedInt(getSurveyToolType());
		break;
	case 8:
		resp->insertSignedInt(getSurveyToolRange());
		break;
	case 9:
		setSurveyToolRange(inv->getSignedIntParameter());
		break;
	case 10:
		sendSurveyEffect((Player*) inv->getObjectParameter());
		break;
	case 11:
		sendSampleEffect((Player*) inv->getObjectParameter());
		break;
	case 12:
		surveyRequest((Player*) inv->getObjectParameter(), inv->getUnicodeParameter(_param1_surveyRequest__Player_unicode_));
		break;
	case 13:
		sampleRequest((Player*) inv->getObjectParameter(), inv->getUnicodeParameter(_param1_sampleRequest__Player_unicode_));
		break;
	default:
		return NULL;
	}

	return resp;
}

int SurveyToolAdapter::useObject(Player* player) {
	return ((SurveyToolImplementation*) impl)->useObject(player);
}

int SurveyToolAdapter::getSurveyToolType() {
	return ((SurveyToolImplementation*) impl)->getSurveyToolType();
}

int SurveyToolAdapter::getSurveyToolRange() {
	return ((SurveyToolImplementation*) impl)->getSurveyToolRange();
}

void SurveyToolAdapter::setSurveyToolRange(int range) {
	return ((SurveyToolImplementation*) impl)->setSurveyToolRange(range);
}

void SurveyToolAdapter::sendSurveyEffect(Player* player) {
	return ((SurveyToolImplementation*) impl)->sendSurveyEffect(player);
}

void SurveyToolAdapter::sendSampleEffect(Player* player) {
	return ((SurveyToolImplementation*) impl)->sendSampleEffect(player);
}

void SurveyToolAdapter::surveyRequest(Player* player, unicode& resourceName) {
	return ((SurveyToolImplementation*) impl)->surveyRequest(player, resourceName);
}

void SurveyToolAdapter::sampleRequest(Player* player, unicode& resourceName) {
	return ((SurveyToolImplementation*) impl)->sampleRequest(player, resourceName);
}

/*
 *	SurveyToolHelper
 */

ORBClassHelper* SurveyToolHelper::instance = new SurveyToolHelper();

SurveyToolHelper::SurveyToolHelper() {
	className = "SurveyTool";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

ORBClassHelper* SurveyToolHelper::getInstance() {
	if (instance == NULL)
		return instance = new SurveyToolHelper();
	else
		return instance;
}

ORBObject* SurveyToolHelper::instantiateObject() {
	return new SurveyTool();
}

ORBObjectAdapter* SurveyToolHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new SurveyToolAdapter((SurveyToolImplementation*)obj);

	ORBObjectStub* stub = new SurveyTool(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	SurveyToolServant
 */

SurveyToolServant::SurveyToolServant(CreatureObject* creature, const unicode& n, const string& tempn, int tempCRC, int tp) : TangibleObjectImplementation(creature, n, tempn, tempCRC, tp) {
	_classHelper = SurveyToolHelper::getInstance();
}

SurveyToolServant::SurveyToolServant(unsigned long long oid, const unicode& n, const string& tempn, int tempCRC, int tp) : TangibleObjectImplementation(oid, n, tempn, tempCRC, tp) {
	_classHelper = SurveyToolHelper::getInstance();
}

SurveyToolServant::~SurveyToolServant() {
}
void SurveyToolServant::_setStub(ORBObjectStub* stub) {
	_this = (SurveyTool*) stub;
	TangibleObjectServant::_setStub(stub);
}

ORBObjectStub* SurveyToolServant::_getStub() {
	return _this;
}

