#include "PaintEstimator.h"

CPaintEstimator::CPaintEstimator(float fWidth, float fLength, float fHeight, float fCoverage)
{
    mfWidth = fWidth;
    mfLength = fLength;
    mfHeight = fHeight;
    mfCoverage = fCoverage;
}
CPaintEstimator::~CPaintEstimator(void)
{
}

// function to calculate the wall area of a room, 
// No inputs - uses member variables
// output float fArea - units are not defined
float CPaintEstimator::CalculateWallArea(void)
{
    float fArea = ((mfWidth * mfHeight)*2.0f) + ((mfLength * mfHeight)*2.0f) ;
    return fArea;
}
// function to calculate the floor area of a room, 
// No inputs - uses member variables
// output float fArea - units are not defined
float CPaintEstimator::CalculateFloorArea(void)
{
    float fArea = (mfWidth * mfLength);
    return fArea;
}
// function to calculate the volume of a room, 
// No inputs - uses member variables
// output float fVolume - units are not defined
float CPaintEstimator::CalculateVolume(void)
{
    float fVolume = (mfWidth * mfHeight* mfLength);
    return fVolume;
}
// function to calculate the volume of paint (in litres)
// required to paint the area of wall
float CPaintEstimator::CalculatePaintReq(float fVolume)
{
    float fPaintVolume = (fVolume/mfCoverage);
    return fPaintVolume;
}
// Function to validate input arguments - initially all values > 0 and < FLT_MAX
// No inputs as uses member variables
// Output boolean - true if all dimensions valid
//                  false if any dimension <=0 or >= FLT_MAX
bool CPaintEstimator::ValidateMeasurements()
{
    bool bOK = false;
    if(mfWidth <=0 || mfLength <=0 || mfHeight <=0|| mfCoverage <=0)
    {
        cout << "ERROR: All values should be > 0" <<endl;
    }
    else if(mfWidth >= FLT_MAX || mfLength >= FLT_MAX || mfHeight >= FLT_MAX|| mfCoverage >= FLT_MAX)
    {
        cout << "ERROR: All values should be < FLT_MAX" <<endl;
    }
    else
    {
        bOK = true;
    }
    return bOK;
}

