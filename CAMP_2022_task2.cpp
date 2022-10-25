#include <iostream>
#include <vector>

bool ChangeStateOfCell(const bool& cell, const int& count)
{
	if (!cell && count == 3)
		return true;

	if (cell)
		switch (count)
		{
		case 2:
			return true;
		case 3:
			return true;
		default:
			return false;
			break;
		}
}

int FindNeighbours(const std::vector<std::vector<bool>>& matrix, const int& i, const int& j)
{
	int count = 0;

	if (matrix[i - 1][j - 1])
		++count;
	if (matrix[i - 1][j])
		++count;
	if (matrix[i - 1][j + 1])
		++count;
	if (matrix[i][j - 1])
		++count;
	if (matrix[i][j + 1])
		++count;
	if (matrix[i + 1][j - 1])
		++count;
	if (matrix[i + 1][j])
		++count;
	if (matrix[i + 1][j + 1])
		++count;

	return count;
}

void PrintMatrix(const std::vector<std::vector<bool>>& matrix)
{
	for (const auto& vector : matrix)
	{
		for (const auto& el : vector)
			std::cout << el << ' ';
		std::cout << std::endl;
	}
}

int main()
{
	// Initialization of the initial matrix //
	std::vector<std::vector<bool>> initial_matrix(7, std::vector<bool>(7));
	initial_matrix = {
		{1,0,0,0,0,0,0},
		{0,0,1,0,0,1,1},
		{1,0,0,1,0,0,1},
		{0,1,1,0,1,1,0},
		{1,1,1,1,0,0,1},
		{1,1,1,1,1,1,1},
		{1,1,0,1,1,0,1}
	};

	// Creating a copy of the matrix //
	std::vector<std::vector<bool>> modified_matrix(initial_matrix);

	std::cout << "Initial matrix:\n";
	PrintMatrix(initial_matrix);

	// Matrix modification //
	for (int k = 0; k < 7; ++k)
	{
		for (int i = 1; i < initial_matrix.size() - 1; ++i)
		{
			int count = 0;
			for (int j = 1; j < initial_matrix.size() - 1; ++j)
			{
				// Counting cell neighbors //
				count = FindNeighbours(initial_matrix, i, j);
				// A change in the state of the cell
				modified_matrix[i][j] = ChangeStateOfCell(initial_matrix[i][j], count);
			}
		}
		initial_matrix = modified_matrix;
	}

	std::cout << "\nModified matrix:\n";
	PrintMatrix(modified_matrix);

	return 0;
}