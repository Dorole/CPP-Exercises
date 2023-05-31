#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;

enum class LightStates
{
	RED, YELLOWTOGREEN, GREEN, YELLOWTORED, INVALID
};

class TrafficLight
{
	LightStates state = LightStates::INVALID;
	string name = "placeholder";
	
	string stringCurrentState()
	{
		string currentState;

		switch (state)
		{
		case LightStates::RED:
			currentState = "RED";
			break;
		case LightStates::YELLOWTOGREEN:
			currentState = "YELLOW";
			break;
		case LightStates::YELLOWTORED:
			currentState = "YELLOW";
			break;
		case LightStates::GREEN:
			currentState = "GREEN";
			break;
		case LightStates::INVALID:
			currentState = "INVALID";
			break;
		default:
			currentState = "ERROR";
			break;
		};

		return currentState;
	}

public:

	void setName(string newName)
	{
		name = newName;
	}

	void switchStates()
	{
		switch (state)
		{
		case LightStates::INVALID:
			state = LightStates::RED;
			break;
		case LightStates::RED:
			state = LightStates::YELLOWTOGREEN;
			break;
		case LightStates::YELLOWTOGREEN:
			state = LightStates::GREEN;
			break;
		case LightStates::GREEN:
			state = LightStates::YELLOWTORED;
			break;
		case LightStates::YELLOWTORED:
			state = LightStates::RED;
			break;
		default:
			break;
		}
	}

	string printNameWState()
	{
		return name + ": " + stringCurrentState();
	}
};


class TrafficIntersection
{
	vector<TrafficLight> northSouthLights;
	vector<TrafficLight> eastWestLights;

	bool init = false; 
	bool firstRun = true;

	//duration in seconds
	const int invalidDuration = 10;
	const int redDuration = 5;
	const int yellowDuration = 3;
	const int greenDuration = redDuration;

	void initLights()
	{	
		TrafficLight northLight, southLight, eastLight, westLight;

		//setNames();
		
		northSouthLights.push_back(northLight);
		northSouthLights.push_back(southLight);
		eastWestLights.push_back(eastLight);
		eastWestLights.push_back(westLight);

		northSouthLights.at(0).setName("North");
		northSouthLights.at(1).setName("South");
		eastWestLights.at(0).setName("East");
		eastWestLights.at(1).setName("West");

		init = true;
	}

	void synchLights(vector<TrafficLight>& lights)
	{
		for (int i = 0; i < lights.size(); i++)
		{
			lights.at(i).switchStates();
		}
	}

	void printStates(vector<TrafficLight>& v1, vector<TrafficLight>& v2)
	{
		vector<vector<TrafficLight>> allLights {v1, v2};

		for (int i = 0; i < allLights.size(); i++)
		{
			for (int j = 0; j < allLights[i].size(); j++)
			{
				cout << allLights[i][j].printNameWState() << endl;
			}
		}

		cout << "=================" << endl;

	}


public:

	void run()
	{
		if (!init)
			initLights();

		while (true)
		{
			printStates(northSouthLights, eastWestLights);

			if (firstRun)
				Sleep(invalidDuration * 1000);
			else
				Sleep(yellowDuration * 1000);

			synchLights(northSouthLights);
			synchLights(eastWestLights);

			printStates(northSouthLights, eastWestLights);
			Sleep(redDuration * 1000);

			synchLights(northSouthLights);
			if (!firstRun)
				synchLights(eastWestLights);
			
			printStates(northSouthLights, eastWestLights);
			Sleep(yellowDuration * 1000);

			synchLights(northSouthLights);
			if (!firstRun)
				synchLights(eastWestLights);
			
			printStates(northSouthLights, eastWestLights);
			Sleep(greenDuration * 1000);

			synchLights(northSouthLights);
			synchLights(eastWestLights);

			if (firstRun)
				firstRun = false;
		}
	}
	
};


int main()
{
	TrafficIntersection trafficIntersection;

	trafficIntersection.run();

}