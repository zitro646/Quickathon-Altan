#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#define PAPER 	1
#define GLASS 	2
#define PLASTIC 3
#define ORGANIC 4
#define REST	5
#define SPECIAL 6
#define ERROR 	7

#define PAPER_STR 	"PAPER"
#define GLASS_STR 	"GLASS"
#define PLASTIC_STR "PLASTIC"
#define ORGANIC_STR "ORGANIC"
#define REST_STR	"REST"
#define SPECIAL_STR "SPECIAL"
#define ERROR_STR 	"ERROR"


#include <string>
#include <iostream>

class	product {

	private:
		std::string id;
		std::string data;
		int			type;

	public:

		product ( void );
		product ( std::string i , std::string dat , int ty);
		product ( const product & var );
		~product ( void );
		product &operator=(const product &tmp);

		// GETTERS

		std::string get_id(void) 	const{return(this->id);};
		std::string get_data(void) 	const{return(this->data);};
		int 		get_type(void) 	const{return(this->type);};
};

std::ostream &operator<<(std::ostream& os, const product &tmp);

int transform_input_type(std::string str);

#endif
