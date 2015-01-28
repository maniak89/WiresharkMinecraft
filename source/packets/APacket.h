#pragma once

class APacket
{
public:
	virtual ~APacket();
    bool parse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint32 offset);
protected:
	friend class packetRegister;
	APacket();

	virtual hf_register_info *getFieldInfo() = 0;
	virtual int getId() = 0;
	virtual bool internal_parse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint32 &offset) = 0;

	void addToTree(hf_register_info &registerInfo, proto_tree *tree, tvbuff_t *tvb, guint32 &offset);
	void addToTree(hf_register_info &registerInfo, proto_tree *tree, tvbuff_t *tvb, guint32 &offset, guint16 length);

private:
	bool isRegistred;
};

