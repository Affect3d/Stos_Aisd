#include <iostream>
#include <sstream>

using namespace std;

int gcd ( int x , int y )
{
    if ( y == 0 )
        return x;
    else if ( x >= y && y > 0)
        return gcd ( y , x % y );
    else return gcd ( y , x );        // if x < y then go ahead and switch them around.
}

string convertHex(int num, string ss)
{

    int x = num % 16;
    char x_char = x+'0';

    if (num ==0)
    {
        return ss;
    }

    switch (x)
    {
        case 10: ss = "A"+ ss; break;
        case 11: ss = "B"+ ss; break;
        case 12: ss = "C"+ ss; break;
        case 13: ss = "D"+ ss; break;
        case 14: ss = "E"+ ss; break;
        case 15: ss = "F"+ ss; break;
        default: ss = x_char + ss; break;
    }

    return convertHex(num / 16, ss);

}

bool recursiveisPrime(int n, int d)
{
    if(n<2)
        return 0;
    if(d == 1)
        return true;
    else
    {
        if(n!=d && n % d == 0)
            return false;
        else
            return recursiveisPrime(n, d - 1);
    }
}

bool is_prime(int n) {
    return recursiveisPrime(n, n);
}

int main()
{
    //cout<< gcd(256, 280) << endl;
    string buffer="";
    cout << convertHex(177777, buffer)<<endl;
    cout << is_prime(3)<<endl;
    return 0;
}
