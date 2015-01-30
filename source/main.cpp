#include "stdafx.h"

#include "MinecraftProtoParser.h"

extern "C" G_MODULE_EXPORT const gchar version[] = "0.0";

static void proto_register_minecraft(void)
{
	MinecraftProtoParser::getInstance()->proto_register();
}

static void proto_reg_handoff_minecraft(void)
{
	MinecraftProtoParser::getInstance()->proto_reg_handoff();
}

extern "C" G_MODULE_EXPORT void plugin_register(void)
{
	proto_register_minecraft();
}

extern "C" G_MODULE_EXPORT void plugin_reg_handoff(void) {
	proto_reg_handoff_minecraft();
}
