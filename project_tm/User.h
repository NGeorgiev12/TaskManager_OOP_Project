#pragma once
#include "MyString.h"
#include "Task.h"

class User
{
public:
	const MyString& getUsername() const;
	const MyString& getPassword() const;


private:
	MyString username;
	MyString password;
};

