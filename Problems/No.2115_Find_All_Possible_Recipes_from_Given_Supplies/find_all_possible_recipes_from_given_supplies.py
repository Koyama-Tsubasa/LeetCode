class Solution(object):
    def findAllRecipes(self, recipes, ingredients, supplies):
        """
        :type recipes: List[str]
        :type ingredients: List[List[str]]
        :type supplies: List[str]
        :rtype: List[str]
        """
        
        all_supplies = set(supplies)
        recipeGraph = defaultdict(list)
        waiting_recipe_cnt = [0]*len(recipes)
        recipe_ready = []
        possible_recipes = []

        for r_id, recipe in enumerate(recipes):
            for ingredient in ingredients[r_id]:
                if ingredient not in all_supplies:
                    recipeGraph[ingredient].append([r_id, recipe])
                    waiting_recipe_cnt[r_id] += 1
            if waiting_recipe_cnt[r_id] == 0:
                recipe_ready.append([r_id, recipe])

        while recipe_ready:
            r_id, recipe = recipe_ready.pop(0)
            possible_recipes.append(recipe)

            if recipe not in recipeGraph:
                continue
            
            for waiting_r_id, waiting_recipe in recipeGraph[recipe]:
                waiting_recipe_cnt[waiting_r_id] -= 1
                if not waiting_recipe_cnt[waiting_r_id]:
                    recipe_ready.append([waiting_r_id, waiting_recipe])

        return possible_recipes
