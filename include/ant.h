#pragma once
#include <vector>


enum Roles {
	FORAGER,
	SOLDIER,
};

class Ant {
	public:
		Ant();
		Ant(int id, std::vector<int> base_coord, Roles role);
		~Ant();
		void destroy();
		void forageFood();
		void scavenge();
		void carryFood();
		void depositFood();
		void returnToBase();
		void returnToFoodSite();
		void getFoodSiteLocation();
		void getCarryState();

		

	private:
		Roles role;
		int colony_id;
		bool carrying_food;
		bool foraging;
		std::vector<int> base_coordinates;
		std::vector<int> food_site_coordinates;
};
