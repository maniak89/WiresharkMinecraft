#include "stdafx.h"
#include "MinecraftProtoParser.h"

MinecraftProtoParser MinecraftProtoParser::mInstance;

#define MINECRAFT_PORT 25565

MinecraftProtoParser::MinecraftProtoParser()
	: proto_minecraft(-1)
{
}


MinecraftProtoParser::~MinecraftProtoParser()
{
}

MinecraftProtoParser *MinecraftProtoParser::getInstance()
{
	return &mInstance;
}

void MinecraftProtoParser::dissect_foo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{

}

void MinecraftProtoParser::proto_register()
{
	proto_minecraft = proto_register_protocol(
		"Minecraft", /* ������ ��� */
		"MC",          /* �������� ��� */
		"mc"           /* ������������ */
		);
}

void MinecraftProtoParser::proto_reg_handoff()
{
	dissector_handle_t minecraft_handle;

	minecraft_handle = create_dissector_handle(MinecraftProtoParser::dissect_foo, proto_minecraft);
	dissector_add_uint("tcp.port", MINECRAFT_PORT, minecraft_handle);
}

int MinecraftProtoParser::getProto()
{
	return proto_minecraft;
}

