#include <iostream>
#include <map>
#include <string>

using namespace std;

class StatePopulation {
private:
    map<string, int> stateMap;

public:
    StatePopulation() {
        stateMap["Maharashtra"] = 39538223;
        stateMap["Madhyapradesh"] = 29145505;
        stateMap["Kerala"] = 21538187;
        stateMap["New Delhi"] = 20201249;
        stateMap["Gujrat"] = 13002700;
    }

    int getPopulation(const string& state) const {
        auto it = stateMap.find(state);
        if (it != stateMap.end()) {
            return it->second;
        } else {
            return -1;
        }
    }

};

int main() {
    StatePopulation statePop;

    string stateName;
    cout << "Enter the name of a state: ";
    getline(cin, stateName);

    int population = statePop.getPopulation(stateName);
    if (population != -1) {
        cout << "The population of " << stateName << " is " << population << "." << endl;
    } else {
        cout << "State not found in the database." << endl;
    }

    return 0;
}
