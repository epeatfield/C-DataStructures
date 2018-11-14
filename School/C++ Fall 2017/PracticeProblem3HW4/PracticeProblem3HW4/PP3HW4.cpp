/**
Add a zero to the beginning and the end of the given array
numbers. You are given the number of elements of the array.
Allocate a new array and place all numbers into it (that is,
the zeroes at the beginning and the end, and all numbers
in between).

Use the C++ style new operator.

Return a pointer to the new array.
*/

int* surround_with_zeroes(int numbers[], int size)
{
	int* arr = new int[size + 2];
	arr[0] = 0;
	arr[size + 1] = 0;
	for (int i = 1; i <= size; i++)
	{
		arr[i] = numbers[i - 1];
	}
	return arr;
}