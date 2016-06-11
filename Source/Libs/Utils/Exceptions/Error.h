#pragma once

namespace Luga {
	namespace Meca {
		namespace Utils{

			class Error: public std::exception{
			public:
				Error(const int numero, const std::string & sentence, const int level) throw()
				: numero(numero), sentence(sentence), level(level){
				}

				virtual ~Error() throw(){}

				virtual const char * what() const throw(){
					return sentence.c_str();
				}

				int Numero() const throw(){
					return numero;
				}

				std::string Message() const throw(){
					return sentence;
				}

				int Level() const throw(){
					return level;
				}

			private:
				int numero;
				std::string sentence;
				int level;
			};

		}
	}
}
