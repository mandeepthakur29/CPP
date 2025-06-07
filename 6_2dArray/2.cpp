#include <iostream>

int largestRowSum(int arr[][4], int row, int col)
{
    int max = INT_MIN;
    for(int i=0; i<row; i++)
    {
        int sum = 0;
        for(int j=0; j<col; j++)
        {
            sum += arr[i][j];
        }
        if(sum > max)
        {
            max = i;
        }
    }
    return max;
}

int largestColSum(int arr[][4], int row, int col) //wrong h abhi, theek krna h
{
    int max = INT_MIN;
    for(int i=0; i<col; i++)
    {
        int sum = 0;
        for(int j=0; j<row; j++)
        {
            sum += arr[j][i];
            if(sum > max)
            {
                max = j;
            }
        }
    }
    return max;
}

int main()
{
    int arr[3][4];

    for(int row=0; row<3; row++)
    {
        for(int col=0; col<4; col++)
        {
            std::cin>>arr[row][col];
        }
    }

    //printing the array
    for(int row=0; row<3; row++)
    {
        for(int col=0; col<4; col++)
        {
            std::cout<<arr[row][col]<<" ";
        }
        std::cout<<std::endl;
    }

    //larget row sum
    int row = largestRowSum(arr, 3, 4);
    std::cout<<"Largest row is: "<<row<<std::endl;

    int col = largestColSum(arr, 3, 4);
    std::cout<<"Largest col is: "<<col<<std::endl;

    return 0;
}