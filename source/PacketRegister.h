/*
 * PacketRegister.h
 *
 *  Created on: 29.01.2015
 *      Author: maniak
 */
#include "stdafx.h"
#ifndef PACKETREGISTER_H_
#define PACKETREGISTER_H_

class APacket;

class PacketRegister {
private:
	PacketRegister();
	static PacketRegister mInstance;

	typedef std::map<int, APacket *> Packets;
	Packets mPackets;

	typedef std::vector<value_string> Names;
	Names mNames;
public:
	static PacketRegister *getInstance();

	//Can return NULL
	APacket *getPacket(int type);
	value_string *getNames();
	void addPacket(APacket *packet);
	virtual ~PacketRegister();
};

#endif /* PACKETREGISTER_H_ */
