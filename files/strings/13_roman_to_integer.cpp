#include <iostream>
#include <string>

using namespace std;

class solution
{
    public:
    int romanToInt(string rom)
    {
        int arr[128];

        // Mapping roman characters.
        arr['I'] = 1;
        arr['V'] = 5;
        arr['X'] = 10;
        arr['L'] = 50;
        arr['C'] = 100;
        arr['D'] = 500;
        arr['M'] = 1000;

        // Iterate over string
        // I can be placed before V (5) and X (10) to make 4 and 9.
        // X can be placed before L (50) and C (100) to make 40 and 90.
        // C can be placed before D (500) and M (1000) to make 400 and 900.

        // When encountered I, check for ONE V or X
        // X : check for L and C
        // C : check for D and M
        int total_val = 0;

        for (size_t i = 0; i < rom.length(); i++)
        {
            if (rom[i] == 'I' && i + 1 < rom.length() && (rom[i + 1] == 'V' || rom[i + 1] == 'X'))
            {
                total_val = total_val + arr[rom[i + 1]] - arr['I'];
                i++;
                continue;
            }

            else if (rom[i] == 'X' && i + 1 < rom.length() && (rom[i + 1] == 'L' || rom[i + 1] == 'C'))
            {
                total_val = total_val + arr[rom[i + 1]] - arr['X'];
                i++;
                continue;
            }

            else if (rom[i] == 'C' && i + 1 < rom.length() && (rom[i + 1] == 'D' || rom[i + 1] == 'M'))
            {
                total_val = total_val + arr[rom[i + 1]] - arr['C'];
                i++;
                continue;
            }

            else{
                total_val = total_val + arr[rom[i]];
            }
        }

        return total_val;
    }
};

int main(){
    solution s;
    cout<<s.romanToInt("MCMXCIV")<<endl;
    return 0;
}
