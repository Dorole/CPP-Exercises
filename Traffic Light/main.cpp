#include<iostream>
#include<vector>
#include<Windows.h>
#include<ctime>

using namespace std;

enum class LightStates
{
	RED, YELLOWTOGREEN, GREEN, YELLOWTORED, INVALID
};

class TrafficLight
{
	LightStates state = LightStates::INVALID;
	string name = "placeholder";
	
	//duration in seconds
	int invalidDuration = 10;
	int redDuration = 5;
	int yellowDuration = 3;
	int greenDuration = 5;

public:

	LightStates getCurrentState()
	{
		return state;
	}

	void setCurrentState(LightStates newState)
	{
		state = newState;
	}

	void setName(string newName)
	{
		name = newName;
	}

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

	int getLightDuration(LightStates state)
	{
		int duration = 0;

		switch (state)
		{
		case LightStates::RED:
			duration = redDuration;
			break;
		case LightStates::YELLOWTOGREEN:
			duration = yellowDuration;
			break;
		case LightStates::YELLOWTORED:
			duration = yellowDuration;
			break;
		case LightStates::GREEN:
			duration = greenDuration;
			break;
		case LightStates::INVALID:
			duration = invalidDuration;
			break;
		default:
			break;
		};

		return duration;
	}

	void switchStatesWSleep(int delay)
	{
		switch (state)
		{
		case LightStates::INVALID:
			Sleep(invalidDuration * 1000);
			state = LightStates::RED;
			break;
		case LightStates::RED:
			Sleep((redDuration * 1000) + (delay * 1000));
			state = LightStates::YELLOWTOGREEN;
			break;
		case LightStates::YELLOWTOGREEN:
			Sleep(yellowDuration * 1000);
			state = LightStates::GREEN;
			break;
		case LightStates::GREEN:
			Sleep(greenDuration * 1000);
			state = LightStates::YELLOWTORED;
			break;
		case LightStates::YELLOWTORED:
			Sleep(yellowDuration * 1000);
			state = LightStates::RED;
			break;
		default:
			break;
		}
	}

	void getNextState()
	{

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
	TrafficLight northLight, southLight, eastLight, westLight;

	//TEST
	vector<TrafficLight> northSouthLights;
	vector<TrafficLight> eastWestLights;

	bool init = false; 
	bool firstRun = true;

	//duration in seconds
	int invalidDuration = 10;
	int redDuration = 5;
	int yellowDuration = 3;
	int greenDuration = 5;

	void setNames()
	{
		northLight.setName("North");
		southLight.setName("South");
		eastLight.setName("East");
		westLight.setName("West");
	}

	//TEST
	void initLights()
	{
		setNames();

		northSouthLights.push_back(northLight);
		northSouthLights.push_back(southLight);
		eastWestLights.push_back(eastLight);
		eastWestLights.push_back(westLight);

		init = true;
	}

	void synchLights(TrafficLight& light1, TrafficLight& light2)
	{
		LightStates stateToSet = light1.getCurrentState();
		light2.setCurrentState(stateToSet);
	}

	void vectorSwitch(vector<TrafficLight>& lights)
	{
		for (int i = 0; i < lights.size(); i++)
		{
			lights.at(i).switchStates();
		}
	}

public:

	//individual lights
	void printStates()
	{
		cout << northLight.printNameWState() << endl;
		cout << southLight.printNameWState() << endl;
		cout << eastLight.printNameWState() << endl;
		cout << westLight.printNameWState() << endl;
	}

	//lights in a vector
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

		//for (int i = 0; i < v1.size(); i++)
		//{
		//	cout << v1.at(i).printNameWState() << endl;
		//}
		//
		//for (int i = 0; i < v2.size(); i++)
		//{
		//	cout << v2.at(i).printNameWState() << endl;
		//}

		cout << "=================" << endl;

	}

	//individual lights
	void run()
	{
		if (!init)
			setNames();
		
		while (true)
		{
			printStates();

			if (firstRun)
				Sleep(invalidDuration * 1000);
			else
				Sleep(yellowDuration * 1000);

			northLight.switchStates();
			synchLights(northLight, southLight);
			eastLight.switchStates();
			synchLights(eastLight, westLight);

			printStates();
			Sleep(redDuration * 1000);

			northLight.switchStates();
			synchLights(northLight, southLight);
			if (!firstRun)
			{
				eastLight.switchStates();
				synchLights(eastLight, westLight);
			}

			printStates();
			Sleep(yellowDuration * 1000);

			northLight.switchStates();
			synchLights(northLight, southLight);
			if (!firstRun)
			{
				eastLight.switchStates();
				synchLights(eastLight, westLight);
			}

			printStates();
			Sleep(greenDuration * 1000);

			northLight.switchStates();
			synchLights(northLight, southLight);
			eastLight.switchStates();
			synchLights(eastLight, westLight);

			if (firstRun)
				firstRun = false;
		}

	}

	//lights in a vector
	void testRun()
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

			vectorSwitch(northSouthLights);
			vectorSwitch(eastWestLights);

			printStates(northSouthLights, eastWestLights);
			Sleep(redDuration * 1000);

			vectorSwitch(northSouthLights);
			if (!firstRun)
			{
				vectorSwitch(eastWestLights);
			}

			printStates(northSouthLights, eastWestLights);
			Sleep(yellowDuration * 1000);

			vectorSwitch(northSouthLights);
			if (!firstRun)
			{
				vectorSwitch(eastWestLights);
			}

			printStates(northSouthLights, eastWestLights);
			Sleep(greenDuration * 1000);

			vectorSwitch(northSouthLights);
			vectorSwitch(eastWestLights);

			if (firstRun)
				firstRun = false;
		}
	}

	
};


int main()
{
	TrafficIntersection trafficIntersection;

	trafficIntersection.testRun();



}