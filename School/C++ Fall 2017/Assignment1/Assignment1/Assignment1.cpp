#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

/*** Complete this program. ***/

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
		int plant_counter = 0;
		int stepsi = 0;
		int stepsf = 0;
		int water = 4;
		int cum_stepunits = 0;
		int farstepsf = 0;
		int farstepsi = 0;
		int farwater = 4;
		int farcum_stepunits = 0;
		int difference = 0;
		int leastwork = 0;

		input >> plant_count;
		if (plant_count <= 0)
		{
			break;
		}

		// Plan Near

		cout << endl;
		cout << "==========================" << endl;
		cout << " Plan Near with " << plant_count << " plants" << endl;
		cout << "==========================" << endl;
		cout << endl;
		cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
		cout << "---------  ----------  ----------  ---------------" << endl;

		while (plant_counter < plant_count)
		{
			water = water - 1;
			if (water == 0)
			{
				stepsf = stepsi + plant_counter;
				cum_stepunits = ((stepsf - stepsi)*water) + cum_stepunits;
				cout << "FAUCET      " << stepsf << "        " << water << "       " << cum_stepunits << endl;
				water = 4;
			}
			else if (water == 3)
			{
				plant_counter = plant_counter + 1;
				stepsf = stepsi + plant_counter;
				cum_stepunits = ((stepsf - stepsi)*water) + cum_stepunits;
				cout << "Plant " << plant_counter << "         " << stepsf << "       " << water << "       " << cum_stepunits << endl;
			}
			else
			{
				plant_counter = plant_counter + 1;
				stepsf = stepsi + 1;
				cum_stepunits = ((stepsf - stepsi)*water) + cum_stepunits;
				cout << "Plant " << plant_counter << "        " << stepsf << "       " << water << "         " << cum_stepunits << endl;
			}
			stepsi = stepsf;
		}

		stepsf = stepsf + plant_count;
		water = water - 1;
		cum_stepunits = ((stepsf - stepsi)*water) + cum_stepunits;
		cout << "FAUCET     " << stepsf << "      " << water << "        " << cum_stepunits << endl;
		cout << endl;
		cout << "Plan Near: Total steps = " << stepsf << ", total step-units = " << cum_stepunits << endl;

		// Plan Far

		cout << endl;
		cout << "=========================" << endl;
		cout << " Plan Far with " << plant_count << " plants" << endl;
		cout << "=========================" << endl;
		cout << endl;
		cout << "Where      Cum. steps  Water amt.  Cum. step-units" << endl;
		cout << "---------  ----------  ----------  ---------------" << endl;

		int farplant_counter = plant_count + 1;
		while (farplant_counter > 1)
		{
			farwater = farwater - 1;
			if (farwater == 0)
			{
				farstepsf = farstepsi + farplant_counter;
				farcum_stepunits = ((farstepsf - farstepsi) * farwater) + farcum_stepunits;
				cout << "FAUCET       " << farstepsf << "       " << farwater << "        " << farcum_stepunits << endl;
				farwater = 4;
			}
			else if (farwater == 3)
			{
				farplant_counter = farplant_counter - 1;
				farstepsf = farstepsi + farplant_counter;
				farcum_stepunits = ((farstepsf - farstepsi) * farwater) + farcum_stepunits;
				cout << "Plant " << farplant_counter << "      " << farstepsf << "       " << farwater << "        " << farcum_stepunits << endl;
			}
			else
			{
				farplant_counter = farplant_counter - 1;
				farstepsf = farstepsi + 1;
				farcum_stepunits = ((farstepsf - farstepsi) * farwater) + farcum_stepunits;
				cout << "Plant " << farplant_counter << "        " << farstepsf << "       " << farwater << "        " << farcum_stepunits << endl;
			}
			farstepsi = farstepsf;
		}

		farstepsf = farstepsf + 1;
		farwater = farwater - 1;
		farcum_stepunits = ((farstepsf - farstepsi) * farwater) + farcum_stepunits;
		cout << "FAUCET       " << farstepsf << "       " << farwater << "         " << farcum_stepunits << endl;
		cout << endl;
		cout << "Plan Far: Total steps = " << farstepsf << ", total step-units = " << farcum_stepunits << endl;

		// Which plan is better? Better means fewer step-units.
		cout << endl;

		if (farcum_stepunits > cum_stepunits)
		{
			leastwork = cum_stepunits;
			difference = farcum_stepunits - cum_stepunits;
			cout << "*** With " << plant_count << " plants, Plan Near is better with " << difference << " fewer step-units." << endl;
		}
		else if (farcum_stepunits < cum_stepunits)
		{
			leastwork = farcum_stepunits;
			difference = cum_stepunits - farcum_stepunits;
			cout << "*** With " << plant_count << " plants, Plan Far is better with " << difference << " fewer step-units." << endl;
		}
		else
		{
			cout << "*** With " << plant_count << " plants, both plans require the same amount of step-units." << endl;
		}

	} while (plant_count > 0);

	return 0;
}