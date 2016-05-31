#include <iostream>
#include <fstream>
#include <Utils/Quaternion.h>
#include <Utils/Vector.h>


using namespace Luga::Meca::Utils;

int main()
{
	int x;

	Vector a;
	a.SetComponants(1,2,3);
	std::cout << a << std::endl;

	Quaternion b;
	b.SetComponants(1,1,1,1);
	std::cout << b << std::endl;

	std::cout << "Enter an integer value : ";
	std::cin >> x;


    // Test Thetrahèdre
    Vector s1(0,-5,3),s2(-1,6,5),s3(4,-5,-3),s4(1,2,-3);
    Vector e1,e2,e3,p;
    e1 = s2-s1;
    e2 = s3-s1;
    e3 = s4-s1;
    std::ofstream fichierOutS("/Users/ludewigfrancois/Desktop/tetraS.txt", std::ios::out | std::ios::trunc);
    fichierOutS << s1 << std::endl;
    fichierOutS << s2 << std::endl << std::endl;

    fichierOutS << s1 << std::endl;
    fichierOutS << s3 << std::endl << std::endl;

    fichierOutS << s1 << std::endl;
    fichierOutS << s4 << std::endl << std::endl;

    fichierOutS << s2 << std::endl;
    fichierOutS << s3 << std::endl << std::endl;

    fichierOutS << s2 << std::endl;
    fichierOutS << s4 << std::endl << std::endl;

    fichierOutS << s3 << std::endl;
    fichierOutS << s4 << std::endl << std::endl;
    fichierOutS.close();


    std::ofstream fichierOut("/Users/ludewigfrancois/Desktop/tetra.txt", std::ios::out | std::ios::trunc);
    if(fichierOut){
    	for(double x = -1 ; x <= 4 ; x+=0.1){
    		for(double y = -5 ; y <= 6 ; y += 0.1){
    			for(double z = -3 ; z <= 5 ; z += 0.1){
    				p.SetComponants(x,y,z);
    				if(0 < (p-s1)*e1 < e1.Norme() && 0 < (p-s1)*e2 < e2.Norme() && 0 < (p-s1)*e3 < e3.Norme()){
    					fichierOut << p << std::endl;
    				}
    			}
    		}
    	}
    	fichierOut.close();
    }
    std::cout << "End" << std::endl << std::endl;
    return 0;
}
