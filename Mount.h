//making shit up
//NOTE DOES NOT COMPILE WITH MAKEFILE YET
#ifndef MOUNT_H
#define MOUNT_H

#include <string>

class mount{
	public:
		mount();
		mount(std::string name, std::string des,);
	
		std::string getName();
		std::string getDescription();
		bool canFly();
		void setName(std::string n);
		void setDescription(std::string d);
		void printMount();
	
	private:
		std:: string name,des;
		bool fly; //do we want flying mounts??????
		double speed; //how fast or far you can travel in a certain time
}
#endif