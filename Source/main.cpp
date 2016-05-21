#include <iostream>
#include <fstream>
#include "Libs/Utils/Include/Utils/Quaternion.h"
#include "Libs/Utils/Include/Utils/Vector3D.h"


using namespace std;
using namespace Luga::Meca::Utils;

int main()
{
	int x;

	Vector3D a;
	a.SetComponants(1,2,3);
	cout << a << endl;

	Quaternion b;
	b.SetComponants(1,1,1,1);
	cout << b << endl;

	cout << "Enter an integer value : ";
    cin >> x;


    // Test Thetrahèdre
    Vector3D s1(0,-5,3),s2(-1,6,5),s3(4,-5,-3),s4(1,2,-3);
    Vector3D e1,e2,e3,p;
    e1 = s2-s1;
    e2 = s3-s1;
    e3 = s4-s1;
    ofstream fichierOutS("/Users/ludewigfrancois/Desktop/tetraS.txt", ios::out | ios::trunc);
    fichierOutS << s1 << endl;
    fichierOutS << s2 << endl << endl;

    fichierOutS << s1 << endl;
    fichierOutS << s3 << endl << endl;

    fichierOutS << s1 << endl;
    fichierOutS << s4 << endl << endl;

    fichierOutS << s2 << endl;
    fichierOutS << s3 << endl << endl;

    fichierOutS << s2 << endl;
    fichierOutS << s4 << endl << endl;

    fichierOutS << s3 << endl;
    fichierOutS << s4 << endl << endl;
    fichierOutS.close();



    ofstream fichierOut("/Users/ludewigfrancois/Desktop/tetra.txt", ios::out | ios::trunc);
    if(fichierOut){
    	for(double x = -1 ; x <= 4 ; x+=0.1){
    		for(double y = -5 ; y <= 6 ; y += 0.1){
    			for(double z = -3 ; z <= 5 ; z += 0.1){
    				p.SetComponants(x,y,z);
    				if(0 < (p-s1)*e1 < e1.Norme() && 0 < (p-s1)*e2 < e2.Norme() && 0 < (p-s1)*e3 < e3.Norme()){
    					fichierOut << p << endl;
    				}
    			}
    		}
    	}
    	fichierOut.close();
    }
    cout << "End" << endl << endl;
    return 0;
}
