#include "files.hpp"

int	get_type(std::string str)
{
	int aux;

	aux = atoi(str.c_str());
	for (int i = 0;i < 7;i++)
	{
		if (aux == i)
			return (i);
	}

	return (ERROR);
}

product equalize_data(std::vector <std::string>seglist, int type)
{
	product pro;
	if (type)
		pro = product(seglist[0],seglist[1],get_type(seglist[2]));
	else
		pro = product("Corrupt Data","Corrupt Data",7);
	return (pro);
}

product *read_file(std::string dir,product *products)
{
	std::string line;
	std::ifstream oldfile(dir);
	int	i;
	
	i = 0;
	if (oldfile.is_open())
	{
		while ( getline (oldfile,line) )
    	{
			std::stringstream test(line);
			std::string segment;
			std::vector <std::string>seglist;

			while (std::getline(test,segment,':'))
				seglist.push_back(segment);
			
			if (seglist.size() == 3)
				products[i] = equalize_data(seglist, 1);
			else
				products[i] = equalize_data(seglist, 0);
			i++;
	   	}
		
    	oldfile.close();
  	}
	else
	{
		std::cout << "Unable to open file"<<std::endl;
		return (NULL);
	}
	return (products);
}

int	file_size(std::string dir)
{
	std::string line;
	std::ifstream oldfile(dir);
	int size;

	size = 0;
	if (oldfile.is_open())
	{
		while ( getline (oldfile,line) )
    	{
			size++;
	   	}
    	oldfile.close();
  	}
	else
	{
		std::cout << "Unable to open file"<<std::endl;
		return(-1);
	}
	return (size);
}