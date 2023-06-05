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

	bool checkState(LightStates controlState)
	{
		return state == controlState;
	}
};


class TrafficIntersection
{
	vector<TrafficLight> northSouthLights;
	vector<TrafficLight> eastWestLights;

	bool init = false; 

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

	void sleep(int seconds)
	{
		Sleep(seconds * 1000);
	}

	bool checkState(vector<TrafficLight>& lights, LightStates state)
	{
		return lights.at(0).checkState(state);
	}

public:

	void run()
	{
		if (!init)
			initLights();

		bool firstRun = true;
		int timer{};
		printStates(northSouthLights, eastWestLights);

		//RUN THIS FOR THE FIRST CYCLE
		do
		{
			timer++;

			if (timer < invalidDuration)
			{
				//LIGHTS DEFAULT
			}
			else if (timer < invalidDuration + redDuration)
			{
				//RED
				if (!checkState(northSouthLights, LightStates::RED))
				{
					synchLights(northSouthLights);
					synchLights(eastWestLights);
				}
			}
			else if (timer < invalidDuration + redDuration + yellowDuration)
			{
				//YELLOW
				if (!checkState(northSouthLights, LightStates::YELLOWTOGREEN))
					synchLights(northSouthLights);
			}
			else if (timer < invalidDuration + redDuration + yellowDuration + greenDuration)
			{
				//GREEN
				if (!checkState(northSouthLights, LightStates::GREEN))
					synchLights(northSouthLights);
			}
			else if (timer < invalidDuration + redDuration + (2 * yellowDuration) + greenDuration)
			{
				//YELLOW
				if (!checkState(northSouthLights, LightStates::YELLOWTORED))
				{
					synchLights(northSouthLights);
					synchLights(eastWestLights);
				}
			}
			else
			{
				firstRun = false;
				timer = 0;
				continue;
			}

			sleep(1);
			printStates(northSouthLights, eastWestLights);

		} while (firstRun);

		//RUN THIS FOR EVERY FOLLOWING CYCLE
		while (true)
		{
			timer++;

			if (timer <= redDuration)
			{
				if (!checkState(northSouthLights, LightStates::RED))
				{
					//RED
					synchLights(northSouthLights);
					//GREEN
					synchLights(eastWestLights);
				}
			}
			else if (timer <= redDuration + yellowDuration)
			{
				//YELLOW
				if (!checkState(northSouthLights, LightStates::YELLOWTOGREEN))
				{
					synchLights(northSouthLights);
					synchLights(eastWestLights);
				}
			}
			else if (timer <= redDuration + yellowDuration + greenDuration)
			{
				if (!checkState(northSouthLights, LightStates::GREEN))
				{
					//GREEN
					synchLights(northSouthLights);
					//RED
					synchLights(eastWestLights);
				}
			}
			else if (timer <= redDuration + (2 * yellowDuration) + greenDuration)
			{
				//YELLOW
				if (!checkState(northSouthLights, LightStates::YELLOWTORED))
				{
					synchLights(northSouthLights);
					synchLights(eastWestLights);
				}
			}
			else
			{
				timer = 0;
				continue;
			}
			
			sleep(1);
			printStates(northSouthLights, eastWestLights);
		}
	}
};


int main()
{
	TrafficIntersection trafficIntersection;
	
	trafficIntersection.run();

}