#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "net.h"

using namespace std;

class Data{
public:
    Data(const string filename);
    bool isEof();
    void getTopology(vector<unsigned> &topology);
    void getEta(double &eta);
    void getMomentum(double &momentum);
    void getTransferFunction(string &transferFunction);

    // Returns the number of input values read from the file:
    unsigned getNextInputs(vector<double> &inputVals);
    unsigned getTargetOutputs(vector<double> &targetOutputVals);

    vector<Connection> readWeights(const int x, const int y);

    void saveNetwork(Net input, string filename, double eta, double momentum);

    void loadData(vector<unsigned> &topology, vector<vector<double>> &inputVals, vector<vector<double>> &targetValues, double &eta, double &momentum, string &transferFunction);

    Net loadnetwork();

private:
    ifstream DataFile;
};
