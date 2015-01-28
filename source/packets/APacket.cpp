#include "stdafx.h"
#include "APacket.h"
#include "MinecraftProtoParser.h"

APacket::APacket()
	: isRegistred(false)
{
}


APacket::~APacket()
{
}

bool APacket::parse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint32 offset)
{
	if (!isRegistred)
	{
		isRegistred = true;
		hf_register_info *hf = getFieldInfo();
		proto_register_field_array(MinecraftProtoParser::getInstance()->getProto(), hf, array_length(hf));
	}
	quint32 myOffset = offset;
	return internal_parse(tree, tvb, pinfo, myOffset);
}

void APacket::addToTree(hf_register_info &registerInfo, proto_tree *tree, tvbuff_t *tvb, guint32 &offset)
{
	quint16 strlen = tvb_get_ntohs(tvb, offset);
	addToTree(registerInfo, tree, tvb, offset, strlen);
}

void APacket::addToTree(hf_register_info &registerInfo, proto_tree *tree, tvbuff_t *tvb, guint32 &offset, quint16 length)
{
	proto_tree_add_item(tree, registerInfo, tvb, offset, length, FALSE);
	offset += length;
}

