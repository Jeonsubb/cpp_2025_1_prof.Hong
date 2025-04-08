#include <iostream>


class Student {
private:
	char* name;
	int age;
	char* city;

public:
	Student(const char* name, int age,const char* city) {
		this->name = strdup(name);
		this->age = age;
		this->city = strdup(city);
	}

	Student(const Student& other) {
		name = strdup(other.name);
		age = other.age;
		city = strdup(other.city);
	}

	~Student() {
		free(name);
		free(city);
	}
	void show() {
		std::cout << "Name: " << name << ", Age: " << age << ", City: " << city << std::endl;
	}
};

int main() {/*
	Student sset2[5] = {
			{"John", 20, "New York"},
			{"Alice", 22, "Los Angeles"},
			{"Bob", 21, "Chicago"},
			{"Emily", 19, "San Francisco"},
			{"Michael", 23, "Seattle"} }
	};*/
	
	/*Student sset2[5] = {
		Student("John", 20, "New York"),
		Student("Alice", 22, "Los Angeles"),
		Student("Bob", 21, "Chicago"),
		Student("Emily", 19, "San Francisco"),
		Student("Michael", 23, "Seattle")
	};*/

	Student s1("John", 20, "New York");
	Student s2("Alice", 22, "Los Angeles");
	Student s3("Bob", 21, "Chicago");
	Student s4("Emily", 19, "San Francisco");
	Student s5("Michael", 23, "Seattle");

	Student sset2[5] = { s1, s2, s3, s4, s5 };
	
	
	for (int i = 0; i < 5; ++i)
		sset2[i].show();

}


복사 생성자 대입 연산자 함께 간다.
string을 쓰자,,,, 
char* 일때 더럽게 오류가 나는데 어떻게 해결할지 알아야 된다..
#include <iostream>
#include <string>

class Student {
	std::string name;
	int age;
	std::string city;

public:
	Student(const std::string& name, int age, const std::string& city)
		: name(name), age(age), city(city) {}

	void show() const {
		std::cout << "Name: " << name << ", Age: " << age << ", City: " << city << '\n';
	}
};

int main() {
	Student sset2[5] = {
		{"John", 20, "New York"},
		{"Alice", 22, "Los Angeles"},
		{"Bob", 21, "Chicago"},
		{"Emily", 19, "San Francisco"},
		{"Michael", 23, "Seattle"}
	};

	for (const auto& s : sset2)
		s.show();
}
