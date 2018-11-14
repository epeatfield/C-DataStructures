#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void printresult(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits);
void calcnear(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits);
void calcfar(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits);
void printnear(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits);
void printfar(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits);
void printbest(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits);
int calcnearvalues(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits);
int calcfarvalues(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits);


int main()
{
	int plant_count;

	const int UNITS_PER_CAN = 3;
	const string INPUT_FILE_NAME = "counts.txt";

	ifstream input;
	input.open(INPUT_FILE_NAME);
	if (input.fail())
	{
		cout << "Failed to open " << INPUT_FILE_NAME << endl;
		return -1;
	}

	// Loop once for each number of plants read from the input file.
	// Stop when the number of plants is 0 or less.
	// During each loop, simulate Plan Near and Plan Far.
	do
	{
		int count = 0;
		int stepsi = 0;
		int stepsf = 0;
		int water = 3;
		int totalstepunits = 0;

		input >> plant_count;
		if (plant_count <= 0)
		{
			break;
		}
		printresult(plant_count, count, stepsi, stepsf, water, totalstepunits);

	} while (plant_count > 0);
	return 0;
}

void printresult(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits)
{
	printnear(plantamount, counter, isteps, fsteps, wateramount, stepunits);
	printfar(plantamount, counter, isteps, fsteps, wateramount, stepunits);
	printbest(plantamount, counter, isteps, fsteps, wateramount, stepunits);
}

void printnear(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits)
{
	cout << endl;
	cout << "==========================" << endl;
	cout << " Plan Near with " << plantamount << " plants" << endl;
	cout << "==========================" << endl;
	cout << endl;
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;

	calcnear(plantamount, counter, isteps, fsteps, wateramount, stepunits);
}

void calcnear(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits)
{
	while (counter < plantamount)
	{
		if (wateramount == 0)
		{
			fsteps = isteps + counter;
			stepunits = ((fsteps - isteps)*wateramount) + stepunits;
			cout << "FAUCET      " << fsteps << "        " << wateramount << "       " << stepunits << endl;
			wateramount = 3;
		}
		else if (wateramount == 3)
		{
			counter = counter + 1;
			fsteps = isteps + counter;
			stepunits = ((fsteps - isteps)*wateramount) + stepunits;
			cout << "Plant " << counter << "         " << fsteps << "       " << wateramount << "       " << stepunits << endl;
			wateramount = wateramount - 1;
		}
		else
		{
			counter = counter + 1;
			fsteps = isteps + 1;
			stepunits = ((fsteps - isteps)*wateramount) + stepunits;
			cout << "Plant " << counter << "        " << fsteps << "       " << wateramount << "         " << stepunits << endl;
			wateramount = wateramount - 1;
		}
		
		isteps = fsteps;
	}
	
	fsteps = fsteps + plantamount;
	stepunits = ((fsteps - isteps)*wateramount) + stepunits;

	cout << "FAUCET     " << fsteps << "      " << wateramount << "        " << stepunits << endl;
	cout << endl;
	cout << "Plan Near: Total steps = " << fsteps << ", total step-units = " << stepunits << endl;
}

void printfar(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits)
{
	cout << endl;
	cout << "==========================" << endl;
	cout << " Plan Far with " << plantamount << " plants" << endl;
	cout << "==========================" << endl;
	cout << endl;
	cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
	cout << "---------  ----------  ----------  ---------------" << endl;

	calcfar(plantamount, counter, isteps, fsteps, wateramount, stepunits);
}

void calcfar(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits)
{
	int farcounter = plantamount + 1;
	while (farcounter > 1)
	{
		if (wateramount == 0)
		{
			fsteps = isteps + farcounter;
			stepunits = ((fsteps - isteps) * wateramount) + stepunits;
			cout << "FAUCET       " << fsteps << "       " << wateramount << "        " << stepunits << endl;
			wateramount = 3;
		}
		else if (wateramount == 3)
		{
			farcounter = farcounter - 1;
			fsteps = isteps + farcounter;
			stepunits = ((fsteps - isteps) * wateramount) + stepunits;
			cout << "Plant " << farcounter << "      " << fsteps << "       " << wateramount << "        " << stepunits << endl;
			wateramount = wateramount - 1;
		}
		else
		{
			farcounter = farcounter - 1;
			fsteps = isteps + 1;
			stepunits = ((fsteps - isteps) * wateramount) + stepunits;
			cout << "Plant " << farcounter << "        " << fsteps << "       " << wateramount << "        " << stepunits << endl;
			wateramount = wateramount - 1;
		}
		isteps = fsteps;
	}

	fsteps = fsteps + 1;
	stepunits = ((fsteps - isteps) * wateramount) + stepunits;
	cout << "FAUCET       " << fsteps << "       " << wateramount << "         " << stepunits << endl;
	cout << endl;
	cout << "Plan Far: Total steps = " << fsteps << ", total step-units = " << stepunits << endl;
}

void printbest(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits)
{

	int difference = 0;
	int farstepunits = calcfarvalues(plantamount, counter, isteps, fsteps, wateramount, stepunits);
	int nearstepunits = calcnearvalues(plantamount, counter, isteps, fsteps, wateramount, stepunits);

	if (farstepunits > nearstepunits)
	{
		difference = farstepunits - nearstepunits;
		cout << endl;
		cout << "*** With " << plantamount << " plants, Plan Near is better with " << difference << " fewer step-units." << endl;
	}
	else if (farstepunits < nearstepunits)
	{
		difference = nearstepunits - farstepunits;
		cout << endl;
		cout << "*** With " << plantamount << " plants, Plan Far is better with " << difference << " fewer step-units." << endl;
	}
	else
	{
		cout << endl;
		cout << "*** With " << plantamount << " plants, both plans require the same amount of step-units." << endl;
	}
}
int calcnearvalues(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits)
{
	while (counter < plantamount)
	{
		if (wateramount == 0)
		{
			fsteps = isteps + counter;
			stepunits = ((fsteps - isteps)*wateramount) + stepunits;
			wateramount = 3;
		}
		else if (wateramount == 3)
		{
			counter = counter + 1;
			fsteps = isteps + counter;
			stepunits = ((fsteps - isteps)*wateramount) + stepunits;
			wateramount = wateramount - 1;
		}
		else
		{
			counter = counter + 1;
			fsteps = isteps + 1;
			stepunits = ((fsteps - isteps)*wateramount) + stepunits;
			wateramount = wateramount - 1;
		}
		isteps = fsteps;
	}

	fsteps = fsteps + plantamount;
	stepunits = ((fsteps - isteps)*wateramount) + stepunits;
	return(stepunits);
}
int calcfarvalues(int plantamount, int counter, int isteps, int fsteps, int wateramount, int stepunits)
{
	int farcounter = plantamount + 1;
	while (farcounter > 1)
	{
		if (wateramount == 0)
		{
			fsteps = isteps + farcounter;
			stepunits = ((fsteps - isteps) * wateramount) + stepunits;
			wateramount = 3;
		}
		else if (wateramount == 3)
		{
			farcounter = farcounter - 1;
			fsteps = isteps + farcounter;
			stepunits = ((fsteps - isteps) * wateramount) + stepunits;
			wateramount = wateramount - 1;
		}
		else
		{
			farcounter = farcounter - 1;
			fsteps = isteps + 1;
			stepunits = ((fsteps - isteps) * wateramount) + stepunits;
			wateramount = wateramount - 1;
		}
		isteps = fsteps;
	}

	fsteps = fsteps + 1;
	stepunits = ((fsteps - isteps) * wateramount) + stepunits;
	return(stepunits);
}