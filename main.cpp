#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double map_point(double value)
{
    return ((value * 3) - 7)/4;
}

double compute_mean(double total, int count)
{
    if (count == 0)
    {
        return 0;
    }
    return total / count;
}

int main()
{
    string nameFile = "data.csv";
    fstream fstr(nameFile);
    if(fstr.fail())
    {
        cerr << "FILE NOT FOUND" << endl;
        return 1;
    }

    ofstream outfile("result.csv");

    double total = 0;
    int count = 0;
    double value;

    while (fstr >> value)
    {

        double mapped_value = map_point(value);
        total += mapped_value;
        count++;
        double mean = compute_mean(total, count);

        outfile << count << " " << mean << "\n";
    }

    fstr.close();
    outfile.close();

    return 0;
}
