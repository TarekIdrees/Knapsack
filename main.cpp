#include <iostream>
using namespace std;
int max(int x, int y)
{
    return (x > y) ? x : y;
}
int knapSack(int capacity, int weight[], int value[], int number_of_item)
{
    int Matrix[number_of_item + 1][capacity + 1];
    for (int i = 0; i <= number_of_item; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                Matrix[i][j] = 0;
            else if (weight[i - 1] <= j)
                Matrix[i][j] = max(value[i - 1] + Matrix[i - 1][j - weight[i - 1]], Matrix[i - 1][j]);
            else
                Matrix[i][j] = Matrix[i - 1][j];
        }
    }
    return Matrix[number_of_item][capacity];
}
int main()
{
    cout << "Enter the number of items in a Knapsack: \n";
    int Number_of_item;
    cin >> Number_of_item;
    int value[Number_of_item], weight[Number_of_item];
    for (int i = 0; i < Number_of_item; i++)
    {
        cout << "Enter value and weight for item " << i << ": \n";
        cin >> value[i];
        cin >> weight[i];
    }
    cout << "Enter the capacity of knapsack \n";
    int capacity;
    cin >> capacity;
    cout << "Max Profit Equal : \n";
    cout<<knapSack(capacity, weight, value, Number_of_item);
    return 0;
}
