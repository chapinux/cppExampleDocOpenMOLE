#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;


double* model_computation(double param1, double param2, double output[]){
std::cout << "model computation with  parameters " << param1 << "and " << param2 << " \n" ;
  	output[0] = param1 * 10 ;
  	output[1] = param2 * 20  ;
  	return output ;
}


int main(int argc , char* argv[])
{
  std::cout << "main function call \n";

  std::istringstream iss1 (argv[1]) ;
  std::istringstream iss2 (argv[2]) ;
  double val1 ;
  double val2 ;
  double output[2];


  if (iss1 >> val1 && iss2 >> val2 ){
  
	double* result = model_computation(val1, val2, output) ;
	
  	std::cout << "log : compute first result "<< result[0] << '\n' ;
  	std::cout << "log : compute second result " <<  result[1]  << '\n' ;

	 ofstream myfile;
	 myfile.open ("results.txt");
	 myfile << result[0] << ','<< result[1]<< "\n";
  	 myfile.close();
	 return 0;
  }
  else{
  	std::cout << "Wrong arg : not an int " ;
  	return -1;
  }

}
