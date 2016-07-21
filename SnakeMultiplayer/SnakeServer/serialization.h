#pragma once
#include "flatbuffer\snakedata_generated.h"
#include <boost\property_tree\ptree.hpp>
void serialize(flatbuffers::FlatBufferBuilder &builder, boost::property_tree::ptree data);