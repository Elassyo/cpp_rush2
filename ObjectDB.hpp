/*
** EPITECH PROJECT, 2018
** CPP Pool Rush 2
** File description:
** ObjectDB class definition
*/

#if !defined (OBJECT_DB_HPP_)
	#define OBJECT_DB_HPP_

	#include <map>

class Object;

class ObjectDB {
public:
	~ObjectDB();

	void addClass(const Object *obj);
	Object *instantiate(const std::string className) const;

private:
	std::map<std::string, const Object *> _db;
};

#endif /* !defined (OBJECT_DB_HPP_) */
