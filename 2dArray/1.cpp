#include <iostream>

bool isPresent(int arr[][4], int target, int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

void rowSum(int arr[][4], int row, int col)
{
    for(int i=0; i<row; i++)
    {
        int sum = 0;
        for(int j=0; j<col; j++)
        {
            sum += arr[i][j];
        }
        std::cout<<"Row sum is: "<<sum<<std::endl;
    }
}

void colSum(int arr[][4], int row, int col)
{
    for(int i=0; i<col; i++)
    {
        int sum = 0;
        for(int j=0; j<row; j++)
        {
            sum += arr[j][i];
        }
        std::cout<<"Col sum is: "<<sum<<std::endl;
    }
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

    //target present or not
    if(isPresent(arr, 12, 3, 4))
    {
        std::cout<<"Present"<<std::endl;
    }
    else
        std::cout<<"Not Present"<<std::endl;


    //row-wise sum
    rowSum(arr, 3, 4);
    colSum(arr, 3, 4);

    return 0;
}