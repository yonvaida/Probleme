#pragma once
#include "serialization.h"
void serialize(flatbuffers::FlatBufferBuilder &builder, boost::property_tree::ptree data) {

	auto board = snakedata::Createboarddata(builder, data.get<int>("table.width"), data.get<int>("table.height"));
	auto snakefood = snakedata::Createsnakefooddata(builder,data.get<int>("snakefood.x"), data.get<int>("snakefood.y"));
	std::vector<flatbuffers::Offset<snakedata::snakebodypoint>> snakebodypoints;
	for (int i = 0; i < data.get<int>("snakebody.length"); i++) {
		snakebodypoints.push_back(snakedata::Createsnakebodypoint(builder, data.get<int>("snakebody.point" + std::to_string(i) + ".x"), data.get<int>("snakebody.point" + std::to_string(i) + ".y")));
	};
	auto snakebodypointsvector = builder.CreateVector(snakebodypoints);
	auto gamestatus = builder.CreateString(data.get<std::string>("game_status"));
	auto gamescore = data.get<int>("game_score");
	auto snake_data = snakedata::Createsnakebodydata(builder,snakebodypointsvector, board,snakefood,gamestatus,gamescore);
	snakedata::FinishsnakebodydataBuffer(builder, snake_data);
		
}