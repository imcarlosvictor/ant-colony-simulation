#pragma once
#include <vector>


class Colony {
	public:
		Colony();
		Colony(int id, int population, int food_supply);
		~Colony();
		void destroy();
		void spawnAnts();
		void getColonyID();
		void getPopulation();
		void getFoodSupply();
		std::vector<int> getCoordinates();
	
	private:
		int colony_id;
		int population;
		int food_supply;
		std::vector<int> base_coordinates;
};
