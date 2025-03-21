class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_set<string> all_supplies(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> recipeGraph;
        unordered_map<string, int> recipe_to_id;
        
        vector<int> waiting_recipe_cnt(recipes.size(), 0);
        queue<int> recipe_ready;
        vector<string> possible_recipes;

        for (int r_id=0; r_id<recipes.size(); r_id++) {

            string recipe = recipes[r_id];
            for (auto ingredient: ingredients[r_id])
                if (!all_supplies.count(ingredient)) {

                    recipeGraph[ingredient].push_back(recipe);
                    waiting_recipe_cnt[r_id]++;

                }   
            
            if (!waiting_recipe_cnt[r_id]) recipe_ready.push(r_id);
            recipe_to_id[recipe] = r_id;

        }

        while (!recipe_ready.empty()) {

            int r_id = recipe_ready.front();
            recipe_ready.pop();
            string recipe = recipes[r_id];
            possible_recipes.push_back(recipe);

            if (!recipeGraph.count(recipe)) continue;

            for (string waiting_recipe: recipeGraph[recipe]) {

                int waiting_r_id = recipe_to_id[waiting_recipe];
                if (!(--waiting_recipe_cnt[waiting_r_id]))
                    recipe_ready.push(waiting_r_id);

            }

        }

        return possible_recipes;

    }
};
