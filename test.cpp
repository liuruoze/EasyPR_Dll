#include <iostream>
#include "include/plate_recognize.h"

using namespace easypr;

#pragma comment(lib,"lib/EasyPR_Dll.lib")

int main()
{
	cout << "test_plate_recognize" << endl;

	Mat src = imread("image/plate_recognize.jpg");

	CPlateRecognize pr;

	pr.LoadSVM("model/svm.xml");
	pr.LoadANN("model/ann.xml");

	vector<string> plateVec;

	int result = pr.plateRecognize(src, plateVec);
	if (result == 0)
	{
		int num = plateVec.size();
		for (int j = 0; j < num; j++)
		{
			cout << "plateRecognize: " << plateVec[j] << endl;			
		}
	}


	int a;
	cin>>a;
	return 0;
}