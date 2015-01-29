#!/bin/bash

xsltproc -o source/packets/packets.h packets_h.xsl proto.xml
xsltproc -o source/packets/packets.cpp packets_cpp.xsl proto.xml

