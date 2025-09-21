#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    // food -> {cuisine, rating}
    unordered_map<string, pair<string, int>> foodInfo;

    // cuisine -> ordered set of foods (sorted by -rating, name)
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

public:
    // Constructor
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineFoods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    // Change rating of a food
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];

        // Remove old entry
        cuisineFoods[cuisine].erase({-oldRating, food});

        // Insert new rating
        cuisineFoods[cuisine].insert({-newRating, food});

        // Update stored info
        foodInfo[food] = {cuisine, newRating};
    }

    // Get highest-rated food in a cuisine
    string highestRated(string cuisine) {
        return cuisineFoods[cuisine].begin()->second;
    }
};

// ------------------- Example Run -------------------
int main() {
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};

    FoodRatings obj(foods, cuisines, ratings);

    cout << obj.highestRated("korean") << endl;   // kimchi
    cout << obj.highestRated("japanese") << endl; // ramen

    obj.changeRating("sushi", 16);
    cout << obj.highestRated("japanese") << endl; // sushi

    obj.changeRating("ramen", 16);
    cout << obj.highestRated("japanese") << endl; // ramen (tie → lexicographically smaller)

    return 0;
}
