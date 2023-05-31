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

	vector<TrafficLight> northSouthLights;
	vector<TrafficLight> eastWestLights;
	vector<vector<TrafficLight>> allLights;

	bool init = false; // ovo u neki init prebaci
	bool firstRun = true;

	void setNames()
	{
		northLight.setName("North");
		southLight.setName("South");
		eastLight.setName("East");
		westLight.setName("West");
	}

	void initLights()
	{
		setNames();

		northSouthLights.push_back(northLight);
		northSouthLights.push_back(southLight);
		eastWestLights.push_back(eastLight);
		eastWestLights.push_back(westLight);

		allLights.push_back(northSouthLights);
		allLights.push_back(eastWestLights);

		init = true;
	}

	void synchLights(TrafficLight& light1, TrafficLight& light2)
	{
		LightStates stateToSet = light1.getCurrentState();
		light2.setCurrentState(stateToSet);
	}


public:

	void run()
	{
		if (!init)
			initLights();
		
		//cout << "Started northSouth" << endl;
		//northLight.switchStates(0);
		//synchLights(northLight, southLight);
		//printStates();

		//cout << "Started eastWest" << endl;
		//if (eastLight.getCurrentState() == LightStates::RED && firstRun)
		//{
		//	int delay = eastLight.getLightDuration(LightStates::YELLOWTOGREEN) + eastLight.getLightDuration(LightStates::GREEN);
		//	eastLight.switchStates(delay);

		//	firstRun == false;
		//}
		//else
		//	eastLight.switchStates(0);

		//synchLights(eastLight, westLight);
		//printStates();
	}


	void test()
	{
		if (!init)
			initLights();

		cout << "Started northSouth" << endl;
		northLight.switchStates();
		cout << "Started eastWest" << endl;
		eastLight.switchStates();

	}

	void printStates()
	{
		cout << northLight.printNameWState() << endl;
		cout << southLight.printNameWState() << endl;
		cout << eastLight.printNameWState() << endl;
		cout << westLight.printNameWState() << endl;
	}
};


int main()
{
	TrafficIntersection trafficIntersection;

	while (true)
		trafficIntersection.run();



}