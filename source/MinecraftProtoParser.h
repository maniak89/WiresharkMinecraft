#pragma once

class MinecraftProtoParser
{
private:
	~MinecraftProtoParser();
	MinecraftProtoParser();

	static MinecraftProtoParser mInstance;
	static void dissect_foo(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);

	int proto_minecraft;
public:
	static MinecraftProtoParser *getInstance();
	void proto_register_foo();
	void proto_reg_handoff_foo();
	int getProto();
	
	
};

