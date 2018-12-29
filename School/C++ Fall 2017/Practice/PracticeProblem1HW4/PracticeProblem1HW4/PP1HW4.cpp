/*
Find the INDEX of the first and last negative element in
the given array of integers and place them into the locations
to which the first and last pointer point. If no elements
are negative, store -1 in both of the locations.
*/
void flneg(int a[], int size, int* first, int* last)
{
	for (int i = 0; i < size; i++)
	{
		if (a[i] < 0)
		{
			*first = i;
			break;
		}
		else *first = -1;
	}
	for (int j = (size - 1); j >= 0; j--)
	{
		if (a[j] < 0)
		{
			*last = j;
			break;
		}
		else *last = -1;
	}
}
