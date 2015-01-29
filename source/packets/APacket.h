#include "stdafx.h"
#ifndef APACKET_H
#define APACKET_H

class APacket
{
public:
	enum EState
	{
		eStateHandshake,
		eStatePlay,
		eStateStatus,
		eStateLogin
	};
	virtual ~APacket();
    bool parse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint32 offset);
    virtual bool isClientSide() = 0;
    virtual EState getState() = 0;
protected:
	APacket();

	friend class PacketRegister;

	void init();
	hf_register_info *getFieldInfo();

	virtual hf_register_info *getFieldInfo_internal() = 0;
	virtual int getId() = 0;
	virtual const char *getName() = 0;
	virtual bool internal_parse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint32 &offset) = 0;

	void addToTree(int registerInfo, proto_tree *tree, tvbuff_t *tvb, guint32 &offset);
	void addToTree(int registerInfo, proto_tree *tree, tvbuff_t *tvb, guint32 &offset, guint16 length);

private:
	bool isRegistred;
	typedef std::vector<hf_register_info *> RegInfo;
	RegInfo mRegInfo;
};

#endif
