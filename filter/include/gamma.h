
#ifndef __GAMMA_H__
#define __GAMMA_H__

#include <vector>
#include "filter.h"
#include <cv.h>
#include <highgui.h>
using namespace std;

class Gamma : public Filter {
public:

    Gamma(const IplImage &src);

    vector< vector<CvPoint2D32f> > ctrlPointsList;

    // Virtual function implementation
    void filtering(const IplImage &src, IplImage* rst);
    void reset();
    void importSettings(string fileName, int suffix);
    void exportSettings(string fileName, int suffix);

    // Member function
    void setCtrlPoints(int ch, const vector<CvPoint2D32f> &ctrlPoints);
    void updateGammaTables(int ch);
    void setCtrlPointsList(const vector< vector<CvPoint2D32f> > &ctrlPointsList);

    ~Gamma();

private:

    const int ACCURACY;

    vector<int> gammaTableB;
    vector<int> gammaTableG;
    vector<int> gammaTableR;

    CvPoint2D32f pointAdd(CvPoint2D32f p, CvPoint2D32f q);
    CvPoint2D32f pointTimes(float c, CvPoint2D32f p);
    CvPoint2D32f Bernstein(float u, const CvPoint2D32f* p);

};

#endif

