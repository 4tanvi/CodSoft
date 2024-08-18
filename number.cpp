#include <iostream>
using namespace std;

int main()
{
    int n;
    int x = 75;
    int count = 0;
    
    cout << "Guess a number between 1 and 100: ";
    
    for (int i = 1; i <= 100; i++)
    {
        cin >> n;
        count = i;
        
        if (n < x)
        {
            cout << "Guess a Greater Number.";
        }
        else if (n > x)
        {
            cout << "Guess a Smaller Number.";
        }
        else
        {
            cout << "YOOOHOOO!! You are correct.";
        }
        
        if (n == x)
            break;
    }
}