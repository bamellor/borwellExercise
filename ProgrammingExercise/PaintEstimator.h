#include <iostream>
using namespace std;

class CPaintEstimator
{
public:
    CPaintEstimator(float fWidth, float fLength, float fHeight, float fCoverage);
    ~CPaintEstimator();
    bool ValidateMeasurements();
    float CalculateFloorArea(void);
    float CalculateWallArea(void);
    float CalculateVolume(void);
    float CalculatePaintReq(float fVolume);

private:
    float mfWidth;
    float mfLength;
    float mfHeight;
    float mfCoverage;
};