#include "APacket.h"
#include "MinecraftProtoParser.h"
#include "PacketRegister.h"

static gint hf_mc_id_PacketData = -1;
static gint hf_mc_id_Type = -1;
static hf_register_info hf_mc_PacketData = {&hf_mc_id_PacketData, {"Data", "mc.data", FT_NONE, BASE_NONE, NULL, 0x0, "Packet Data", HFILL}};
static hf_register_info hf_mc_Type = {&hf_mc_id_Type, { "Type", "mc.type", FT_UINT8, BASE_DEC, RVALS(PacketRegister::getInstance()->getNames()), 0x0, "Packet Type", HFILL }};

APacket::APacket()
	: isRegistred(false)
{
	mRegInfo.push_back(&hf_mc_PacketData);
	mRegInfo.push_back(&hf_mc_Type);
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
	guint32 myOffset = offset;
	return internal_parse(tree, tvb, pinfo, myOffset);
}

void APacket::init()
{
	hf_register_info *child = getFieldInfo_internal();
	size_t size = array_length(child);
	for (size_t i = 0; i < size; ++i)
		mRegInfo.push_back(&child[i]);
}

hf_register_info *APacket::getFieldInfo()
{
	return mRegInfo[0];
}

void APacket::addToTree(int registerInfo, proto_tree *tree, tvbuff_t *tvb, guint32 &offset)
{
	guint16 strlen = tvb_get_ntohs(tvb, offset);
	addToTree(registerInfo, tree, tvb, offset, strlen);
}

void APacket::addToTree(int registerInfo, proto_tree *tree, tvbuff_t *tvb, guint32 &offset, guint16 length)
{
	proto_tree_add_item(tree, registerInfo, tvb, offset, length, false);
	offset += length;
}

