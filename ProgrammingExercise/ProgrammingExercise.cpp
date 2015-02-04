// ProgrammingExercise.cpp
// Taking three room dimensions and paint coverage as input, calculate the volume and floor area of a room and calculate
// the amount of paint required.  Note that the input can be in any unit of measurement, but should be consistent.  
// The amount of paint required will be in litres.
//

#include <iostream>
#include <cfloat>
#include "PaintEstimator.h"

using namespace std;
void Usage();
bool GetArgs(int argc, char *argv[]);
float fWidth;
float fLength;
float fHeight;
float fCoverage;

int main(int argc, char* argv[])
{
    if (false == GetArgs(argc, argv))
    {
        Usage();
        exit(-1);
    }   

    CPaintEstimator workerClass(fWidth,fLength,fHeight,fCoverage);

    if (false == workerClass.ValidateMeasurements())
    {
        exit(-1);
    }   
    float fWallArea = workerClass.CalculateWallArea(); 
    float fFloorArea = workerClass.CalculateFloorArea(); 
    float fRoomVolume = workerClass.CalculateVolume(); 
    float fPaintRequired = workerClass.CalculatePaintReq(fWallArea);
    cout << "Wall Area: " << fWallArea << " units squared" <<endl;
    cout << "Floor Area: " << fFloorArea << " units squared"  << endl;
    cout << "Room Volume: " << fRoomVolume << " units cubed"  << endl;
    cout << "Paint Required: " << fPaintRequired << " litres"  << endl;

	return 0;
}
// Display usage instructions
void Usage()
{
    cerr << "\nProgramming Exercise\n\n";
    cerr << "Usage: " << " -w <float> \"room width\"\n";
    cerr << "Usage: " << " -l <float> \"room length\"\n";
    cerr << "Usage: " << " -h <float> \"room height\"\n";
    cerr << "Usage: " << " -c <float> \"paint coverage (units squared per litre)\"\n";
    cerr << "Usage: " << " Note that units are free, but should be consistent for all fields\n";
}
// Extract command line arguments, which will contain the room dimensions
// Input size of arg list and array of args
// output - boolean true if sufficient args correctly set
//                  false if some args missing or invalid
bool GetArgs(int argc, char *argv[])
{
    int i=1;
    bool bOK = true;
    unsigned int ui_term_count = 0;

    while(i<=argc-1)
    {
        if (argv[i][0] != '-' && argv[i][0] != '/')
        {
            cerr << "Can't understand " << argv[i] << ". Have you missed a '-' or '/' ?" << endl;
            bOK = false;
            Usage();
            break;
        }
        switch(argv[i][1])
        {
            case 'u':
                Usage();
                bOK = false;
                break;
            case 'w':
                {
                    if (i+1 > argc-1)
                    {
                        cerr << "ERROR: Missing argument of -w.\n\n";
                        Usage();
                        return false;
                    }
                    string sWidth = argv[i+1];
                    fWidth = static_cast<float>(atof(sWidth.c_str()));
                    i++;
                    ui_term_count++;
                }
                break;
            case 'h':
                {
                    if (i+1 > argc-1)
                    {
                        cerr << "ERROR: Missing argument of -h.\n\n";
                        Usage();
                        return false;
                    }
                    string sHeight = argv[i+1];
                    fHeight = static_cast<float>(atof(sHeight.c_str()));
                    i++;
                    ui_term_count++;
                }
                break;
            case 'l':
                {
                    if (i+1 > argc-1)
                    {
                        cerr << "ERROR: Missing argument of -l.\n\n";
                        Usage();
                        return false;
                    }
                    string sLength = argv[i+1];
                    fLength = static_cast<float>(atof(sLength.c_str()));
                    i++;
                    ui_term_count++;
               }
               break;
            case 'c':
                {
                    if (i+1 > argc-1)
                    {
                        cerr << "ERROR: Missing argument of -c.\n\n";
                        Usage();
                        return false;
                    }
                    string sCoverage = argv[i+1];
                    fCoverage = static_cast<float>(atof(sCoverage.c_str()));
                    i++;
                    ui_term_count++;
                }
                break;
            default:
                cerr << "Can't understand " << argv[i] << endl;
                Usage();
                bOK = false;
                break;
        }
        i++;
    }
    if(ui_term_count != 4)
    {
        bOK = false;
    }
    return bOK;
}
