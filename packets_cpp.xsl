<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet
    version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" encoding="Windows-1252"/>
    <xsl:variable name="empty" select="/@empty" />
    <xsl:variable name="smallcase" select="'abcdefghijklmnopqrstuvwxyz'" />
    <xsl:variable name="uppercase" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'" />
    <xsl:template name="ParseType">
        <xsl:param name="type"/>
    </xsl:template>

  <xsl:template match="/">/* autogenerated file */
#include "stdafx.h"
#include "packets.h"
#include "MinecraftProtoParser.h"

void getAllPackets(std::vector&lt;APacket *> &amp;packets)
{
    <xsl:for-each select="/proto/packet">
    packets.push_back(new <xsl:value-of select="./@state"/>_<xsl:value-of select="./@name"/>_<xsl:value-of select="./@boundto"/>());</xsl:for-each>    
}

<xsl:for-each select="/proto/class">
/////////////////////////////////////////////////////////////////////////
// <xsl:value-of select="./@name"/>
/////////////////////////////////////////////////////////////////////////
bool <xsl:value-of select="./@name"/>::internal_parse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint32 &amp;offset)
{
    static int ett_t = -1;
    /* Setup protocol subtree array */
    static int *ett[] = {
        &amp;ett_t
    };

    proto_item *mc_item = proto_tree_add_item(tree, MinecraftProtoParser::getInstance()->getProto(), tvb, offset, length, FALSE);
    tree = proto_item_add_subtree(mc_item, ett_mc);


}
</xsl:for-each>

<xsl:for-each select="/proto/packet"><xsl:variable name="classname" select="./@name" />
/////////////////////////////////////////////////////////////////////////
// <xsl:value-of select="./@state"/>_<xsl:value-of select="./@name"/>_<xsl:value-of select="./@boundto"/>
/////////////////////////////////////////////////////////////////////////

<xsl:value-of select="./@state"/>_<xsl:value-of select="./@name"/>_<xsl:value-of select="./@boundto"/>::<xsl:value-of select="./@state"/>_<xsl:value-of select="./@name"/>_<xsl:value-of select="./@boundto"/>()
    : APacket()
    <xsl:for-each select="./@field">
    , hf_mc_id_<xsl:value-of select="./@name"/>(-1)
    , hf_mc_<xsl:value-of select="./@name"/>({&amp;hf_mc_id_<xsl:value-of select="./@name"/>, {
    <xsl:value-of select="./@name"/>,
    "mc.<xsl:value-of select="$classname"/>_<xsl:value-of select="translate(./@name, $smallcase, $uppercase)"/>".
    <xsl:choose>
        <!--xsl:when test=""></xsl:when-->
    </xsl:choose>
    }})</xsl:for-each>
{
    <xsl:for-each select="./@field">
    mRegInfo.push_back(&amp;hf_mc_<xsl:value-of select="./@name"/>);</xsl:for-each>
}

<xsl:value-of select="./@state"/>_<xsl:value-of select="./@name"/>_<xsl:value-of select="./@boundto"/>::~<xsl:value-of select="./@state"/>_<xsl:value-of select="./@name"/>_<xsl:value-of select="./@boundto"/>()
{
}

bool <xsl:value-of select="./@state"/>_<xsl:value-of select="./@name"/>_<xsl:value-of select="./@boundto"/>::isClientSide()
{
    <xsl:choose>
    <xsl:when test="./@boundto='Client'">return true;</xsl:when>
    <xsl:when test="./@boundto='Server'">return false;</xsl:when>
    <xsl:otherwise>
        #pragma message("WHAAAAT? what is type '<xsl:value-of select="./@boundto"/>'")
        return false;
    </xsl:otherwise>
    </xsl:choose>
}

APacket::EState <xsl:value-of select="./@state"/>_<xsl:value-of select="./@name"/>_<xsl:value-of select="./@boundto"/>::getState()
{
    return APacket::eState<xsl:value-of select="./@state"/>
}

hf_register_info *<xsl:value-of select="./@state"/>_<xsl:value-of select="./@name"/>_<xsl:value-of select="./@boundto"/>::getFieldInfo_internal()
{
    return &amp;mRegInfo[0];
}

int <xsl:value-of select="./@state"/>_<xsl:value-of select="./@name"/>_<xsl:value-of select="./@boundto"/>::getId()
{
    return <xsl:value-of select="./@id"/>;
}

bool <xsl:value-of select="./@state"/>_<xsl:value-of select="./@name"/>_<xsl:value-of select="./@boundto"/>::internal_parse(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, guint32 &amp;offset)
{
    return true;    
}

</xsl:for-each>
  </xsl:template>
</xsl:stylesheet>