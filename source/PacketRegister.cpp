/*
 * PacketRegister.cpp
 *
 *  Created on: 29.01.2015
 *      Author: maniak
 */
#include "stdafx.h"
#include <PacketRegister.h>
#include "packets/APacket.h"

PacketRegister PacketRegister::mInstance;

PacketRegister::PacketRegister() {


}

PacketRegister::~PacketRegister() {
	for (Packets::iterator it = mPackets.begin(); it != mPackets.end(); ++it)
		delete it->second;
	mPackets.clear();
}

PacketRegister *PacketRegister::getInstance()
{
	return &mInstance;
}

APacket *PacketRegister::getPacket(int type)
{
	Packets::iterator it = mPackets.find(type);
	if (it == mPackets.end())
		return NULL;
	return it->second;
}

value_string *PacketRegister::getNames()
{
	return &mNames[0];
}

void PacketRegister::addPacket(APacket *packet)
{
	mPackets[packet->getId()] = packet;
	mNames.push_back({packet->getId(), packet->getName()});
}
