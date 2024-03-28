#pragma once
#include <iostream>
#include <string>
#include <vector>
class Students {
private:
	std::string _name;
	int _level;
public:
	Students() : _name(""), _level(0) { }
	Students(std::string name, int level) : _name(name), _level(level) { }
	Students(const Students& other) {
		_name = other._name;
		_level = other._level;
	}
	Students& operator=(const Students& other) {
		_name = other._name;
		_level = other._level;
		return *this;
	}

	std::string get_name() const {
		return _name;
	}
	int get_level() const {
		return _level;
	}


	bool operator==(const Students& other) const {
		return ((_name == other._name) && (_level == other._level));
	}
	bool operator<(const Students& other) const {
		return ((_name < other._name) || ((_name == other._name) && (_level < other._level)));
	}
	bool operator>(const Students& other) const {
		return ((_name > other._name) || ((_name == other._name) && (_level > other._level)));
	}
	bool operator<=(const Students& other) const {
		return ((_name <= other._name) || ((_name == other._name) && (_level <= other._level)));
	}
	bool operator>=(const Students& other) const {
		return ((_name >= other._name) || ((_name == other._name) && (_level >= other._level)));
	}


};

std::ostream& operator<<(std::ostream& os, const Students& man) {
	os << man.get_name() << ", " << man.get_level();
	return os;
}

std::ostream& operator<<(std::ostream& os, std::vector<Students>& list) {
	for (const Students& man : list) {
		os << man << std::endl;
	}
	os << std::endl;
	return os;
}