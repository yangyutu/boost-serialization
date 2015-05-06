#include <iostream>
#include <fstream>

// include input and output archivers
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

// include this header to serialize vectors
#include <boost/serialization/vector.hpp>

using namespace std;

class CoorPair
{
    friend class boost::serialization::access;
 
    // Serialize the std::vector member of Info
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
      ar & x;
      ar & y;    
    }

public:
	int x;
	int y;
	// we have to provide a default constructor
	CoorPair(){};
	CoorPair(int x0,int y0){x=x0;y=y0;}
};


class CoorPairHalf
{
    friend class boost::serialization::access;
 
    // Serialize the std::vector member of Info
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
      ar & x;    
    }

public:
	int x;
	int y;
	// we have to provide a default constructor
	CoorPairHalf(){};
	CoorPairHalf(int x0,int y0){x=x0;y=y0;}
};



int main()
{

  std::vector<double> v = {1,2,3.4, 5.6};

  // serialize vector
  {
    std::ofstream ofs("/tmp/copy.ser");
    boost::archive::text_oarchive oa(ofs);
    oa & v;
  }

   std::vector<double> v2;

   // load serialized vector into vector 2
   {
     std::ifstream ifs("/tmp/copy.ser");
     boost::archive::text_iarchive ia(ifs);
     ia & v2;
   }

   // printout v2 values
   for (auto &d: v2 ) {
      std::cout << d << endl;
   }


		std::vector<CoorPair> v3;
		  v3.push_back(CoorPair(1,1));
		  v3.push_back(CoorPair(2,2));
		  
		  {
		   std::ofstream ofs("/tmp/copyCoor.ser");
		   boost::archive::text_oarchive oa(ofs);
		   oa & v3;
		  }
  std::vector<CoorPair> v4;

		  {
		   std::ifstream ifs("/tmp/copyCoor.ser");
		   boost::archive::text_iarchive ia(ifs);
		   ia & v4;
		  }

		std::cout << v4.size() << std::endl;
		std::cout << v4[0].x << std::endl;
			 		std::cout << v4[0].y << std::endl;



		std::vector<CoorPairHalf> v5;
		  v5.push_back(CoorPairHalf(1,1));
		  v5.push_back(CoorPairHalf(2,2));
		  
		  {
		   std::ofstream ofs("/tmp/copyCoor2.ser");
		   boost::archive::text_oarchive oa(ofs);
		   oa & v5;
		  }
  std::vector<CoorPairHalf> v6;

		  {
		   std::ifstream ifs("/tmp/copyCoor2.ser");
		   boost::archive::text_iarchive ia(ifs);
		   ia & v6;
		  }

		std::cout << v6.size() << std::endl;
		std::cout << v6[0].x << std::endl;
			 		std::cout << v6[0].y << std::endl;

  return 0;
}
