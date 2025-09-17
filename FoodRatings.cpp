#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, set<string, function<bool(const string&, const string&)>>> cuisineFoods;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
        }

        for (int i = 0; i < foods.size(); i++) {
            string cuisine = cuisines[i];
            if (!cuisineFoods.count(cuisine)) {
                cuisineFoods[cuisine] = set<string, function<bool(const string&, const string&)>>(
                    [&](const string& a, const string& b) {
                        int r1 = foodToRating[a];
                        int r2 = foodToRating[b];
                        if (r1 != r2) return r1 > r2;
                        return a < b;
                    }
                );
            }
            cuisineFoods[cuisine].insert(foods[i]);
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        auto& s = cuisineFoods[cuisine];

        s.erase(food);
        foodToRating[food] = newRating;
        s.insert(food);
    }

    string highestRated(string cuisine) {
        return *cuisineFoods[cuisine].begin();
    }
};

int main() {
    vector<string> foods = {"sushi", "burger", "taco", "ramen", "burrito"};
    vector<string> cuisines = {"japanese", "american", "mexican", "japanese", "mexican"};
    vector<int> ratings = {5, 3, 4, 4, 5};

    FoodRatings fr(foods, cuisines, ratings);

    cout << "Highest rated Japanese food: " << fr.highestRated("japanese") << endl; // sushi
    cout << "Highest rated Mexican food: " << fr.highestRated("mexican") << endl;   // burrito

    fr.changeRating("ramen", 6); // ramen now has highest rating in Japanese cuisine

    cout << "After rating change..." << endl;
    cout << "Highest rated Japanese food: " << fr.highestRated("japanese") << endl; // ramen

    return 0;
}
