#include "stdafx.h"

#include "MinecraftProtoParser.h"





void proto_register_foo(void)
{
	MinecraftProtoParser::getInstance()->proto_register_foo();
}

void proto_reg_handoff_foo(void)
{
	MinecraftProtoParser::getInstance()->proto_reg_handoff_foo();
}