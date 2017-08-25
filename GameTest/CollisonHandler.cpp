#include "CollisonHandler.h"


std::vector<Block> * CollisonHandler::checkPlayerBlockCollisions(const Player &player, const std::vector<Block> &blocks)
{
	intersections.clear();
	for (Block block : blocks)
	{
		system("cls");
		//std::cout << player.position << std::endl << block.position << std::endl << block.bb.Center << std::endl;

		if (checkAABB(player.bb, block.bb))
		{
			//intersections.push_back(block);
			std::cout << block.position << "                          " << player.position << std::endl;
		}
	}
	return &intersections;
}

bool CollisonHandler::checkAABB(const BoundingBox &bb1, const BoundingBox &bb2)
{
	//std::cout << bb1.Center << "              " << bb2.Center << std::endl;
	//std::cout << bb1.Center;// << "             " << bb2.Center << std::endl;
	//std::cout << "Player under: "<<(bb1.RightUpFront >= bb2.LeftDownBack) << "                    Block under: " << (bb1.LeftDownFront <= bb2.RightUpBack) << std::endl;

	if (bb1.LeftUpBack <= bb2.RightDownFront && bb1.RightDownFront >= bb2.LeftUpBack)
	{
		return true;
	}
	else
		return false;
}
