#include "deserialization.h"
void deserialize(std::vector<unsigned char> &buf, boost::property_tree::ptree &data) {
	auto snake_data = snakedata::Getsnakebodydata(buf.data());
	data.put("table.width", snake_data->board()->width());
	data.put("table.height", snake_data->board()->height());
	data.put("snakefood.x", snake_data->snakefood()->x());
	data.put("snakefood.y", snake_data->snakefood()->y());
	data.put("game_status", snake_data->gamestatus()->str());
	data.put("game_score", snake_data->gamescore());
	auto snakebodylength = snake_data->snakebody()->Length();
	for (int i = 0; i < snakebodylength; i++) {
		data.put("snakebody.point"+std::to_string(i)+".x", snake_data->snakebody()->Get(i)->x());
		data.put("snakebody.point"+std::to_string(i)+".y", snake_data->snakebody()->Get(i)->y());
		}
	data.put("snakebody.length", snakebodylength);
	


};